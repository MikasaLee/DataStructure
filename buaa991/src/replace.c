/*************************************************************************
	> File Name: replace.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Fri 15 Nov 2019 10:38:07 PM CST
 ************************************************************************/

/**
 * 使用命令行参数形式编写程序，该程序将指定文本文件中所有某个单词的出现均替换成另一个单词，
 * 经过替换后的文件信息存放于另一个文本文件中。
 *		设命令行格式为：
 *				replace oldfile newfile oldword newword
 *	其中，replace为命令名，oldfile,newfile,oldword和newword为命令行参数
 *	例如，执行命令：
 *				replace file1 file2 old new
 *	的结果是将文本文件file1中的所有单词"old"替换成"new"，替换后的文件信息存放与文本文件file2中
 *	要求：程序中必须有命令行的正确性检查
 */

#include "stdio.h"
#include "stdlib.h"

int main(int argc,char **argv){
	
	FILE *fp1,*fp2;
	char *old,*new,c;
	int i = 0;


	if(argc != 5){
		printf("error:argument account must be 5!\n");
		return 1;
	}
	if( (fp1 = fopen(argv[1],"r"))
			&& (fp2 = fopen(argv[2],"w"))){
		old = argv[3];
		new = argv[4];

		while((c = fgetc(fp1)) != EOF){
			fputc(c,fp2);
			if(c == old[i]){
				++i;
				if(old[i] == '\0'){
					fseek(fp2,-i,SEEK_CUR);
					fputs(new,fp2);
					i = 0;
				}
			}else if(c == old[0]) i = 1;
			else i = 0;
		}
	}

	fclose(fp2);
	fclose(fp1);
	return 0;
}
