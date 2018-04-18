/**
 * 循环链表的实现
 * 主要实现与单链表基本一致，但最主要的不同是判断链表结束由p/p->next为空改成了p/p->next是否指向头结点
 */
#ifndef CIRCULARLINKLIST_H
#define CIRCULARLINKLIST_H
#include "stdio.h"
#include "../../Unit_1/src/myDefine.c"
#include "stdlib.h"

typedef int ElemType;
typedef struct CLNode{
	//数据域
	ElemType data;
	//指针域
	struct CLNode *next;
	
}CLNode,*CLinkList;

//构造一个空的线性循环链表。
Status InitList_CL(CLinkList *CL);
//销毁一个线性循环链表
Status DestroyList_CL(CLinkList *CL);
//清空循环链表
Status ClearList_CL(CLinkList *CL);
//判断循环链表是否为空
Bool ListEmpty_CL(CLinkList CL);
//得到循环链表的节点的长度
int ListLength_CL(CLinkList CL);
//得到循环链表第i个位置的data
Status GetElem_CL(CLinkList CL,int i,ElemType *e);
//LocateElem_CL 的compare函数
Bool max(ElemType a,ElemType b);
Bool equals(ElemType a,ElemType b);
//返回第一个与e满足关系compare函数的L的节点的节点次序
int LocateElem_CL(CLinkList CL,ElemType e,Bool (*compare)(ElemType ,ElemType));
//得到数据域是cur_e的前一个数据，赋值给pre_e,若不存在,pre_e = NULL;
//特殊情况，若cur_e为第一个节点的data，那么pre_e为最后一个节点的data
Status PriorElem_CL(CLinkList CL,ElemType cur_e,ElemType *pre_e);
//得到数据域是cur_e的前一个数据，赋值给next_e,若不存在,next_e = NULL;
//特殊情况，若cur_e为最后一个节点的data，那么next_e为第一个节点的data
Status NextElem_CL(CLinkList CL,ElemType cur_e,ElemType *next_e);
//在第i个节点的位置插入元素e
Status ListInsert_CL(CLinkList CL,int i,ElemType e);
//删掉第i个节点，并且将第i个节点的data传给e
Status ListDelete_CL(CLinkList CL,int i,ElemType *e);
//-------------------------
//visit()
Bool visit(ElemType e);
Status ListTraverse_CL(CLinkList CL,Bool (*visit)(ElemType));
//显示链表
void Print_CL(CLinkList CL);
#endif
