/*************************************************************************
	> File Name: inputAndMax.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 03 Dec 2019 10:35:28 PM CST
 ************************************************************************/

/**
 * 请编写一程序，该程序的功能是首先将用户通过键盘输入的若干字符（用EOF结束输入）存入一维数组s中，然后找出数组中具有最大ASCII码值的字符，并且输出该字符以及对应的ASCII码
 */
#include "stdio.h"

#define MAX 50
int main(int argc,char **argv){

	char s[MAX],*p,*max;
	for(p = s;scanf("%c",p)!=EOF;p++);
	for(max = p = s;*p!='\0';p++) if(*max < *p) max = p; 

	printf("最大字符：%c,对应的ASCII码：%d\n",*max,*max);

	return 0;
}
