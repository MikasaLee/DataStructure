/**
 * 一元多项式的实现。课本2.4
 */
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stdio.h>
#include "../../Unit_1/src/myDefine.c"
#include <stdlib.h>
#include <math.h>

//float不能比较是否相等，只能取近似值
#define infinitesimal 1e-6

typedef struct {		//每一项的表示
	float coef;	//系数
	int expn;	//指数
}ElemType,term;

typedef struct LinkList{	//多项式的链表
	//数据域
	ElemType data;

	//指针域
	struct LinkList* next;
}LNode,*LinkList;

typedef struct polynomial{	//链表的头结点。
	//一元多项式
	LinkList head;

	//当前该一元多项式的长度
	int length;		
}poly, *Polynomial,*polynomial;

//输入m项的系数和指数，建立一元多项式P
Status CreatePolyn(Polynomial *p,int m);

//销毁一元多项式p
Status DestroyPolyn(Polynomial *p);

//打印输出一元多项式P
void PrintPolyn(Polynomial p);

//得到一元多项式的长度
int PolynLength(polynomial p);

//往一元多项式中加一项
Status AddNode(Polynomial p,float coef,int expn);

//往一元多项式中加一个一元多项式
Status AddPolyn(Polynomial *Pa,polynomial *Pb);

//一元多项式Pa减去一元多项式Pb
Status SubtractPolyn(Polynomial *Pa,polynomial *Pb);

//一元多项式相乘
Status MultiplyPolyn(polynomial *Pa,polynomial *Pb);

//将一元多项式化为非递减的最简式
Status SimplesetPolyn(Polynomial p);
#endif
