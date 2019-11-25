/*************************************************************************
	> File Name: deleteChar.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 25 Nov 2019 11:02:13 PM CST
 ************************************************************************/
/**
 * 请编写一C程序，该程序的功能是确定字符串中首次出现的某字符在串中的位置（即该字符是字符串中的第几个字符），然后从字符串中删除该字符。要求：
 * 1. 如果未能找到该字符，程序给出相应信息，否则，输出该字符在字符串中出现的首次位置，删除该字符（注：不考虑非首次出现的该字符的删除），并且显示删除前后的字符串
 * 2. 通过键盘输入字符串以及被确定的字符
 */

#include "stdio.h"
#include "stdlib.h"
#define MAX 50
void delete(char a[],char k){
	int i;
	for(i = 0;a[i]!='\0';i++)
		if(a[i] == k) break;
	
	if(a[i] == '\0'){	//未找到
		printf("该字符串不存在此字符！\n");
	}else{
		printf("该字符出现的位置：%d\n",i+1);
		for(;a[i]!='\0';i++){
			a[i] = a[i+1];
		}
	}
}
int main(int argc,char **argv){

	char a[MAX],k;
	printf("请输入字符串：\n");
	scanf("%s",a);
	printf("请输出要删除的字符：\n");
	scanf(" %c",&k);			//WARNNING：scanf中%s后跟%c不能正确读出，是因为%s碰到空格或者\n结束但不会读取空格和\n，也就是这两个依旧在缓存区中，所以%c会读入这两个字符，就会报错 通过%c前加一个空格或者getchar()或者gets()来消除这个结束符


	printf("删除前字符串：%s\n",a);
	delete(a,k);
	printf("删除后字符串：%s\n",a);
	return 0;
}
