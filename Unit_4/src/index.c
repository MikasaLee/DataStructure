/**
 * 4.3 串的模式匹配算法
 * 	求子串的定位函数Index(HString S,HString T,int pos)
 */

/**
 * 方法一：myHString.c中定义的Index函数，借助其他函数实现。
 *	   思路为从S的pos位置开始，每次截取T->size个字符，与T进行比较，相等返回T，不等从下一位位置开始截取T->size个字符。 
 *
 *	   SubString函数的时间复杂度为O(T -> size)，StrCompare的时间复杂度也为O(T -> size).所以Index函数的时间复杂度为O(S->size*2(T -> size)) //不考虑pos和ensureCapacity函数。
 */	   
/**
 * 方法二：不借助任何myHString.c文件定义的其他函数实现匹配算法
 * 	   思路为从S的pos位置开始，比较T的第一个字符，若相等继续比较S的下一个字符和T的下一个字符，若不想等将S的游标回退，T的游标重置
 * 	   时间复杂度为O(S -> size * T -> size) //最坏情况
 *		
 *	   缺点：当主串中存在多个和模式串“部分匹配”的子串时，会引起S的游标多次回溯，比如在000000000000000000000000000000001中匹配0000001的情况。时间复杂度也就越趋近与S -> size * T -> szie。
 *	   	 当然即使是最坏情况，其速度也远远快于方法一。
 */
#ifndef INDEX_C
#define INDEX_C
#include "myHString.c"

int Index(HString S,HString T,int pos){
	int i,j;	//i为S的游标，j为T的游标
	if(!S||!T) exit(OVERFLOW);
	if((pos + T -> size) > S -> size+1) return -1;
	i = pos-1,j=0;
	while(i < S -> size && j <T -> size){
		if(S->Base[i] == T -> Base[j]){	//继续比较后续字符
			i++;
			j++;
		}else{				//指针后退重新开始比较
			i=i-j+1;
			j=0;
		}
	}
	if(j >= T -> size) return i - T -> size+1;
	return -1;
}
/**
 * 方法三：克努特-莫里斯-普拉特算法(又叫KMP算法)，可在O(m+n)的数量级上完成对串的模式匹配操作。其最大特点在于：在每一趟匹配过程中出现不想等的情况，不需要回溯i指针
 * 	 
 * 	 ***很多的文本模式处理都使用KMP算法。重点掌握，理解
 * 	 重难点在next数组的求法。
 */
void get_next(int **next,HString S){		//next数组：其值为S的每一位所拥有相同的最大子串长度。子串的范围为0到该位的长度-1，0表示没有相同的子串，1表示最大子串为1。。依次类推；下标0没有子串，设置为特殊位-1
	int i,j;
	(*next) = (int *)malloc(sizeof(int)*S->size);
	(*next)[0] = -1;
	i = 0;	//i表示两个含义：S的游标和next的游标
	j = -1;	//j表示next[i]的值
	while(i < S -> size){
		if(j == -1 || S -> Base[i] == S -> Base[j]){
			++i;
			++j;
			(*next)[i] = j;
		}else{
			//j--;	//j--是否也可以?  2018-4-21：从实验结果来说没问题，可是从理解上来说就不对了。
			j = (*next)[j];
		}
	}
}

void get_nextval(int **next,HString T);
int Index_KMP(HString S,HString T,int pos){
	int i,j,*next;		//KMP的next数组	
	if(pos + T -> size > S -> size +1 ) return -1;
	//get_next(&next,T);
	get_nextval(&next,T);		//改进的KMP的next数组
	i = j = 0;
	while(i < S -> size && j < T -> size){
		if(j == -1 || S -> Base[i] == T -> Base[j]){
			i++;
			j++;
		}else{
			j = next[j];
		}
	}
	if(j >= T -> size) return i - T -> size+1;
	return -1;
}
/**
 * 最后，关于KMP算法，需要说明两点：
 ******************************************************************************************************
 * 	1. 虽然方法二的时间复杂度为O(n*m)，但在一般情况下，其执行的时间近似与O(n+m),因此至今仍被采用。
 * 	   KMP算法仅当模式与主串之间存在许多”部分匹配”的情况下才显得比方法二快的多。但是KMP算法最大的
 * 	   特点在于主串的游标不需要回溯，整个匹配过程中，对主串仅需要从头到尾扫描一遍，这对处理从外设
 * 	   输入的庞大文件很有效，可以边读入边匹配，而无需从头再读
 ******************************************************************************************************
 *      2. get_next函数中得到next数组在某些情况下尚有缺陷。例如模式“a a a a b”在和主串“a a a b a a a 
 *         a b”匹配时，当i=4(值为b),j=4(值为a)时，S -> Base[4] != T -> Base[4]，由于next的指示还需要进
 *         行i=4(值为b),j=3(值为a);i=4(值为b),j=2(值为a);i=4(值为b),j=1(值为a)这三次比较。但实际上因为
 *         模式中第1,2,3个字符和第4个字符都相等，因此不需要再和主串中第4个字符想比较，而可以直接将模式
 *         一口气向右滑动4个字符，i后移一个字符进行i=5(a),j=1(a)时的比较。
 *	   
 *	   这就是说,如果按照上述定义得到的next[j]=k,而模式中P(j)=P(k),则当主串中字符S(i)!=P(j)时，不需
 *	   要再和P(k)比较，而直接和P(next[k])进行比较，换句话说，此时的next[j]应该和next[k]相同。由此可
 *	   得计算next函数修正值的算法get_nextval函数，此时匹配算法不变。
 ******************************************************************************************************
 */
void get_nextval(int **next,HString T){
	int i,j;
	(*next) = (int *)malloc(sizeof(int)*T -> size);
	(*next)[0] = -1;
	i = 0;
	j = -1;
	while(i < T -> size){
		if(j == -1 || T -> Base[i] == T -> Base[j]){
			++i;
			++j;
			if(T -> Base[i] != T -> Base[j]) (*next)[i] = j;
			else (*next)[i] = (*next)[j];
		}else j = (*next)[j];
	}
}

#endif
