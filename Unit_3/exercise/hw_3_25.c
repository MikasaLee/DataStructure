/**
 * 3.25 试写出求递归函数F(n)的递归算法，并消除递归：
 * 	当 n = 0	:F(n) = n+1;
 * 	当 n > 0	:F(n) = n*F(n/2)
 */
#include "stdio.h"
#include "stdlib.h"
//递归方法
float hw_3_25(int n){
	if(n == 0)	return n+1;
	return n*hw_3_25(n/2);
}
//消除递归的意思就是使用迭代
float diedai(int n){
	float a[n+1];
	int i=1;
	for(a[0] =1;i<=n;i++){
		a[i] = i*a[i/2];
	}
	return a[n];
}
int main(int argc,char **args){
	printf("n = 4时，result=%.2f\n",hw_3_25(4));
	printf("n = 4时，result=%.2f\n",diedai(4));
}
