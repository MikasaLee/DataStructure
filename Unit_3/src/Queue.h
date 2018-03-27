/**
 * 链式存储队列(Queue)的头文件
 */

#ifndef QUEUE_H 
#define QUEUE_H
#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"

#if (!defined HW_3_31_C)	//hw_3_31需要使用栈和队列
typedef char ElemType;
#endif

typedef struct node{
	ElemType data;	//数据域
	struct node * next;	//指针域
}node,*Node;

typedef struct{
	Node head;		//首节点		
	Node tail;		//尾节点
}queue,*Queue;

Status InitQueue(Queue *q);		//构造一个空队列
Status DestroyQueue(Queue *q);		//销毁一个队列
Status ClearQueue(Queue q);		//清空一个队列
Bool QueueEmpty(Queue q);		//若队列为空队列，则返回TRUE，否则返回FALSE
int QueueLength(Queue q);		//返回队列Q的元素个数，即为队列的长度
Status GetHead(Queue q,ElemType *node);	//若队列不为空，则用e返回Q的队头元素，并返回OK；否则返回ERROR
Status EnQueue(Queue q,ElemType e);	//插入元素e为Q的新的队尾元素
Status DeQueue(Queue q,ElemType *e);	//删除Q的队头元素，用e返回其值，并返回OK；否则返回ERROR
Status QueueTraverse(Queue q,Bool visit(ElemType));	//用visit遍历队列Q的所有元素，若有一个返回FALSE，则返回FALSE；否则返回TRUE
#endif
