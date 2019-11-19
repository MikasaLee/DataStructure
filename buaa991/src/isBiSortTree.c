/*************************************************************************
	> File Name: isBiSortTree.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 19 Nov 2019 10:58:32 PM CST
 ************************************************************************/

/**
 * 已知二叉树采用二叉链表存储结构，链节点构造为：lchild data rchild 根节点为T,
 * 请写一非递归算法，判断该二叉树是否为二叉排序树，若是二叉排序树，算法返回1，否则返回0
 */
// Unit_6下的ListBiTree将ElemType设置为char了，所以这里只是没有经过测试的代码
#include "stdio.h"

#define MAX 100			//这是栈容量的上限
#define MinData -1			//这是data的最小值
int isBiSortTree(BTREE T){
	BTREE Stack[MAX],p;
	top = -1;
	ElemType last = MinData;
	if(T == NULL) return 0;
	p = T;
	while(p || top != -1){
		if(p){
			if(last > p -> data) return 0;
			Stack[++top] = p;
			last = p -> data;
			p = p -> lchild;
		}else{
			p = Stack[top--];

			last = p -> data;
			p = p -> rchild;
		}
	}
	return 1;
}

