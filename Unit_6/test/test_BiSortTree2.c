/*************************************************************************
	> File Name: test_BiSortTree.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 25 Sep 2019 08:42:24 PM CST
 ************************************************************************/

#ifndef MAIN
#define MAIN

#include "../src/BiSortTree2.c"

int main(int argc,char **argv){
	BiSortTree T = NULL;
	//BiSortElemType datas[] = { 23,43,123,34,123,534,67,23,423,45,62,5,62,6,3,4,6 };
	BiSortElemType data,datas[] = { 50,35,70,40,50,65,20,80 };

	printf("\n----------测试CreateBiSortTree(),其中包括InSertBiSortNode()------------\n");
	if(CreateBiSortTree(&T,datas,8)){
		printf("\n----------测试InOrderTracerse()------------\n");
		InOrderTraverse(T,Visit);
		/**
		printf("\n----------测试SearchBiSortNode() and SearchBiSortNode2()------------\n");
		printf("要查找的元素是:");
		scanf("%d",&data);
		printf("result:\n\tSearchBiSortNode:%d\n\tSearchBiSortNode2:%d\n",SearchBiSortNode(T,data) -> data,SearchBiSortNode2(T,data) -> data);			//如果没有此元素则返回null节点，所以会报指针非法访问，这是正确的结果
**/
		printf("\n----------测试DeleteBiSortNode()------------\n");
	
		printf("要删除的元素是:");
		scanf("%d",&data);
		DeleteBiSortNode(&T,data);
		InOrderTraverse(T,Visit);
	}

	return 0;
}
#endif
