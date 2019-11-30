/*************************************************************************
	> File Name: findWord.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sat 30 Nov 2019 03:03:23 PM CST
 ************************************************************************/

/**
 * 请编写一c语言函数 char *maxword(char *s,char *t),该函数的功能是求出字符串s与字符串t的最长公共单词（这里，假设两个字符串均由英文字母和空格字符组成）；若找到这样的公共单词，函数返回该单词，否则，返回NULL
 * 例如：s = "This is C programming text" t = "This is a text for C programming"，则函数返回:programming
 * 要求：1. 函数中不得设置保存单词的存储空间
 *       2. 给出函数之前请用文件简要叙述函数的基本思想
 */

#include "stdio.h"
#include "stdlib.h"

char *maxword(char *s,char *t){			//此函数没有任何问题！关键在于如何调用
	char *s1 = s,*t1,*maxword = NULL;
	int i,maxlength = 0;
	while(*s != '\0'){
		for(;*s == ' ';) s++;					//跳过空格
		for(s1 = s;*s1 != ' ' && *s1 != '\0' ;++s1);		//从s中切割出单词

		if(s1 - s > maxlength){
			//在t中找是否有s-s1这个单词
			while(*t != '\0'){
				for(;*t == ' ';) t++;			//跳过空格
				for(t1 = t;*t1 != ' ' && *t1 != '\0' ;++t1);		//从t中切割出单词
				if((t1 - t) == (s1 - s)){
					for(i = 0;i < t1-t;i++) 
						if(t[i] != s[i]) break;
					if(i == t1-t) break;		//有这个单词
				}
				t = t1;
			}
			if(*t != '\0'){			//t中有此单词
				maxword = s;
				maxlength = s1 - s;
			}
		}
		s = s1;
	}
	if(maxword != NULL) maxword[maxlength] = '\0';
	return maxword;
}

int main(int argc,char **argv){
	
	//char *s = "This is C programming text",*t = "This is a text for C programming";
	/**
	 * 如果按照上述的声明，s和t都指向字符串常量，这就意味着不能对这两个字符串常量进行任何修改，而当我们找到最大单词maxword需要分割出此单词，也就是说需要在该单词最后加一个'\0'但这样就是在原字符串常量上进行修改了，故报错
	 */
	char *s = malloc(sizeof(char)*100),*s1,
		 *t = "This is a text for C programming",*temp="This is C programming text";
	s1 =s;
	while(*s1++ = *temp++);
	printf("最长公共单词：%s\n",maxword(s,t));
	
	return 0;
}
