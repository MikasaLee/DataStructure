/*************************************************************************
	> File Name: psum.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Thu 05 Dec 2019 10:17:56 PM CST
 ************************************************************************/

/**
 * 请编写一C语言函数psum，该函数的功能是首先接收两个整数类型的参数a和n，然后计算1的a次方+2的a次方+3的a次方+...+n的a次方 的结果。需要注意的是，当a或者n小于等于0时，该函数返回0。
 * 提示：可以先编写一个求解n的a次方的辅助函数，再在psum函数中计算累加和
 */

#include "stdio.h"

int Index(int a,int n){			//求解a的n次方
	int i,sum = n;
	for(i = 1;i<a;i++) sum *=n ;
	return sum;
}

int psum(int a,int n){
	int sum = 0,i;
	if(a <= 0 || n <= 0) return 0;
	
	for(i = 1;i<=n;i++) sum +=Index(a,i);

	return sum;
}

int main(int argc,char **argv){
	
	printf("1的4次方加到3的4次方:%d\n",psum(4,3));
	return 0;
}
