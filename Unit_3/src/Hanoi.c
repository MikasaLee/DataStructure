/**
 * 汉诺塔问题
 */
#include "stdio.h"
#ifndef HANOI_C
#define HANOI_C

void move(char begin,char end);
void hanoi(int n,char a,char b,char c){		//将层数为n的汉诺塔从a借助b都移到c
	if(n == 1)	move(a,c);
	else{
		hanoi(n-1,a,c,b);		//先将前n-1块由a借助c移到b
		move(a,c);			//将第n块由a移到c
		hanoi(n-1,b,a,c);		//再将前n-1块由b借助a移到c
	}
}
void move(char begin,char end){
	printf("%c --> %c\n",begin,end);
}
#endif
