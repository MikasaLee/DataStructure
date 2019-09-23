/*************************************************************************
	> File Name: InOrderTraverse.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 03 Oct 2018 05:53:46 PM CST
 ************************************************************************/

/**
 * 课本算法6.2 ，6.3 ：利用栈来实现二叉树的非递归前序遍历(算法6.1是利用递归实现的，也是ListBiTree.c文件中的实现方法，所以就不再重复了)
 */

#ifndef INORDERTRAVERSE_H
#define INORDERTRAVERSE_H

#include "ListBiTree.c"
typedef Node ElemType;
#include "../../Unit_3/src/SqStack.c"		//引入栈

Status InOrderTraverse_1(LBiTree T,Bool Visit(Node node));	//算法6.2
Status InOrderTraverse_2(LBiTree T,Bool Visit(Node node));	//算法6.3

#endif
