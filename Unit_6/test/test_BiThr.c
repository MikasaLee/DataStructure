/*************************************************************************
	> File Name: test_ListBiTree.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 02 Oct 2018 06:39:57 PM CST
 ************************************************************************/


#ifndef MAIN
#define MAIN

#include "../src/BiThr.c"

int main(int argc,char **argv){
	ThrTree T = NULL,Thead;
	ListElemType_Thr *e = "ABCDEF#G#HI#J";
	if(CreateBiTree_Thr(&T,e,0,13)){
		printf("\n----------测试InOrderTraverse_Thr()------------\n");
		InOrderThreading_Thr(&Thead,T);
		InOrderTraverse_Thr(Thead,visitByChar);
		printf("\n----------测试PreOrderTraverse_Thr()------------\n");
		PreOrderThreading_Thr(&Thead,T);
		PreOrderTraverse_Thr(Thead,visitByChar);
	}	
	return 0;
}

#endif
