/*************************************************************************
	> File Name: fun.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sun 24 Nov 2019 09:56:40 PM CST
 ************************************************************************/

/**
 * 请编写一C程序，该程序的功能是先通过键盘输入一个整数n，然后调用一个递归fun(int n)计算1+2+3+...+n，最后输出计算结果
 */

#include "stdio.h"

int fun(int n){
	if(n == 1) return 1;
	return fun(n-1)+n;
}

int main(int argc,char **argv){
	int n;
	printf("请输入n:");
	scanf("%d",&n);
	printf("\nfun(%d):%d",n,fun(n));
}
