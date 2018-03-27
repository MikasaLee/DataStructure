/**
 * 循环队列的顺序表示和实现（头文件）
 * 	当队列用顺序存储时，容易造成空间的浪费；而用链式存储时，会设计到申请释放空间，操作不便。因此让二者折中所以就出现了循环队列
 *	循环队列在设计上依旧采用数组，而在逻辑上用链表
 */

#ifndef CYLSQQUEUE_H
#define CYLSQQUEUE_H
#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"

//银行模拟业务,习题hw_3_33.c中中需要重新定义ElemType
#if (!defined BANK_SIMULATION_H) && (!defined HW_3_33_C)
typedef char ElemType;
#endif

#define MAX_SIZE 10
typedef struct{
	ElemType *base;		//存放数据
	int head;		//头指针
	int tail;		//尾指针
}cylSqQueue,*CylSqQueue;

Status InitCylSqQueue(CylSqQueue *q);
Status DestroyCylSqQueue(CylSqQueue *q);
Status ClearCylSqQueue(CylSqQueue q);
Bool CylSqQueueEmpty(CylSqQueue q);
int CylSqQueueLength(CylSqQueue q);
Status GetHead_CSQ(CylSqQueue q,ElemType *node);
Status EnCylSqQueue(CylSqQueue q,ElemType e);
Status DeCylSqQueue(CylSqQueue q,ElemType *e);
Status CylSqQueueTraverse(CylSqQueue q,Bool visit(ElemType));
#endif


