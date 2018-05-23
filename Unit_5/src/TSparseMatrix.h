/*************************************************************************
	> File Name: SparseMatrix.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 22 May 2018 08:22:58 PM CST
 ************************************************************************/
/**
 * 稀疏矩阵(Sparse Matrix)之三元组顺序表的头文件定义：
 *		稀疏矩阵：其非零元较零元少，且分布没有一定规律的矩阵。
 *		
 *		三元组顺序表：按照压缩矩阵的概念:** 只存储稀疏矩阵的非零元 ** 。因此，除了存储非零元的值之外，还必须同时记下它所在的行和列的位置(i,j)。
 *					  反之，一个三元组(i,j,Aij)唯一确定了矩阵A的一个非零元。
 *			
 */

#ifndef TSPARSEMATRIX_H
#define TSPARSEMATRIX_H


#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"

//--------------稀疏矩阵的三元组顺序表存储表示------------------------

#ifndef ELEMTYPE
#define ELEMTYPE
typedef int ElemType;
#endif


#define  MAXSIZE 500			//假设非零元个数的最大值为12500
typedef struct{
	int i,j;
	ElemType e;
}triple,*Triple;
typedef struct{
	Triple data[MAXSIZE+1];		//非零元三元组表，data[0]未启用。简单实现，就不再设置成动态了。
	int mu,nu,tu;				//矩阵的行数，列数，非零元的总个数
}tsm,*TSMatrix;

//----------------相关操作-------------------

Status CreateTSMatrix(TSMatrix *M,int mu,int nu);		//创建稀疏矩阵M
Status DestroyTSMatrix(TSMatrix *M);	//销毁稀疏矩阵M
Status SetTSMatrix(TSMatrix *M,ElemType **arr,int arr_mu,int arr_nu);	//用二维数组来初始化M
Status SetDataTSMatrix(TSMatrix M,int i,int j,ElemType e);	//将M[i][j]位置设置为e
Status GetDataTSMatrix(TSMatrix M,int i,int j,ElemType *e);	//得到M[i][j]，赋值给e
void PrintTSMatrix(TSMatrix M);			//打印稀疏矩阵M
Status CopyTSMatrix(TSMatrix M,TSMatrix *T);	//由稀疏矩阵M复制得到T
Status AddTSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q); //稀疏矩阵M,N,Q的行数和列数相等，Q = M + N
Status SubTSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q); //稀疏矩阵M,N,Q的行数和列数相等，Q = M - N
Status MultTSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q);//稀疏矩阵M的列数等于N的行数，Q = M * N
Status TransposeTSMatrix(TSMatrix M,TSMatrix *T);	  //求稀疏矩阵M的转置矩阵T
/** 难点就是求转置矩阵  **/
#endif
