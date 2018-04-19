/**
 * 扩展版本的线性表，书上p37页对应着相关的定义
 * 扩展版本的线性表分为两部分，链表类型和节点类型，链表类型中定义着该链表的一些基本信息,可以在一定程度上减小了普通链表类型的缺点
 */
#ifndef EXTENDLINKLIST_H
#define EXTENDLINKLIST_H

#include "stdio.h"
#include "../../Unit_1/src/myDefine.c"
#include "stdlib.h"

typedef int ElemType;
typedef struct ELNode{		//节点类型
	//数据域
	ElemType data;
	//指针域
	struct ELNode *next;
	struct ELNode *prior;
}ELNode,*Link,*Position;

typedef struct{			//链表类型
	Link head,tail;		//分别指向头结点和尾节点	注意头结点现在和普通节点一样，也可以存放数据
	int length;		//链表当前节点的个数
}ELink,*ELinkList;

//-----------------------------------------------------------------
//声明的方法：

//创建一个节点,data为e,并且返回给L
Status MakeNode_EL(Link *L,ElemType e);

//释放L所指向的节点
void FreeNode_EL(Link *L);

//销毁一个扩展线性链表
Status DestroyList_EL(ELinkList *L);

//清空操作
Status ClearList_EL(ELinkList *L);

//得到扩展线性链表L的长度
int ListLength_EL(ELinkList L);

//判断是否为空链表
Bool ListEmpty_EL(ELinkList L);

//返回链表中头节点的指针
Position GetHead_EL(ELinkList L);

//返回链表中最后一个节点的指针
Position GetLast_EL(ELinkList L);

//ListInsert方法，书上没有要求，但是很多方法都是基于ListInsert实现的。
//同时实现两个ListInsert方法，一个是可以实现插入ElemType,而另一个是两个链表的连接操作
Status ListInsertElemType_EL(ELinkList L,int i,ElemType e);

//将节点L2中的一部分节点[L2_head,L2_tail]插入到L1的第i个位置(！！！！注意是插入，不是复制！！！) 
//k = L2_tail - L2_head + 1.
Status ListInsertELinkList_EL(ELinkList L1,int i,Link L2_head,Link L2_tail,int k);

//ListDelete方法
Status ListDelete_EL(ELinkList L,int i,Link *e);

//查找的方法：范围是(begin,end]
Link ListSearch_EL(ELinkList L,int *begin,int end,ElemType e);

//返回p指示线性链表L中第i个节点的位置并返回ok
Status LocatePos_EL(ELinkList L,int i,Link *e);

//GetElem方法，和LocatePos的不同只是返回的是Link的data。
Status GetElem_EL(ELinkList L,int i,ElemType *e);

//在第一个位置上插入节点s	
Status InsFirst_EL(ELinkList L,Link s);

//删除第一个位置上的节点，并且返回给q
Status DelFirst_EL(ELinkList L,Link *q);

//将链表Lb的一部分链接到La的第i个节点上
Status AppendSome_EL(ELinkList La,int src,ELinkList Lb,int begin,int end);

//将链表Lb的剩余部分连接到La上
Status Append_EL(ELinkList La,ELinkList Lb,int begin);

//删除线性链表中L的尾节点并以p返回
Status Remove(ELinkList L,Link *p);

//已知p指向线性表L中的一个节点，将s所指节点插入在p所指的节点之前，//并修改指针p指向新插入的节点
Status InsBefore_EL(ELinkList L,Link *p,Link s);
//已知p指向线性表L中的一个节点，将s所指节点插入在p所指节点之后
Status InsAfter_EL(ELinkList L,Link *p,Link s);

//setget方法：已知p为线性表中的一个节点，更新/得到其data
Status SetCurElem(Link p,ElemType e);
ElemType GetCurElem(Link p);

//已知p指向线性链表L的一个节点，返回p所指节点的直接前驱的位置
Position PriorPos(Link p);
//已知p指向线性链表L的一个节点，返回p所指节点的直接后继的位置
Position NextPos(Link p);

//用于测试LocateElem的equals
Bool equals(ElemType a,ElemType b);
//得到L中第一个与元素e满足compare关系的节点
Position LocateElem_EL(ELinkList L,ElemType e,Bool (*compare)(ElemType,ElemType));

Bool visit(ElemType e);
//遍历链表
Status ListTraverse_EL(ELinkList L,Bool (*visit)(ElemType));

//打印链表
void Print_EL(ELinkList L);
#endif
