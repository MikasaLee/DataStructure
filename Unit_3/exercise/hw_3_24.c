/**
 * 3.24 试编写如下定义的递归函数的递归算法，并根据算法画出求g(5,2)时栈的变化过程。
 * 	当 m = 0, n >= 0	: g(m,n) = 0
 * 	当 m > 0, n >= 0	: g(m,n) = g(m-1,2n)+n
 */

#include "stdio.h"
#include "stdlib.h"
int hw_3_24(int m,int n){
	if(m == 0)	return 0;
	return hw_3_24(m-1,2*n)+n;
}

int main(int argc,char **args){
	printf("g(5,2)的结果是：%d\n",hw_3_24(5,2));
}
