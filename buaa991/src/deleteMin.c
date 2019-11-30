/*************************************************************************
	> File Name: deleteMin.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sat 30 Nov 2019 02:49:54 PM CST
 ************************************************************************/

/**
 * 请编写一程序，该程序的功能是找出并且删除一维整形数组a[100]中的最小值元素
 *	要求：1. 数组对个元素通过键盘输入获得初值
 *		  2. 所有对数组元素的引用必须通过指针完成
 */
/*
 * 输入100个太多了，几个就ok
 */
#include "stdio.h"


#define MAX 10				//考试时只需要将MAX = 100就行
int main(int argc,char **argv){

	int a[MAX],*p,i,min;
	p = a;
	printf("请输入数据：\n");
	for(i = 0;i<MAX;i++) scanf("%d",p+i);
	printf("\nbefore delete:");
	for(i = 0;i<MAX;i++) printf("%d ",*(p+i));

	//删除操作
	for(min = 0,i = 1;i<MAX;i++){
		if(*(p+min) > *(p+i)) min = i;
	}
	for(i = min;i<MAX-1;i++) *(p+i) = *(p+i+1);

	printf("\nafter delete:");
	for(i = 0;i<MAX-1;i++) printf("%d ",*(p+i));
	
	return 1;

}
