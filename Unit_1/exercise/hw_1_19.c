#include "stdio.h"
#include "stdlib.h"
#include "../src/myDefine.c"
#include "math.h"
/**
 * 1.19  试编写算法，计算i!*2i的值并存入数组a[0..arrsize-1]的第i-1个分量中(i=1,2,…,n)。
 *	 假设计算机中允许的整数最大值为maxint，则当n>arrsize或对某个k(1≤k≤n)使k!*2k>maxint时，应按出错处理。注意选择你认为较好的出错处理方法。
 */
#define arrsize 10
int myRecursion(int x);
int myExponential(int x,int y);
void myCalculate(int *a,int n,int maxint);
void main(){
	int i;
	int maxint = (int)pow(2,8*sizeof(int));
	int a[arrsize];
	myCalculate(a,10,maxint);
	for(i=0;i<10;i++) printf("%d  ",a[i]);
}
void myCalculate(int *a,int n,int maxint){
	int i,sum;
	if(n > arrsize) exit(OVERFLOW);
	for(i = 0;i<n;i++){
		sum = myRecursion(i)*myExponential(2,i);
		if( sum > maxint)
			exit(OVERFLOW);
		a[i] = sum;
	}
}

//计算递归
int myRecursion(int x){
	if(x < 0) exit(OVERFLOW);
	if(x == 0) return 1;
	return x*myRecursion(x-1);
}
//计算指数
int myExponential(int x,int y){	//x表示底数，y表示幂次(本题不涉及幂次小于0)
	if(y == 0) return 1;
	if(y > 0)
		return x*myExponential(x,y-1);
}
