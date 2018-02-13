/**
 * 线性表的定义（没有头结点）
 * 同时约定完全用C语言实现（不能用c++的引用）
 */
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
