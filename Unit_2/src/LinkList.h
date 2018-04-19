/**
 * 线性表的顺序表示和实现
 * 同时约定完全用C语言实现（不能用c++的引用）
 */
#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include "../../Unit_1/src/myDefine.c"
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
	//数据域
	ElemType data;
	//指针域
	struct LNode * next;
} LNode,*LinkList;

//构造一个空的链表（构造head节点,并规定当ELemType为int/long类型时，头结点的data为当前的节点个数）
Status InitList_L(LinkList *L);
//销毁链表（包括头结点也销毁）
Status DestroyList_L(LinkList *L);
Status ClearList_L(LinkList *L);
//判断链表是否为空。
Bool ListEmpty_L(LinkList L);
//返回L中节点的个数
int ListLength_L(LinkList L);
//返回第i个节点的数据域(注意：实际应用中最好是将数据域置为vector或者各种数据存储格式(xml,yaml,json...)有利于数据域的扩展，但是链表的考察点不在这里，故只有一个data意思意思就行了)
Status GetElem_L(LinkList L,int i,ElemType *e);
//LocateElem_L的compare函数,第一个参数是否比第二个参数大
Bool max(ElemType a,ElemType b);
Bool equals(ElemType a,ElemType b);
//返回第一个与e满足关系compare函数的L的节点的节点次序
int LocateElem_L(LinkList L,ElemType e,Bool (*compare)(ElemType a,ElemType b));
//得到数据域是cur_e的前一个数据，赋值给pre_e,若不存在,pre_e = NULL;
Status PriorElem_L(LinkList L,ElemType cur_e,ElemType *pre_e);
//得到cur_e的下一个数据域，并返回给next_e
Status NextElem_L(LinkList L,ElemType cur_e,ElemType *next_e);

//在第i个节点的位置上插入元素e
Status ListInsert_L(LinkList L,int i,ElemType e);
//在第i个节点的位置上删除元素e
Status ListDelete_L(LinkList L,int i,ElemType *e);
//visit()
Bool visit(ElemType e);
//遍历链表
Status ListTraverse_L(LinkList L,Bool visit(ElemType e));
//显示链表
void Print_L(LinkList L);
#endif
