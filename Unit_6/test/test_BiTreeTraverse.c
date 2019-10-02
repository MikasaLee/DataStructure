/*************************************************************************
	> File Name: test_BiSortTree.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 25 Sep 2019 08:42:24 PM CST
 ************************************************************************/

#ifndef MAIN
#define MAIN

#include "../src/BiTreeTraverse.c"

int main(int argc,char **argv){
	BiSortTree T = NULL;
	//BiSortElemType datas[] = { 23,43,123,34,123,534,67,23,423,45,62,5,62,6,3,4,6 };
	BiSortElemType data,datas[] = { 50,35,70,40,50,65,20,80 };

	printf("\n----------测试CreateBiSortTree(),其中包括InSertBiSortNode()------------\n");
	if(CreateBiSortTree(&T,datas,8)){
		printf("\n----------测试PreOrder()------------\n");
		PreOrder1(T,Visit);
		printf("\n");
		PreOrder2(T,Visit);
		printf("\n----------测试InOrder()------------\n");
		InOrder1(T,Visit);
		printf("\n");
		InOrder2(T,Visit);
		printf("\n----------测试PostOrder()------------\n");
		PostOrder1(T,Visit);
		printf("\n");
		PostOrder2(T,Visit);
		printf("\n----------测试LevelOrder()------------\n");
		LevelOrder2(T,Visit);
		printf("\n");
	}

	return 0;
}
#endif
