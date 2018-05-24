/*************************************************************************
	> File Name: SparseMatrix.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 22 May 2018 08:22:58 PM CST
 ************************************************************************/
/**
 * 稀疏矩阵(Sparse Matrix)之行逻辑链接的顺序表的头文件定义：
 *
 * 为了便于随机存取任意一行的非零元，则需要知道每一行的第一个非零元在三元组表中的位置。为此，可借用快速转置矩阵算法中的"行"信息思想，指示"行"信息的辅助数组cpot固定在稀疏矩阵的存储结构中。称这种"带行链接信息"的三元组为行逻辑链接的顺序表。
 */

#ifndef RLSPARSEMATRIX_H
#define RLSPARSEMATRIX_H


#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"

//--------------稀疏矩阵的行逻辑链接的顺序表存储表示------------------------

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
	int *rpos;					//各行第一个非零元的位置表
	int mu,nu,tu;				//矩阵的行数，列数，非零元的总个数
}RLSm,*RLSMatrix;

//----------------相关操作-------------------

Status CreateRLSMatrix(RLSMatrix *M,int mu,int nu);		//创建稀疏矩阵M
Status DestroyRLSMatrix(RLSMatrix *M);	//销毁稀疏矩阵M
Status SetRLSMatrix(RLSMatrix *M,ElemType **arr,int arr_mu,int arr_nu);	//用二维数组来初始化M
Status SetDataRLSMatrix(RLSMatrix M,int i,int j,ElemType e);	//将M[i][j]位置设置为e
Status GetDataRLSMatrix(RLSMatrix M,int i,int j,ElemType *e);	//得到M[i][j]，赋值给e
void PrintRLSMatrix(RLSMatrix M);			//打印稀疏矩阵M
Status CopyRLSMatrix(RLSMatrix M,RLSMatrix *T);	//由稀疏矩阵M复制得到T
Status AddRLSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix *Q); //稀疏矩阵M,N,Q的行数和列数相等，Q = M + N
Status SubRLSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix *Q); //稀疏矩阵M,N,Q的行数和列数相等，Q = M - N
Status MultRLSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix *Q);//稀疏矩阵M的列数等于N的行数，Q = M * N
Status TransposeRLSMatrix(RLSMatrix M,RLSMatrix *T);	  //求稀疏矩阵M的转置矩阵T
/** 难点就是求转置矩阵  **/
#endif
