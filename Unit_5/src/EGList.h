/*************************************************************************
	> File Name: EGList.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sat 26 May 2018 05:28:47 PM CST
 ************************************************************************/

//---------广义表的扩展线性链表存储方式--------------

#ifndef EGLIST_H
#define EGLIST_H

typedef enum {ATOM,LIST} ElemTag;	//ATOM = 0，原子；LIST = 1，子表

#ifndef ELEMTYPE
#define ELEMTYPE
typedef char ElemType;
#endif
#include "../../Unit_4/src/mySString.c"		//提供字符串SString,SString[0]存放着该串的长度
typedef  ElemType AtomType;

typedef struct EGLNode{
	ElemTag tag;				//公共部分，用于区分原子节点和表节点			
	union{						//不同层次
		AtomType atom;			
		struct EGLNode *hp;		
	}Union;
	struct EGLNode *tp;			//同一层次，相当于next

}EGLNode,*EGList;

//--------------------基本操作---------------------

Status InitEGList(EGList *L);				//创建空的广义表
Status CreateEGList(EGList *L,SString S);	//由广义表的字符串表示S创建广义表L；其中，S是格式形如(a,b,(c,d,()),e)
Status DestroyEGList(EGList *L);			//销毁广义表L
Status CopyEGList(EGList L,EGList *T);		//由广义表L复制得到T
int EGListLength(EGList L);				//得到广义表的长度
int EGListDepth(EGList L);				//得到广义表的深度
Bool EGListEmpty(EGList L);				//判断广义表是否为空
EGList EGetHead(EGList L);					//取得广义表L的头
EGList EGetTail(EGList L);					//取得广义表L的尾
Status InsertFirst_EGL(EGList *L,EGList e);	//插入元素e作为广义表L的第一元素
Status DeleteFirst_EGL(EGList *L,EGList *e);	//删除广义表的第一元素，并用e返回其值
Status Traverse_EGL(EGList L,Bool (*visit)(AtomType));	//用visit函数遍历广义表L的每个元素

#endif

