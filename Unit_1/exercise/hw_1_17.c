#include "stdio.h"
#include "../src/myDefine.c"
#include "stdlib.h"

/**
 * 习题1.17
 * 已知k阶斐波那契序列的定义为
 *
 * 	f0=0, f1=0, …, fk-2=0, fk-1=1;
 *
 *	 fn=fn-1+fn-2+…+fn-k, n=k,k+1,…
 *
 * 试编写求k阶斐波那契序列的第m项值的函数算法，k和m均以值调用的形式在函数参数表中出现。
 */
int myFibonacci(int k,int m);

void main(){
	int k,m;
	k = 3;
	for(m =1;m<10;m++)
		printf("求的%d阶斐波那契数列第%d项的值为：%d\n",k,m,myFibonacci(k,m));
}
int myFibonacci(int k,int m){
	if(k<2 || m <0) exit(OVERFLOW);
	int sum = 0,i;
	if(m < k-1) return 0;
	if(m == k-1)	return 1;
	for(i = 1;i <= k;i++)	sum += myFibonacci(k,m-i);
	return sum;
}
