/*************************************************************************
	> File Name: test_BiSortTree.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 25 Sep 2019 08:42:24 PM CST
 ************************************************************************/

#ifndef MAIN
#define MAIN

#include "../src/BiSortTree.c"

int main(int argc,char **argv){
	BiSortTree T = NULL;
	//BiSortElemType datas[] = { 23,43,123,34,123,534,67,23,423,45,62,5,62,6,3,4,6 };
	BiSortElemType datas[] = { 50,35,70,40,50,65,20,80 };

	printf("\n----------测试CreateBiSortTree(),其中包括InSertBiSortNode()------------\n");
	if(CreateBiSortTree(&T,datas,8)){
		printf("\n----------测试InOrderTracerse()------------\n");
		InOrderTraverse(T,Visit);
		printf("\n----------测试DeleteBiSortNode(),其中包括SearchBiSortNode()------------\n");
		BiSortElemType data;
	
		printf("要删除的元素是:");
		scanf("%d",&data);
		DeleteBiSortNode(T,data);
	
	}




	return 0;
}
#endif
