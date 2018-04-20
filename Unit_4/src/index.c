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
 */

void get_next(int **next,HString S){		//0，1表示相同的最大前缀和最大后缀的长度为0，2表示最大长度为1，依次类推
	int i=1,j=0;	//i为next的下标,j为最大长度(next的值)。
	(*next) = (int *)malloc(sizeof(int)*(S->size+1));	//*next[0] 不使用
	(*next)[1] = 0;
	while(i <= S -> size){
		if(j == 0 || S->Base[i-1] == S -> Base[j-1]){
			i++;
			j++;
			(*next)[i] = j;
		}else{
			j = (*next)[j];		//缩小j的范围。
		}
	}
}

int Index_KMP(HString S,HString T,int pos){
	int i,j,*next;		//KMP的next数组	
	if(pos + T -> size > S -> size +1 ) return -1;
	get_next(&next,T);
	i = j = 1;
	while(i < S -> size && j < T -> size){
		if(j == 0 || S -> Base[i-1] == T -> Base[j-1]){
			i++;
			j++;
		}else{
			j = next[j];
		}
	}
	if(j >= T -> size) return i - T -> size+1;
	return -1;
}
#endif
