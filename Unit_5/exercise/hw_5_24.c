/*************************************************************************
	> File Name: hw_5_24.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 28 May 2018 07:08:09 PM CST
 ************************************************************************/

/**
 * 5.24 三元组顺序表的另一种变型是，不存矩阵元素的行、列下标，而存非零元在矩阵中以行为主序时排列的顺序号，即在LOC(0, 0)=1，l=1时按教科书5.2节中公式(5-2)计算出的值。试写一算法，由矩阵元素的下标值i，j求元素的值。
 */

#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"

/** 三元组的表示：
 *
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
**/

typedef int ElemType;
#define MAXSIZE 500

typedef struct{
	int locate;
	ElemType e;
}triple,*Triple;
typedef struct{
	Triple data[MAXSIZE+1];
	int mu,nu,tu;
}matrix,*Matrix;

Status GetData_5_24(Matrix M,int i,int j,ElemType *e){
	int curor,locate;
	if(!M || i<0|| i > M -> mu|| j<0||j>M -> nu) return ERROR;
	locate = (M -> nu)*i+j;
	for(curor = 1;(curor<=M -> tu)&&(M -> data[curor] -> locate <= locate);curor++){
		if(M ->data[curor] -> locate == locate){
			(*e) = M -> data[curor] -> e;
			return OK;
		}
	}
	(*e) = 0;
	return OK;
}

Status CreateMatrix_5_24(Matrix *M,ElemType **arr,int row,int cols){
	int i,j;
	if(!arr) return ERROR;
	if(!((*M) = (Matrix )malloc(sizeof(matrix)))) exit(OVERFLOW);
	(*M) -> mu = row;
	(*M) -> nu = cols;
	(*M) -> tu = 0;
	for(i = 0;i<row;i++){
		for(j = 0;j< cols;j++){
			if(arr[i][j]!=0){
				if(!((*M) -> data[++((*M) -> tu)] = (Triple)malloc(sizeof(triple)))) 
					exit(OVERFLOW);
				else{
					(*M) -> data[(*M) -> tu] -> e = arr[i][j];
					(*M) -> data[(*M) -> tu] -> locate = i * cols+j;
				}	
			}
		}
	}
	return OK;
}



int main(int argc,char **argv){
	Matrix M;
	int row,cols,i;
	row = cols = 5;
	ElemType temp;
	ElemType **arr = (ElemType **)malloc(sizeof(ElemType *)*row);
	for(i = 0;i<row;i++){
		arr[i] = (ElemType *)malloc(sizeof(ElemType)*cols);
	}
	arr[0][1] = 1;
	arr[0][3] = 5;
	arr[1][2] = -3;
	arr[1][4] = 2;
	arr[2][0] = 2;
	arr[2][1] = 3;
	arr[2][2] = 4;
	arr[3][3] = 2;
	arr[4][0] = 3;
	arr[4][1] = -1;

	
	if(CreateMatrix_5_24(&M,arr,row,cols)){
		GetData_5_24(M,0,1,&temp);
		printf("%d\n",temp);
		GetData_5_24(M,2,0,&temp);
		printf("%d\n",temp);
		GetData_5_24(M,4,1,&temp);
		printf("%d\n",temp);
	}

}
