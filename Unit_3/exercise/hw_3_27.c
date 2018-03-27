/**
 * 3.27 已知Ackerman函数的定义如下：
 *		akm(m,n) = :
 *			n+1 , 当m = 0;
 *			akm(m-1,1)	当m!=0,n=0;
 *			akm(m-1,akm(m,n-1))	当m!=0,n!=0;
 *		
 * 	(1) 写出递归算法；
 *
 *	(2) 写出非递归算法；
 *
 * 	(3) 根据非递归算法，画出求akm(2,1)时栈的变化过程。
 * //注：Ackerman函数：阿克曼函数。
 */
typedef int ElemType;
#ifndef HW_3_27_C
#define HW_3_27_C
#include "../src/SqStack.c"


int answer1(int m,int n){	//用递归实现
	if(m == 0)	return n+1;
	if(m!=0 && n == 0)	return answer1(m-1,1);
	if(m!=0 && n!=0 )	return answer1(m-1,answer1(m,n-1));
}

int answer2(int m,int n){
	SqStack_L mval,nval;	//借用栈来实现非递归
	if(InitStack_Sq(&mval)&&InitStack_Sq(&nval)){
			
		*(mval -> top) = m;
		(mval -> top)++;
		*(nval -> top) = n;
		(nval -> top)++;

		do{
			while(*(mval -> top -1) != 0){
				while((*(nval -> top -1)) != 0){
					if((nval -> top - nval -> base) == nval -> capacity){      //扩容
						 nval -> base = realloc(nval -> base,((nval ->capacity)+STACKINCREMENT)*sizeof(ElemType));
						 nval -> top = nval -> base + nval -> capacity;
						 nval -> capacity +=STACKINCREMENT;
					}
					if((mval -> top - mval -> base) == mval -> capacity){      //扩容
						 mval -> base = realloc(mval -> base,((mval ->capacity)+STACKINCREMENT)*sizeof(ElemType));
						 mval -> top = mval -> base + mval -> capacity;
						 mval -> capacity +=STACKINCREMENT;
					}
	
					*(mval -> top) = *(mval -> top -1);
					(mval -> top)++;
					*(nval -> top) = (*(nval -> top-1))-1;
					(nval -> top)++;
				}
				(*(mval -> top -1))--;
				*(nval -> top - 1) = 1;
			}
			if((mval -> top) > (mval -> base)){
				(mval -> top)--;
				(nval -> top)--;
				(*(mval -> top -1))--;
				(*(nval -> top -1)) = (*(nval -> top))+1;
			}
		}while((mval -> top) > (mval -> base));
		return *(nval -> top)+1;
	}
}

int main(int argc,char **args){
	int m,n;
	printf("请输入m,n:\n");
	printf("m=");
	scanf("%d",&m);
	printf("n=");
	scanf("%d",&n);
	printf("akm(%d,%d)=%d",m,n,answer2(m,n));
}


#endif
