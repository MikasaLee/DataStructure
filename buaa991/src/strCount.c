/*************************************************************************
	> File Name: strCount.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 02 Dec 2019 11:09:46 PM CST
 ************************************************************************/

/**
 * 请编写一程序，该程序的功能是计算并输出某子串substr在主串str中出现的次数。
 * 要求：
 *		(1) 把求子串在主串中出现次数的过程编写一个独立的函数：
 *			int StrCount(char *str,char *substr)
 *		(2) 若主串str中未出现子串substr，则函数返回0
 *		(3) 在主函数中通过键盘输入方式分别给str和substr赋值，并且所有涉及到字符串的操作均通过指针完成
 */
#include "stdio.h"

int strCount(char *str,char *substr){
	int count = 0;
	char *p,*q;
	while(*str){
		for(p = str,q = substr; *p && *q && (*p == *q);p++,q++);	//判断是否为子串
		if(*q == '\0') ++count;					//是子串
		++str;
	}
	return count;
}

int main(int argc,char **argv){

	char *str = "aaaabaaaaa",*substr="aa";
	printf("子串出现的次数:%d\n",strCount(str,substr));
	return 0;
}
