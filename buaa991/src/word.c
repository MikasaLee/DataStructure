/*************************************************************************
	> File Name: word.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sat 07 Dec 2019 09:19:47 PM CST
 ************************************************************************/

/**
 * 所谓变位词是指把某个单词的字母的位置(顺序)加以改换所形成的一个新词。例如：silent就是listen的一个变位词，integral也是triangle的一个变位词
 * 请编写一C程序，用来求解某个单词在一篇文章中的变位词。用户通过键盘输入一个单词和一个文本文件的名称，程序按照升序输出在这个文本文件中出现的该单词的所有变位词（同一个变位词多次出现时，只输出一次）；如果没有变位词，则程序输出NONE
 * 说明：
 *	1. 为了简化问题，假设所有涉及的单词长度均不超过20个字母，文本文件中出现的都是普通单词，他们通过空格符，制表符或者回车符进行分割，没有数字，标点符号等其他特殊符号，且单词个数不超过100个
 *	2. 变位词不区分大小写，即Silent也是lisent的变位词。相同的单词不是变位词，如Silent不是Silent的变位词。为了简化问题，可以考虑把所有输入的单词都转化为小写，排序输出时也不再考虑大小写的问题，全部以小写形式输出
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX 20
/**
 * 确定变位词：
 *	1 两个单词长度一样 
 *	2 temp中的每个字母都在word中存在
 *	3 temp 和 word 的所有字母ASCII码之和相等
 */
typedef struct bianwei{
	char word[MAX];
	struct bianwei * next;
}bianwei,*Bianwei;

int main(int argc,char **argv){
	char word[MAX],filename[MAX],temp[MAX],ch;
	int i,ascii,length,tempAsc,j;
	FILE *fp;
	Bianwei headAns,p,q;

	printf("请输入单词:\n");
	scanf("%s",word);
	printf("请输入文本文件名:\n");
	scanf("%s",filename);

	if((fp = fopen(filename,"r")) == NULL){
		printf("error:file open failed!\n");
		exit(1);
	}
	
	//头结点
	headAns = (Bianwei)malloc(sizeof(bianwei));
	if(headAns == NULL) exit(1);
	headAns -> next = NULL;
	p = headAns;

	//word的ASCII之和和单词长度
	ascii = 0;
	length = 0;
	for(i = 0;word[i]!='\0';i++){
		if((word[i] >='A') && (word[i] <='Z'))
			word[i] = word[i] - 'A' + 'a';
		ascii += word[i];
	}
	length = i;

	while(1){
		//取一个单词
		for(i = 0,tempAsc = 0;((ch = fgetc(fp)) >= 'a' && (ch <= 'z')) ||
					((ch >= 'A') && (ch <='Z'));tempAsc+=temp[i++])
			if((ch >='A' ) && (ch <='Z'))
				temp[i] = ch - 'A' + 'a';
			else temp[i] = ch;
		temp[i] = '\0';
		if(i == 0 && ch != EOF) continue;
		if((i == length) && (tempAsc == ascii)){
			for(i = 0;temp[i] !='\0';++i){
				for(j = 0;word[j] != '\0';++j)
					if( temp[i] == word[j]) break;
				if(word[j] == '\0')	break;		//第i个字符在word中没有
			}
			if(temp [i] == '\0'){			//变位词
				//判断是否和word一样
				if(strcmp(word,temp) != 0){	//和word不一样，判断是否有相同单词加入变位词中
					if(headAns -> next == NULL){
						q = (Bianwei)malloc(sizeof(bianwei));
						strcpy(q -> word,temp);
						q -> next = headAns -> next;
						headAns -> next = q;
						
					}else{
						p = headAns -> next;
						while(p){
							
							if(strcmp(p -> word,temp) == 0) break;
							else if(strcmp(p -> word,temp)<0){
								if(p -> next){
									if(strcmp(p -> next -> word,temp)>0){
										q = (Bianwei)malloc(sizeof(bianwei));
										strcpy(q -> word,temp);
										q -> next = p -> next;
										p -> next = q;
										break;
									}
	
								}else{
									q = (Bianwei)malloc(sizeof(bianwei));
									strcpy(q -> word,temp);
									q -> next = p -> next;
									p -> next = q;
									break;
								}
							}
							p = p -> next;
						}
					}
				}
			}
		}
		if(ch == EOF) break;
	}

	if(headAns -> next == NULL) printf("NONE\n");
	else
		for(p = headAns -> next;p;p = p -> next)
			printf("%s ",p -> word);

	fclose(fp);
	return 0;
}

