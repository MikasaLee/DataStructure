/**
 * 队列(Queue)的头文件
 */

#ifndef QUEUE_H 
#define QUEUE_H

#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"

//#if !define  //模版准备好
typedef char ElemType;
//#endif

typedef struct node{
	ElemType data;	//数据域
	struct node * next;	//指针域
}node,*Node;

typedef struct{
	Node head;		//首节点		
	Node tail;		//尾节点
}queue,*Queue;

#endif
