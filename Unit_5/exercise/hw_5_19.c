/*************************************************************************
	> File Name: hw_5_19.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sun 27 May 2018 07:07:07 PM CST
 ************************************************************************/

/**
 * 5.19❹若矩阵Am×n中的某个元素aij是第i行中的最小值，同时又是第j列中的最大值，则称此元素为该矩阵中的一个马鞍点。假设二维数组存储矩阵Am×n，试编写求出矩阵中所有马鞍点的算法，并分析你的算法在最坏情况下的时间复杂度。
 */

#include "../../Unit_1/src/myDefine.c"

#ifndef ELEMTYPE
#define ELEMTYPE
typedef int ElemType;
#endif
#include "../../Unit_2/src/LinkList.c"		//链表


void hw_5_19(ElemType arr[][4],int row,int cols){
	LinkList minEachRow[row];					//minEachRow[i]表示第i行最小值的下标,有可能每一行有多个最小值，所以需要链表
	LinkList maxEachCols[cols];		//同上
	int i,j,k;
	for(i = 0;i<row;i++){
		if(!InitList_L(&minEachRow[i])) exit(OVERFLOW);
		k = 0;
		for(j = 0;j<cols;j++){
			if(arr[i][j] < arr[i][k]){
				k = j;
				DestroyList_L(&(minEachRow[i]));
				InitList_L(&(minEachRow[i]));
				ListInsert_L(minEachRow[i],ListLength_L(minEachRow[i])+1,k);
			}else if(arr[i][j] == arr[i][k]){
				k = j;
				ListInsert_L(minEachRow[i],ListLength_L(minEachRow[i])+1,k);
			}
		}
	}

	for(j = 0;j<cols;j++){
		if(!InitList_L(&maxEachCols[j])) exit(OVERFLOW);
		k = 0;
		for(i = 0;i<row;i++){
			if(arr[i][j] > arr[k][j]){
				k = i;
				DestroyList_L(&(maxEachCols[j]));
				InitList_L(&(maxEachCols[j]));
				ListInsert_L(maxEachCols[j],ListLength_L(maxEachCols[j])+1,k);
			}else if(arr[i][j] == arr[k][j]){
				k = i;
				ListInsert_L(maxEachCols[j],ListLength_L(maxEachCols[j])+1,k);
			}
		}
	}
	
	for(i = 0;i<row;i++){
		for(j = 0;j<cols;j++){
			if((LocateElem_L(maxEachCols[j],i,equals)!=0) && ((LocateElem_L(minEachRow[i],j,equals))!=0))
				printf("[%d][%d]是一个马鞍点\n",i,j);
		}
	}
	return;
}

int main(int argc,char **argv){
	ElemType arr[][4]={
		{1,2,1,4},
		{-1,6,-5,2},
		{-2,7,0,1},
		{1,2,1,3}};
	hw_5_19(arr,4,4);

	return 0;
}
