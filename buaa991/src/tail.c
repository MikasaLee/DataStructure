/*************************************************************************
	> File Name: tail.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sun 10 Nov 2019 06:52:55 PM CST
 ************************************************************************/
/**
 * 实现Unix系统中tail [-n] filename命令
 *	其中 tail为命令名；参数filename为文本文件名；[-n]是可选的，表示要打印最后几行，默认是10行
 *	要求：
 *		1. 用c语言实现该程序
 *		2. 该程序具有一定的错误能力，比如处理非法命令行参数和非法文件名
 */

#include "stdio.h"
#include "stdlib.h"
#define DEFAULT_LINE 10

int main(int argc,char **argv){

	char *filename,*temp,c,*str = malloc(sizeof(char)*100);
	int i,line = 0,offset;
	FILE *fp;
	
	if(argc < 2){
		printf("error: parm number must >= 2!\n");
		return 1;
	}
	filename = argv[1];			//初始化指向命令行第一个参数 有可能是-n 有可能是文件名

	if(filename[0] == '-'){
		temp = filename;			//filename只负责指向文件名
		filename = argv[2];
		for(i = 1; temp[i] != '\0';i++){			//得到行数
			if((temp[i] <'0') || (temp[i] >'9')){	//非法行数
				printf("error: line number error!\n");
				return 1;
			}
			line = line*10+temp[i]-'0';
		}
	}else line = DEFAULT_LINE;

	//处理文件
	if( (fp = fopen(filename,"r")) == NULL ){
		printf("error: file %s open error!\n",filename);
		return 1;
	}

	// 定位到倒数第n行的开头
	fseek(fp,0,SEEK_END);		//定位到文件最后,fseek函数改变的并不是fp的指针，而是FILE结构体中的一个属性：文件偏移量（简单的说就是文件光标） fseek和ftell的定位都是依靠该属性实现的，而fp的指向始终不变
	offset = ftell(fp);

	while(offset > 0 && line >= 0){	//定位到倒数第n行开头或者n比文件总行数大时定位到文件头,注意这里line是大于等于0 因为定位到文件最后是文件的最后一样最后一个字符，也就是该行的换行符，所以要先把这个换行符减掉 所以line多循环一次
		//if(fgetc(fp) == '\n') --line;		//找见一个换行符line减一
		fseek(fp,--offset,SEEK_SET);	//光标往前移一个字节
		if((c = fgetc(fp)) == '\n')
			--line;		//找见一个换行符line减一
	}
	while((c = fgetc(fp) != EOF)) printf("%c",c);		//输出后n行,这个不行？？？？
	//while(fgets(str,sizeof(str),fp)) printf("%s",str);		//输出后n行，这个可以？？？

	fclose(fp);
	return 0;
}

