/*************************************************************************
	> File Name: subStrCpy.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Fri 15 Nov 2019 10:24:18 PM CST
 ************************************************************************/

/**
 * 请编写一程序，将一字符串的第k个字符开始的全部字符复制成另一个字符串
 * 要求：1.将复制过程单独编写一个函数，并且采用指针完成
 *		 2.在主函数中输入字符串和k的值，并且在主函数中输出复制结果
 */

#include "stdio.h"
#include "stdlib.h"
#define MAX 80

char *getSub(char *s,int k){
	char *p,*t;
	if(p = (char *)malloc(sizeof(char)*MAX)){
		t = p;						//t为p的游标
		s+=k-1;
		while(*t++=*s++);			
	}
	return p;
}

int main(int argc,char **argv){

	char *s;
	int k;
	if(s = (char *)malloc(sizeof(char)*MAX)){
		printf("请输入字符串s:");
		scanf("%s",s);
		printf("请输入k:");
		scanf("%d",&k);

		printf("子串为:%s\n",getSub(s,k));
	}
	return 0;
}
