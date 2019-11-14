/*************************************************************************
	> File Name: outprime.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Thu 14 Nov 2019 11:29:53 PM CST
 ************************************************************************/

/**
 * 使用命令行参数形式编写c语言程序以实现从2开始连续输出n个素数。
 * 设命令行格式为：
 *			outprime.c
 *		例如：执行命令
 *			outprime 10
 *		的结果是：2 3 5 7 11 13 17 19 23 29
 */

#include "stdio.h"
#include "stdlib.h"

int isSuShu(int);
int main(int argc,char **argv){
	int n,i;
	if(argc != 2){
		printf("error:argument number must be 2！\n");
		return 1;
	}
	n = atoi(argv[1]);

	i = 2;
	while(n > 0){
		if(isSuShu(i++)) --n;
	}
	return 0;
}
int isSuShu(int i){
	int j;
	for(j = 2 ;j<=i/2;j++)
		if(i%j == 0) return 0;
	printf("%d ",i);
	return 1;
}
