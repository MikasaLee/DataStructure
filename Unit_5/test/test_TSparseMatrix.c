/*************************************************************************
	> File Name: test_TSparseMatrix.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 23 May 2018 06:19:09 PM CST
 ************************************************************************/

#include "../src/TSparseMatrix.c"

int main(int argc,char **argv){
	TSMatrix M,T,N;
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

	printf("-------------测试SetTSMatrix(),其中包含了CreateTSMatrix(),SetDataTSMatrix()的测试-------\n");
	if(SetTSMatrix(&M,arr,row,cols) && SetTSMatrix(&N,arr1,row,cols)){
		PrintTSMatrix(M);
		PrintTSMatrix(N);
	}

	printf("-----测试GetTSMatrix()--------\n");
	GetDataTSMatrix(M,4,1,&temp);
	printf("[4][1]=%d\n",temp);

	printf("-----测试CopyTSMatrix()--------\n");
	CopyTSMatrix(M,&T);
	PrintTSMatrix(T);
	GetDataTSMatrix(T,4,0,&temp);
	printf("[4][0]=%d\n",temp);
	
	printf("-----测试AddTSMatrix()--------\n");
	PrintTSMatrix(M);
	PrintTSMatrix(N);
	if(AddTSMatrix(M,N,&T))
		PrintTSMatrix(T);

	printf("-----测试SubTSMatrix()--------\n");
	PrintTSMatrix(M);
	PrintTSMatrix(N);
	if(SubTSMatrix(M,N,&T))
		PrintTSMatrix(T);
	
	printf("-----测试MultTSMatrix()--------\n");
	PrintTSMatrix(M);
	PrintTSMatrix(N);
	if(MultTSMatrix(M,N,&T))
		PrintTSMatrix(T);
	
	printf("-----测试TransposeTSMatrix()--------\n");
	PrintTSMatrix(M);
	PrintTSMatrix(N);
	if(TransposeTSMatrix(M,&T))
		PrintTSMatrix(T);
	
	
	
	
	return 0;
}
