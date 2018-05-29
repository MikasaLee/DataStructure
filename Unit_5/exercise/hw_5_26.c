/*************************************************************************
	> File Name: hw_5_26.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 29 May 2018 06:11:01 PM CST
 ************************************************************************/

/**
 * 5.26 试编写一个以三元组形式输出用十字链表表示的稀疏矩阵中非零元素及其下标的算法。
 */

#include "../src/CLinkMatrix.c"
void PrintMatrix_5_26(CLMatrix M){
	int curor;
	CLink ptr;
	if(!M){
		printf("该稀疏矩阵不存在!\n");
		return;
	}
	printf("稀疏矩阵的行数，列数：%d,%d\n",M -> mu,M -> nu);
	printf("稀疏矩阵的非零元个数：%d\n",M -> tu);
	printf("-------------------------------\n");
	for(curor = 0;curor < M -> mu;curor++){
		for(ptr = M -> rhead[curor];ptr;ptr = ptr -> right)
			printf("(%d,%d,%d)\n",ptr->i,ptr->j,ptr->e);
	}
	printf("-------------------------------\n");
	return;
}

int main(int argc,char **argv){
	CLMatrix M;
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

	if(SetCLMatrix(&M,arr,row,cols))
		PrintMatrix_5_26(M);
	return 0;
}
