/**
 * 双向链表的实现
 */
#include <stdio.h>
#include "/home/C/DataStructure/Unit_1/src/myDefine.c"
#include <stdlib.h>

typedef int ElemType;
typedef struct DuLNode{
	//数据域：
	ElemType data;
	//指针域：
	struct DuLNode * prior;		//指向前一个节点
	struct DuLNode * next;		//指向后一个节点

}DuLNode,*DuLinkList;
