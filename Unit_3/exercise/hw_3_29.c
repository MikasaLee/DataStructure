/**
 * 3.29 如果希望循环队列中的元素都能得到利用，则需设置一个标志域tag，并以tag的值为0和1来区分，尾指针和头指针值相同时的队列状态是“空”还是“满”。
 * 试编写与此结构相应的入队列和出队列的算法，并从时间和空间角度讨论设标志和不设标志这两种方法的使用范围（如当循环队列容量较小而队列中每个元素占的空间较多时，哪一种方法较好）。
 */

#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"

typedef char ElemType;

#define MAX_SIZE 10
typedef struct{
	ElemType *base;		//存放数据
	int head;		//头指针
	int tail;		//尾指针

	Bool tag;		//标志位。 0表示满，1表示空
}tagCSQ,*TagCSQ;

Status InitTagCylSqQueue(TagCSQ *q);
Status EnTagCylSqQueue(TagCSQ q,ElemType e);	//入队列
Status DeTagCylSqQueue(TagCSQ q,ElemType *e);	//出队列

Status InitTagCylSqQueue(TagCSQ *q){
	(*q) = (TagCSQ)malloc(sizeof(tagCSQ));
	if(*q){
		(*q) -> base = (ElemType *)malloc(sizeof(ElemType)*MAX_SIZE);
		(*q) -> head = (*q) -> tail = 0;
		(*q) -> tag = 1;
		return OK;
	}
	return ERROR;
}

Status EnTagCylSqQueue(TagCSQ q,ElemType e){
	if(!q)	exit(OVERFLOW);
	if((q -> head == q -> tail) && (q -> tag == 0))	return ERROR;	//队列已满
	q -> base[q -> tail] = e;
	q -> tail = (q -> tail+1)%MAX_SIZE;
	if(q -> head == q -> tail) q -> tag = 0;
	return OK;
}
Status DeTagCylSqQueue(TagCSQ q,ElemType *e){
	if(!q)	exit(OVERFLOW);
	if((q -> head == q -> tail) && (q -> tag == 1))	return ERROR;	//空队列
	(*e) = q -> base[q -> head];
	q -> head = (q -> head+1)%MAX_SIZE;
	if(q -> head == q -> tail) q -> tag = 1;
	return OK;
}

void show(TagCSQ q){
	if(!q)	exit(OVERFLOW);
	if((q -> head == q -> tail) && (q -> tag == 1))	return;	//空队列
	int i = q -> head;
	do{
		printf("%c ",q -> base[i]);
		i = (++i)%MAX_SIZE;
	}while(i != q -> tail);
	printf("\n");
}


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

//当容量小且每个元素占用的空间较多时，此方法更好；
//其他情况两种方法的时间复杂度都是一样的
