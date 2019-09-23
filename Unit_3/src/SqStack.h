/**
 * 顺序栈的头文件
 */

#ifndef SQSTACK_H
#define SQSTACK_H

#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"

#define STACK_INIT_SIZE 10
#define STACKINCREMENT 5

/* 在SqStack的测试2文件，数值转换文件，迷宫求解中,表达式运算,习题3.20,习题3.27,Unit_6/src/InOrderTraverse.h
 * 中需要重新定义ElemType*/
#if (!defined TEST_C) && (!defined CONVERSION_C) && (!defined MAZEPATH_H) &&(!defined EXPRESSION_H) && (!defined HW_3_20_C) && (!defined HW_3_27_C) &&(!defined HW_3_33_C) &&(!defined INORDERTRAVERSE_H) 
typedef char ElemType;
#endif

typedef struct{
	ElemType *base;
	ElemType *top;
	int capacity;	//base的容量
}SqStack,*SqStack_L;

Status InitStack_Sq(SqStack_L *S);	//构造空栈
Status DestroyStack_Sq(SqStack_L *S);	//销毁栈
Status ClearStack_Sq(SqStack_L S);	//清空栈
Bool StackEmpty_Sq(SqStack_L S);	//判断栈是否为空
int StackLength_Sq(SqStack_L S);	//返回栈中元素的个数
Status GetTop_Sq(SqStack_L S,ElemType *e);	//返回栈顶元素
Status Push_Sq(SqStack_L S,ElemType e);	//压入元素
Status Pop_Sq(SqStack_L S,ElemType *e);	//弹出元素给e
Status StackTraverse_Sq(SqStack_L S,Bool visit(ElemType e));	//访问栈

#endif

