/*************************************************************************
	> File Name: BiTreeTraverse.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sat 28 Sep 2019 10:32:31 PM CST
 ************************************************************************/

/**
 * 二叉树的遍历: 
 *		包括 前序 中序 后序 层序 这四种的递归与非递归的算法(层序只有非递归) 后缀是1表示递归 2为非递归
 *		借用版本2的二叉排序树为例（因为这个工具少，更加贴近考试）
 */

#ifndef BITREETRAVERSE_H
#define BITREETRAVERSE_H

#include "./BiSortTree2.c"		//版本2的二叉排序树

Status PreOrderTraverse1(BiSortTree T,Bool Visit(Node node));	//先序
Status InOrderTraverse1(BiSortTree T,Bool Visit(Node node));	//中序
Status PostOrderTraverse1(BiSortTree T,Bool Visit(Node node));	//后序


Status PreOrderTraverse2(BiSortTree T,Bool Visit(Node node));	//先序
Status InOrderTraverse2(BiSortTree T,Bool Visit(Node node));	//中序
Status PostOrderTraverse2(BiSortTree T,Bool Visit(Node node));	//后序
Status LevelOrderTraverse2(BiSortTree T,Bool Visit(Node node));	//层序

#endif
