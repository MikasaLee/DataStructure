/**
 * 3.26 求解平方根√A的迭代函数定义如下： 
 *	sqrt(A,p,e) = 
 *		当 |p2 - A| < e , p
 *		当 |p2 - A| >=e , sqrt(A,(p+A/p)*1/2,e);
 * 其中，p是A的近似平方根，e是结果允许误差。试写出相应的递归算法，并消除递归.
 */
#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"
#define e 0.01		//允许误差为0.01

float Sqrt(int A,float p){
	if(A <= 0)	exit(OVERFLOW);
	if( (p*p - A < e) && (p*p - A >-e)) return p;
	else return Sqrt(A,(p+A/p)/2);
}

int main(int argc,char **args){
	int i;
	i = 10;
	printf("%d的平方根为%.2f\n",i,Sqrt(i,1));	
}
