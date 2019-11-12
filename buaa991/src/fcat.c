/*************************************************************************
	> File Name: fcat.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 12 Nov 2019 11:10:20 PM CST
 ************************************************************************/
/**
 * 编写一个c语言程序fcat.c,将命令行中指定的多个文本文件连接成一个文本文件。eg：
 *		fcat file1 file2 file3
 *	其中fcat为命令名，file1，file2，file3为参数。该命令的功能是将文本文件file1 file2 file3连接成一个文本文件，文件名由第一个参数指定
 */
#include "stdio.h"
#include "stdlib.h"
int main(int argc,char **argv){
	int i;
	FILE *fp,*fp1;
	if(argc < 2){
		printf("error : argument count must >=2!\n");
		return 1;
	}
	if((fp = fopen(argv[1],"r+")) == NULL){
		printf("error : failed open %s \n",argv[1]);
		return 1;
	}
	fseek(fp,0,SEEK_END);
	for(i = 2;i<argc;i++){
		char c;
		if((fp1 = fopen(argv[i],"r")) == NULL){
			printf("error : failed open %s \n",argv[1]);
			return 1;
		}
		while((c = fgetc(fp1))!= EOF) fputc(c,fp);
		fclose(fp1);
	}

	fclose(fp);
	return 0;
}
