/*************************************************************************
	> File Name: SparseMatrix.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 22 May 2018 08:22:58 PM CST
 ************************************************************************/
/**
 * 稀疏矩阵(Sparse Matrix)之十字链表的头文件定义：
 *		稀疏矩阵：其非零元较零元少，且分布没有一定规律的矩阵。
 *		
 *		当矩阵的非零元个数和位置在操作过程中变化较大时，就不宜采用顺序存储结构来表示三元组的线性表。而应该采用链式存储结构表示三元组的线性表。
 *
 */

#ifndef CLINKMATRIX_H
#define CLINKMATRIX_H


#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"

//--------------稀疏矩阵的十字链表存储表示------------------------

#ifndef ELEMTYPE
#define ELEMTYPE
typedef int ElemType;
#endif

typedef struct CLNode{
	int i,j;					//该非零元的行和列下标
	ElemType e;
	struct CLNode *right,*down;
}CLNode,*CLink;

typedef struct{
	CLink *rhead,*chead;		//行和列链表头指针向量基址。
	int mu,nu,tu;				//稀疏矩阵的行数，列数，非零元个数
}cLMatrix,*CLMatrix;

//----------------相关操作-------------------

Status CreateCLMatrix(CLMatrix *M,int mu,int nu);		//创建稀疏矩阵M
Status DestroyCLMatrix(CLMatrix *M);	//销毁稀疏矩阵M
Status SetCLMatrix(CLMatrix *M,ElemType **arr,int arr_mu,int arr_nu);	//用二维数组来初始化M
Status SetDataCLMatrix(CLMatrix M,int i,int j,ElemType e);	//将M[i][j]位置设置为e
Status GetDataCLMatrix(CLMatrix M,int i,int j,ElemType *e);	//得到M[i][j]，赋值给e
void PrintCLMatrix(CLMatrix M);			//打印稀疏矩阵M
Status CopyCLMatrix(CLMatrix M,CLMatrix *T);	//由稀疏矩阵M复制得到T
Status AddCLMatrix(CLMatrix M,CLMatrix N,CLMatrix *Q); //稀疏矩阵M,N,Q的行数和列数相等，Q = M + N
Status SubCLMatrix(CLMatrix M,CLMatrix N,CLMatrix *Q); //稀疏矩阵M,N,Q的行数和列数相等，Q = M - N
Status MultCLMatrix(CLMatrix M,CLMatrix N,CLMatrix *Q);//稀疏矩阵M的列数等于N的行数，Q = M * N
Status TransposeCLMatrix(CLMatrix M,CLMatrix *T);	  //求稀疏矩阵M的转置矩阵T

#endif
