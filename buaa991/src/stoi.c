/*************************************************************************
	> File Name: stoi.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Thu 05 Dec 2019 10:57:36 PM CST
 ************************************************************************/

/**
 * 请编写一C语言程序，该程序首先读取用户通过键盘输入的一个字符串（该字符串由数字字符和非数字字符组成），然后将其中连续的数字字符作为一个整数提取出来，保存到相应的整数数组中，最后将这些整数按照从大到小的顺序依次输出。例如：若用户输入的字符串为"abc123de45f*#6?*789&"则应该分别提取出123 45 6 和789四个整数，然后按照789 123 45 6 的顺序依次输出它们（说明：不考虑负整数的情况，负号-作为非数字字符处理）
 * 要求：
 *	1. 将数字字符串转成整数时不得使用C语言提供的库函数，需编写函数stoi来实现
 *	2. 把整数数组从大到小的顺序输出功能也封装成一个单独的函数output中，不能直接写在main函数中
 */
#include "stdio.h"
#define MAX 50

typedef struct{
	int counts[MAX];
	int length;
}array;

array stoi(char *str){
	char *p,*q;
	int number,sum;
	array arr;
	arr.length = 0;

	p = str;
	while(*p != '\0'){
		if(*p >='0' && *p <= '9'){
			sum = number = 0;
			for(q = p;*q >= '0' && *q <='9';++q){
				number = *q -'0';
				sum = sum*10+number;
			}
			arr.counts[arr.length++] = sum;
			p = q;
		}else ++p;
	}
	return arr;
}

void output(int counts[],int length){
	
	int i,j,max,temp;
	for(i = 0;i<length;i++){
		max = i;
		for(j = i+1;j<length;j++){
			if(counts[max] < counts[j]) max = j;
		}
		temp = counts[max];
		counts[max] = counts[i];
		counts[i] = temp;
	}
	printf("从大到小依次为：\n");
	for(i = 0; i<length;i++) printf("%d ",counts[i]);
}

int main(int argc,char **argv){
	char s[MAX];
	array arr;
	printf("请输入字符串：\n");
	scanf("%s",s);
	arr = stoi(s);
	output(arr.counts,arr.length);

	return 0;
}
