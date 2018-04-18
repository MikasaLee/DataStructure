/**
 * 双向链表的实现
 */
#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H
#include <stdio.h>
#include "../../Unit_1/src/myDefine.c"
#include <stdlib.h>

typedef int ElemType;
typedef struct DuLNode{
	//数据域：
	ElemType data;
	//指针域：
	struct DuLNode * prior;		//指向前一个节点
	struct DuLNode * next;		//指向后一个节点

}DuLNode,*DuLinkList;

//构造双向链表
Status InitList_DL(DuLinkList *DL);	//规定头结点的data为0,prior为NULL

Status DestroyList_DL(DuLinkList *DL);
Status ClearList_DL(DuLinkList *DL);
Bool ListEmpty_DL(DuLinkList DL);
int ListLength_DL(DuLinkList DL);
Status GetElem_DL(DuLinkList DL,int i,ElemType *e);
//---------compare函数-----------------------
Bool equals(ElemType a,ElemType b);
int LocateElem_DL(DuLinkList DL,ElemType e,Bool (*compare)(ElemType,ElemType));
//如果cur_e是第一个节点的data，那么pre_e也是NULL
Status PriorElem_DL(DuLinkList DL,ElemType cur_e,ElemType *pre_e);
Status NextElem_DL(DuLinkList DL,ElemType cur_e,ElemType *next_e);
Status ListInsert_DL(DuLinkList DL,int i,ElemType e);
Status ListDelete_DL(DuLinkList DL,int i,ElemType *e);
//------visit函数--------------
Bool visit(ElemType e);
Status ListTraverse_DL(DuLinkList DL,Bool (*visit)(ElemType));
void Print_DL(DuLinkList DL);
#endif
