/*************************************************************************
	> File Name: GList.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Fri 25 May 2018 08:09:20 PM CST
 ************************************************************************/

/**
 * 广义表的头尾节点链表存储表示
 * 广义表是线性表的推广，简单来说，就是允许线性表中嵌套线性表
 *		书上给了两种定义方法，但是头尾链表貌似定义不完全，还缺一个标志位来说明tp指向的为同一层次还是不同层次。（也可能是我还有什么地方没有注意到，求指点。。）实在是写不下去了，无奈。。。
 * 
 * 头尾链表法先放这里，貌似第八章会对其有所改进。之后再说
 */

#ifndef GLIST_H
#define GLIST_H

typedef enum {ATOM,LIST} ElemTag;	//ATOM = 0，原子；LIST = 1，子表

#ifndef ELEMTYPE
#define ELEMTYPE
typedef char ElemType;
#endif
#include "../../Unit_4/src/mySString.c"		//提供字符串SString,SString[0]存放着该串的长度
typedef  ElemType AtomType;

typedef struct GLNode{
	ElemTag tag;							//公共部分，用于区分原子节点和表节点
	union{
		AtomType atom;						//atom表示原子节点的值
		struct{struct GLNode *hp,*tp;}ptr;	//ptr表示子表的指针域，hp和tp分别指向表头和表尾。
		/** 
		 *	（1）表头：当广义表LS非空时，称第一个元素为LS的表头
		 *	（2）表尾：称广义表LS中除去表头后其余元素组成的广义表为LS的表尾。所以表尾取出后还要再加一个()
		 */
	}Union;
}GLNode,*GList;

//--------------------基本操作---------------------

Status InitGList(GList *L);				//创建空的广义表
Status CreateGList(GList *L,SString S);	//由广义表的字符串表示S创建广义表L；其中，S是格式形如(a,b,(c,d,()),e)
Status DestroyGList(GList *L);			//销毁广义表L
Status CopyGList(GList L,GList *T);		//由广义表L复制得到T
int GListLength(GList L);				//得到广义表的长度
int GListDepth(GList L);				//得到广义表的深度
Bool GListEmpty(GList L);				//判断广义表是否为空
GList GetHead(GList L);					//取得广义表L的头
GList GetTail(GList L);					//取得广义表L的尾
Status InsertFirst_GL(GList *L,GList e);	//插入元素e作为广义表L的第一元素
Status DeleteFirst_GL(GList *L,GList *e);	//删除广义表的第一元素，并用e返回其值
Status Traverse_GL(GList L,Bool (*visit)(AtomType));	//用visit函数遍历广义表L的每个元素

#endif
