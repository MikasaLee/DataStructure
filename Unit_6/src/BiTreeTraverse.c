/*************************************************************************
	> File Name: BiTreeTraverse.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sat 28 Sep 2019 10:43:20 PM CST
 ************************************************************************/

#ifndef BITREETRAVERSE_C
#define BITREETRAVERSE_C

#include "./BiTreeTraverse.h"

void PreOrder1(BiSortTree T,Bool Visit(Node node)){
	if(T){
		Visit(T);
		PreOrderTraverse1(T -> lchild,Visit);
		PreOrderTraverse1(T -> rchild,Visit);
	}
}

void InOrder1(BiSortTree T,Bool Visit(Node node)){	//中序
	if(T){
		InOrderTraverse1(T -> lchild,Visit);
		Visit(T);
		InOrderTraverse1(T -> rchild,Visit);
	}
}
void PostOrder1(BiSortTree T,Bool Visit(Node node)){	//后序
	if(T){
		PostOrderTraverse1(T -> lchild,Visit);
		PostOrderTraverse1(T -> rchild,Visit);
		Visit(T);
	}
}

void PreOrder2(BiSortTree T,Bool Visit(Node node));	//先序
void InOrder2(BiSortTree T,Bool Visit(Node node));	//中序
void PostOrder2(BiSortTree T,Bool Visit(Node node));	//后序
void LevelOrder2(BiSortTree T,Bool Visit(Node node));	//层序


#endif

