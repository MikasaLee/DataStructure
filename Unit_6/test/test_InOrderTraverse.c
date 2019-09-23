/*************************************************************************
	> File Name: test_ListBiTree.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 02 Oct 2018 06:39:57 PM CST
 ************************************************************************/


#ifndef MAIN
#define MAIN

#include "../src/InOrderTraverse.c"

int main(int argc,char **argv){
	LBiTree T = NULL;
	ListElemType_Bt *e = "ABCDEF#G#HI#J";
	printf("\n----------测试CreateBiTree_L()------------\n");
	if(CreateBiTree_L(&T,e,0,13)){
		printf("\n----------测试InOrderTraverse_1()------------\n");
		InOrderTraverse_1(T,visitByChar);
		printf("\n----------测试InOrderTraverse_2()------------\n");
		InOrderTraverse_2(T,visitByChar);
	}
	
	return 0;
}

#endif
