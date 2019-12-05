/*************************************************************************
	> File Name: strcmp_nc.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Thu 05 Dec 2019 12:37:22 PM CST
 ************************************************************************/

/**
 * 字符串处理函数strcmp(s1,s2)可以比较两个字符串的大小，其字符的大小是以ASCII码表上的顺序决定的，该函数首先将S1第一个字符减去S2的第一个字符，若差值为0则继续比较下一个字符，若不为0则该差值就是函数的最终结果
 * 请参照该函数的实现原理，写出一个新的字符串比较函数strcmp_nc(s1,s2)，该函数的功能与strCmp类似，但不区分字符串中的大小写字母，例如：字符a和字符A相等
 * 要求：实现过程中不得使用任何已有的关于字符和字符串处理的库函数
 */
#include "stdio.h"
#include "string.h"
int strcmp_nc(char *s1,char *s2){
	for(;*s1 == *s2 || *s1 - *s2 == 32 || *s1 - *s2 == -32;++s1,++s2)
		if(*s1 == '\0') return 0;
	return *s1 - *s2;
}

int main(int argc,char **argv){

	char s1[80],s2[80];
	puts("请输入s1:");
	scanf("%s",s1);
	puts("请输入s2:");
	scanf("%s",s2);
	printf("strcmp_nc：%d\n",strcmp_nc(s1,s2));
	printf("strcmp：%d\n",strcmp(s1,s2));
	return 0;
}
