/*************************************************************************
	> File Name: test_TSparseMatrix.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 23 May 2018 06:19:09 PM CST
 ************************************************************************/

#include "../src/FastTransposeTSMatrix.c"

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

	printf("-----测试FastTransposeTSMatrix()--------\n");
	if(SetTSMatrix(&M,arr,row,cols)&&FastTransposeTSMatrix(M,&T))
		PrintTSMatrix(M);
		PrintTSMatrix(T);
	
	return 0;
}
