/*************************************************************************
	> File Name: sum.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Thu 14 Nov 2019 11:47:28 PM CST
 ************************************************************************/

/**
 * 请编写程序,该程序首先通过键盘输入获得整型数据a与n，然后计算sum = a+aa+aaa+....(共n项)
 * 最后输出计算结果。例如：当a=5,n=4时，计算sum=5+55+555+5555
 */

#include "stdio.h"

int main(int argc,char **argv){
	int a,sum=0,n,k;
	printf("a=");
	scanf("%d",&a);
	printf("n=");
	scanf("%d",&n);
	while(n-->0){
		k = k*10+a;
		sum +=k;
	}
	printf("sum=%d\n",sum);
	return 0;
}
