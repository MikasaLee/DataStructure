/*************************************************************************
	> File Name: fastq.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sat 07 Dec 2019 08:12:48 PM CST
 ************************************************************************/

/**
 * FASTQ文件是一种存储生物序列（通常称为核酸序列）以及相应质量评价的文本格式文件。整个文件包含多条生物序列，每条生物序列由四行信息组成：
 *	第一行为序列标识,以'@'开头；
 *	第二行是具体的生物序列（即由ATGC组成的核酸序列）；
 *	第三行以"+"开头，后面是描述信息；
 *	第四行是质量信息，与第二行的序列一一对应，每个序列均有一个质量评分，采用字符表示，该字符的ASCII码值即为质量值，取值为33到126的ASCII码（即从字符“!”到字符"~"）
 *	下面给出的是单条生物序列的一个示例（整个文件就是由多个这样的生物序列依次存放组成的）
 *		@SEQ_ID
 *		GATTTGGGGTTCAAAGCAGTATCGATCAAATAGTAAATCCATTTGTTCAACTCACAGTTT
 *		+Description
 *		!''*((((***+))%%%++)(%%%).1***-+*''))**55CCF>>>>>>CCCCCCC65
 *	提示
 *	 1. 检查规则：以每四行为一个处理单元，在这四行中，第一行以'@'开头；第二行只包含ATGC四种核酸（表示核酸的四个字符大小写均可，即小写atgc也是合法字符，并假定序列长度不超过2000）；第三行以'+'开头；第四行的长度与第二行相同，并且为合法的质量取值。建议分别将每个检查规则编写成独立的函数
 *	 2. 采用命令行参数的形式接受文件名参数
 *	 3. 为了简化处理逻辑，当检查到文件有一处格式不合法后，程序即可终止，输出文件格式不合法的提示。只有当文件中所有的内容都合法，程序才输出文件格式合法的提示
 */
#include "stdio.h"
#include "stdlib.h"
#define MAXLENGTH 2000


int checkLine1(char *str);
int checkLine2(char *str);
int checkLine3(char *str);
int checkLine4(char *str);

int main(int argc,char **argv){

	FILE *fp;
	char str[MAXLENGTH],ch;
	int length2,length4;

	if(argc != 2){
		printf("command line number must be 2!\n");
		exit(1);
	}

	if((fp = fopen(argv[1],"r")) == NULL){
		printf("file open failed!\n");
		exit(1);
	}
	while(fscanf(fp,"%s",str) != EOF){
		//处理第一行
		if(checkLine1(str) == 0){
			printf("error:第一行开头必须是@!\n");
			exit(1);
		}
		//处理第二行
		if(fscanf(fp,"%s",str) == EOF){
			printf("error:序列格式必须是4行!\n");
			exit(1);
		}
		if((length2 = checkLine2(str)) == 0){
			printf("error:第二行字符只能是大小写ATCG!\n");
			exit(1);
		}

		//处理第三行
		if(fscanf(fp,"%s",str) == EOF){
			printf("error:序列格式必须是4行!\n");
			exit(1);
		}
		if(checkLine3(str) == 0){
			printf("error:第三行开头必须是+!\n");
			exit(1);
		}
		//处理第四行
		if(fscanf(fp,"%s",str) == EOF){
			printf("error:序列格式必须是4行!\n");
			exit(1);
		}
		if((length4 = checkLine4(str)) == 0){
			printf("error:第四行ASCII必须为33-126\n");
			exit(1);
		}
		if(length4 != length2){
			printf("error:第二行与第四行长度必须一样\n");
			exit(1);
		}
	}
	printf("文件格式正确!\n");
	return 0;
}

int checkLine1(char *str) {return str[0] == '@'?1:0;}
int checkLine2(char *str){
	//第二行是具体的生物序列（即由ATGC组成的核酸序列）
	int length;
	for(length = 0;str[length] != '\0';++length){
	switch(str[length]){
		case 'a':case 't':case 'c':case 'g':
		case 'A':case 'T':case 'C':case 'G':
			break;
		default:return 0;
	}
  }
  return length+1;
}
int checkLine3(char *str){return str[0] == '+'?1:0;}
int checkLine4(char *str){
	int length;
	 for(length = 0;str[length] != '\0';++length)
		if((str[length] - 33 < 0) || (str[length]) - 126 >0)
			return 0;
	return length+1;
}
