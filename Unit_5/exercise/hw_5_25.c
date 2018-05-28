/*************************************************************************
	> File Name: hw_5_25.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 28 May 2018 08:08:27 PM CST
 ************************************************************************/

/**
 *	5.25若将稀疏矩阵A的非零元素以行序为主序的顺序存于一维数组V中，并用二维数组B表示A中的相应元素是否为零元素（以0和1分别表示零元素和非零元素）
 *	试写一算法，实现在上述表示法中实现矩阵相加的运算。并分析你算法的时间复杂度。
 */

#include "../src/RLSparseMatrix.c"	//行逻辑表示的稀疏矩阵

typedef struct{
	RLSMatrix M;
	int arr[MAXSIZE+1];
}matrix,*Matrix;

Status CreateMatrix_5_25(Matrix *M,int **element,int row,int cols){
	int curor,i,j;
	ElemType temp;
	Matrix p;
	if(!element){
		element = (ElemType **)malloc(sizeof(ElemType *)*row);
		for(i = 0;i<row;i++){
			element[i] = (ElemType *)malloc(sizeof(ElemType)*cols);
		}
		for(i = 0;i<row;i++){
			for(j = 0;j<cols;j++){
				element[i][j] = 0;
			}
		}
	}


	if(!((*M) = (Matrix)malloc(sizeof(matrix)))) exit(OVERFLOW);
	p = (*M);
	if(!SetRLSMatrix(&(p-> M),element,row,cols)) return ERROR;
//	if(!(p-> arr = (int *)malloc(sizeof(int)*(p -> M -> tu + 1)))) exit(OVERFLOW);	//arr[0] 用来存放长度
	p -> arr[0] = p -> M-> tu;
	for(curor = 1;curor<=p -> M -> tu;curor++){
		GetDataRLSMatrix(p -> M,p -> M->data[curor]->i,p -> M -> data[curor]->j,&temp);
		(*M) -> arr[curor] = temp;
		SetDataRLSMatrix(p-> M,p-> M->data[curor]->i,p -> M -> data[curor]->j,1);
	}
	return OK;
}

Status AddMatrix_5_25(Matrix M,Matrix N,Matrix *T){
	int i,j,k;
	ElemType flag_i,flag_j;
	Matrix p;
	if(!M || !N || (M -> M -> mu != N -> M ->mu) || (M -> M-> nu != N -> M ->nu)) return ERROR;
	if(!CreateMatrix_5_25(T,NULL,M -> M-> mu,M -> M ->nu)) exit(OVERFLOW);
	p = *T;

	for(i = j = k = 1;(i<= M ->M ->tu)&&(j<= N -> M ->tu);){
		flag_i = (M -> M -> data[i] -> i) * (M -> M -> nu)+(M -> M ->data[i] -> j);
		flag_j = (N -> M -> data[j] -> i) * (N -> M -> nu)+(N -> M ->data[j] -> j);
		if(flag_i < flag_j){
			p -> arr[k] = M -> arr[i];
			SetDataRLSMatrix(p -> M,M -> M->data[i]->i,M -> M -> data[i]->j,1);
			++k;
			++i;
		}else if(flag_i == flag_j){
			if(M ->arr[i] + N ->arr[j] != 0 ){
				p -> arr[k] = M -> arr[i] + N -> arr[j];		
				SetDataRLSMatrix(p -> M,M -> M->data[i]->i,M -> M -> data[i]->j,1);
				++k;
			}
			++i;
			++j;
		}else{
			p -> arr[k] = N -> arr[j];
			SetDataRLSMatrix(p -> M,N -> M->data[j]->i,N -> M -> data[j]->j,1);
			++k;
			++j;
		}
	}
	while(i <= M -> M -> tu){
		p -> arr[k] = M -> arr[i];
		SetDataRLSMatrix(p -> M,M -> M->data[i]->i,M -> M -> data[i]->j,1);
		++k;
		++i;
	}
	while(j <= N -> M -> tu){
		p -> arr[k] = N -> arr[j];
		SetDataRLSMatrix(p -> M,N -> M->data[j]->i,N -> M -> data[j]->j,1);
		++k;
		++j;
	}
	p -> M -> tu = --k;
	return OK;
}
void PrintMatrix(Matrix M){
	int i;
	printf("[");
	for(i = 1;i<=M -> M ->tu;i++)
		printf("%d ",M -> arr[i]);
	printf("]\n");
	for(i = 0;i<M -> M ->mu;i++)
		printf("%d ",M -> M -> rpos[i]);
	PrintRLSMatrix(M -> M);
	return;
}

int main(int argc,char **argv){
	Matrix M,T,N;
	int row = 5,cols=5,i;

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

	
	ElemType **arr1 = (ElemType **)malloc(sizeof(ElemType *)*row);
	for(i = 0;i<row;i++){
		arr1[i] = (ElemType *)malloc(sizeof(ElemType)*cols);
	}
	arr1[0][0] = -3;
	arr1[0][2] = 2;
	arr1[1][3] = -1;
	arr1[2][1] = 4;
	arr1[3][0] = 6;
	arr1[3][4] = 5;
	arr1[4][0] = 3;
	arr1[4][3] = 2;

	
	CreateMatrix_5_25(&M,arr,row,cols);
	CreateMatrix_5_25(&N,arr1,row,cols);
	PrintMatrix(M);
	PrintMatrix(N);
	AddMatrix_5_25(M,N,&T);
	PrintMatrix(T);
	return 0;
}

