/*************************************************************************
	> File Name: checkScanf.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 25 Nov 2019 10:56:30 PM CST
 ************************************************************************/

#include "stdio.h"
#include "malloc.h"

main(){
	char *p,*q;
	p = (char *)malloc(sizeof(char)*20);
	q = p;
	scanf("%s%s",p,q);		//abc def 输入空格也会阻断scanf
	printf("%s%s\n",p,q);

}
