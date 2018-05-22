/**
 * 数组的顺序存储(行序为主序)
 *
 */

#ifndef ARRAY_H
#define ARRAY_H

#include "../../Unit_1/src/myDefine.c"
#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"		// stdarg：standard arguments:主要目的是让函数能接受可变参数

#define MAX_ARRAY_DIM  8 //假设数组维数的最大值为8

#ifndef ELEMTYPE
#define ELEMTYPE
typedef char ElemType;
#endif

typedef struct {
	ElemType *base;			//数组元素的基址,由InitArray分配
	int dim;				//数组维数
	int *bounds;			//数组维界地址，由InitArray分配
	int *constants;			//数组映像函数常量基址,即constants存储移动每一行(或每一列)所需跨越的元素个数，由InitArray分配
}array,*Array;

//-------------基本操作的函数原型声明----------------------
Status InitArray(Array *A,int dim, ...);	//若维数dim和随后的各维长度合法，则构造相应的数组A，并返回OK
Status DestroyArray(Array *A);				//销毁数组A
Status Value(Array A,ElemType *e,...);		//A为n维数组，e为元素变量，随后是n个下标值。 若各下标不超界，则e赋值为所指定的A的元素值，并返回OK
Status Assign(Array A,ElemType e,...);		//A是n维数组，e为元素变量，随后是n个下标值。 若下标不超界，则将e的值赋给所指定的A的元素，并返回OK
Status Locate(Array A,va_list ap,int *off); //若ap中的各个参数给的正确，那么off为偏移量并且返回OK，否则off为-1并且返回-1
void PrintArray(Array A);					//打印数组A
#endif

/**
 * 注：Value()和Assign()函数中用到的公式：
 *		LOC(j1,j2,...,jn) = LOC(0,0,...,0) + c0j0+c1j1+...ciji;
 *		其中 cn = L,c(i-1) = bi*ci; 1 < i <= n
 */
