/*************************************************************************
	> File Name: change.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 11 Nov 2019 11:40:14 PM CST
 ************************************************************************/

/**
 * 假设某操作系统有一条命令，该命令的功能是将指定文本文件中的所有小写字母换成大写字母，其他字符格式保持不变，格式为：
 *			change filename
 *	其中change为命令名，参数filename为文件名
 *	请实现该命令程序。要求进行命令行的正确性检查
 */

#include "stdio.h"
#include "stdlib.h"

int main(int argc,char **argv){

	FILE *fp;
	char c;
	if(argc != 2){
		printf("error: argument count must be 2!\n");
		return 1;
	}
	if((fp = fopen(argv[1],"r+")) != NULL){
		fseek(fp,0,SEEK_SET);
		while((c = fgetc(fp)) != EOF){
			if((c >='a') && (c<='z')){
				c = c -'a'+'A';	// c = c -32也行;但是这样写更直白更稳
				fseek(fp,-1,SEEK_CUR);	//定位回刚才的小写字母
				fputc(c,fp);
			}
		}
		fclose(fp);
	}else{
		printf("error: fopen failed!\n");
		return 1;
	}
	
	return 0;
}
