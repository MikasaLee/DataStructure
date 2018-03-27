/**
 * 3.30 假设将循环队列定义为：以域变量rear和length分别指示循环队列中队尾元素的位置和内含元素的个数。
 * 试给出此循环队列的队满条件，并写出相应的入队列和出队列的算法（在出队列的算法中要返回队头元素）。
 */

#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"

#if (!defined MAIN)
typedef char ElemType;
#endif
#define MAX_SIZE 10
typedef struct{
	ElemType *base;		//存放数据
	int length;		//元素个数
	int tail;		//尾指针

}tagCSQ,*TagCSQ;

Status InitTagCylSqQueue(TagCSQ *q);
Status EnTagCylSqQueue(TagCSQ q,ElemType e);	//入队列
Status DeTagCylSqQueue(TagCSQ q,ElemType *e);	//出队列

Status InitTagCylSqQueue(TagCSQ *q){
	(*q) = (TagCSQ)malloc(sizeof(tagCSQ));
	if(*q){
		(*q) -> base = (ElemType *)malloc(sizeof(tagCSQ)*MAX_SIZE);
		(*q) -> tail = (*q) -> length = 0;
		return OK;
	}
	return ERROR;
}

Status EnTagCylSqQueue(TagCSQ q,ElemType e){
	if(!q)	exit(OVERFLOW);
	if(q -> length == MAX_SIZE)	return ERROR;
	q -> base[q -> tail] = e;
	q -> tail = (q -> tail +1)%MAX_SIZE;
	q -> length++;
	return OK;
}
Status DeTagCylSqQueue(TagCSQ q,ElemType *e){
	if(!q)	exit(OVERFLOW);
	if(q -> length == 0)	return ERROR;
	(*e) = q -> base[(q -> tail - q -> length + MAX_SIZE)%MAX_SIZE]; 
	q -> length--;
	return OK;
}
void show(TagCSQ q){
	if(!q)	exit(OVERFLOW);
	if(q -> length == 0)	return;	//空队列
	int i = (q -> tail - q -> length + MAX_SIZE)%MAX_SIZE;
	do{
		printf("%c ",q -> base[i]);
		i = (++i)%MAX_SIZE;
	}while(i != q -> tail);
	printf("\n");
}
#ifndef MAIN
int main(int argc,char **args){
	TagCSQ t;
	ElemType e;
	int i;
	if(InitTagCylSqQueue(&t)){
		for(i = 0;i<10;i++)	EnTagCylSqQueue(t,i+'0');
		show(t);
		for(i = 0;i<10;i++)	{DeTagCylSqQueue(t,&e);printf("%c ",e);}
		show(t);
	}
}
#endif

//当容量小且每个元素占用的空间较多时，此方法更好；
//其他情况两种方法的时间复杂度都是一样的
