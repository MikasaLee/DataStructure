/*************************************************************************
	> File Name: hw_5_22.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sun 27 May 2018 08:31:54 PM CST
 ************************************************************************/

/**
 * 5.22假设稀疏矩阵A和B均以三元组顺序表作为存储结构。试写出满足以下条件的矩阵相加的算法：
 *		假设三元组顺序表A的空间足够大，将矩阵B加到矩阵A上，不增加A，B之外的附加空间，你的算法能否达到O(m+n)的时间复杂度？其中m和n分别为A，B矩阵中非零元的数目。
 */

#include "../src/TSparseMatrix.c"

Status hw_5_22(TSMatrix M,TSMatrix N){
	int i,j,k;
	int sum_m = M -> tu,sum_n = N -> tu;
	for(i = M -> tu;i>=1;i--)		//将M中每个元素后移N->tu
		 M ->data[i+N->tu] = M -> data[i];
	for(i = N -> tu+1,j = 1,k = 1;(i<= sum_m+sum_n)&&(j <= sum_n);){
		if(((M -> data[i] -> i) < (N -> data[j] -> i)) || 
				((M -> data[i] -> i == N -> data[j] -> i)&&(M ->data[i] -> j < N -> data[j] -> j)))
			M -> data[k++] = M -> data[i++];
		else if(((M -> data[i] -> i) == (N ->data[j] -> i)) &&((M -> data[i] -> j) == (N ->data[j] -> j))){
			if(M -> data[i] -> e + N ->data[j] -> e!=0){
				M -> data[k] = M -> data[i++];
				M ->data[k++] -> e +=N -> data[j++] -> e;
			}else{
				i++;j++;
			}
		}else 
		M -> data[k++] = N -> data[j++];
	}
	while(i<=sum_m+sum_n) M ->data[k++] = M ->data[i++];
	while(j<=sum_n) M ->data[k++] = N ->data[j++];
	
	M -> tu = k-1;

	return OK;
}

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

	
	if(SetTSMatrix(&M,arr,row,cols) && SetTSMatrix(&N,arr1,row,cols)){

		PrintTSMatrix(M);
		PrintTSMatrix(N);

		if(hw_5_22(M,N))
			PrintTSMatrix(M);
	}
	return 0;
}
