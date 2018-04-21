/**
 * 线性表的顺序表示和实现
 * 同时约定完全用C语言实现（不能用c++的引用）
 */

/**
 * 2018-4-18 
 */
#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include "../../Unit_1/src/myDefine.c"
#include <stdlib.h>

#define LIST_INIT_SIZE 5 	//线性表存储空间的起始分配量
#define LIST_INCREMENT 10 	//线性表存储空间的分配增量

#ifndef ELEMTYPE
#define ELEMTYPE
typedef int ElemType;		//定义ElemType
#endif

typedef struct List{
	ElemType *elem;		//存储空间基地址
	int length;		//当前长度
	int listsize;		//当前分配的存储容量，sizeof(ElemType)为单位
}sqList,*SqList;

//初始化线性表，成功返回1，失败返回0
Status InitList_Sq(SqList *L);
//销毁线性表
Status DestroyList_Sq(SqList *L);
//将线性表清空
Status ClearList_Sq(SqList L);
//判断线性表是否为空，是返回TRUE，否则返回FALSE
Bool  ListEmpty_Sq(SqList L);
//得到线性表第i个元素的值,并将其赋予e
Status GetElem_Sq(SqList L,int i,ElemType *e);
//根据判断函数，返回符合条件的第一个元素的序列，若没有符合的返回0
int LocateElem_Sq(SqList L,ElemType e,Bool (*compare)(ElemType a,ElemType b));
//得到前驱
Status PriorElem_Sq(SqList L,ElemType cur_e,ElemType *pre_e);
//得到后继
Status NextElem_Sq(SqList L,ElemType cur_e,ElemType *next_e);
//插入操作
Status ListInsert_Sq(SqList L,int i,ElemType e);
//删除操作
Status ListDelete_Sq(SqList L,int i,ElemType *e);
//输出线性表L的所有信息
void PrintList_Sq(SqList L);
//遍历线性表
Status ListTraverse_Sq(SqList L,Bool visit(ElemType e));
#endif
