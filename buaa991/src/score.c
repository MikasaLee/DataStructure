/*************************************************************************
	> File Name: score.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Thu 05 Dec 2019 12:54:15 PM CST
 ************************************************************************/

/**
 * 设存储在D盘根目录下的文本文件score.dat中记录着学生的姓名和成绩，每一行表示一个学生的信息，包括学生姓名(姓名中不存在空格等特殊字符)和成绩，他们之间用制表符\t分割，例如：
 *	zhangsan	84.5
 *	lisi	78
 *	wangwu	65.5
 *	maliu	90
 *
 *	请针对该文件写一个程序，该程序的功能是计算所有学生的平均成绩，并输出其中成绩最高的三个学生的信息(姓名和成绩),若学生总人数不足三人，则输出全部学生成绩
 */
#include "stdio.h"
#include "stdlib.h"
#define MAX 50
typedef struct {
	char stuName[10];
	float stuScore;
}Student,*Stus;

int main(int argc,char **argv){
	FILE *fp;
	int number = 0;
	Stus max1,max2,max3,stus,p;
	float sumScore=0.0;
	
	stus = (Stus)malloc(sizeof(Student)*MAX);
	if(stus == NULL) exit(1);
	if((fp = fopen("score.dat","r")) == NULL) exit(1);//试卷上是fopen("D:\score.dat","r");
	//记住fscanf加!=EOF
	//记住对max1 2 3 也进行初始化，否则他们默认不是NULL
	for(p = stus,max1= max2 =max3 = NULL;fscanf(fp,"%s\t%f",p -> stuName,&(p -> stuScore)) != EOF;++p,++number){
		printf("姓名:%s 分数：%f\n",p ->stuName,p -> stuScore);
		sumScore+=p -> stuScore;
		if(max1 == NULL) max1 = p;
		else if(p -> stuScore > max1 -> stuScore){
			max3 = max2;
			max2 = max1;
			max1 = p;
		}else{
			if(max2 == NULL) max2 = p;
			else if(p -> stuScore > max2 -> stuScore){
				max3 = max2;
				max2 = p;
			}else{
				if(max3 == NULL) max3 = p;
				else if(p -> stuScore > max3 -> stuScore){
					max3 = p;
				}
			}
		}
	}
	printf("平均成绩：%f\n",sumScore/number);
	if(max1) printf("成绩最高姓名:%s\t分数：%f\n",max1 ->stuName,max1 -> stuScore);
	if(max2) printf("成绩第二高姓名:%s\t分数：%f\n",max2 ->stuName,max2 -> stuScore);
	if(max3) printf("成绩第三高姓名:%s\t分数：%f\n",max3 ->stuName,max3 -> stuScore);

	fclose(fp);
	free(stus);

	return 0;
}
