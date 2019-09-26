/*************************************************************************
	> File Name: BiSortTree.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 23 Sep 2019 07:45:01 PM CST
 ************************************************************************/

/**
 * 二叉排序树(Binary Sort Tree)的链式实现,版本2 
 *		考试的时候程序题不会给我这么多时间和空间让我把工具都准备好（也就是有很多基础函数）
 *		再实现插入删除查找功能的，所以版本2没有其他方法，只有创建查找插入删除
 *		其中要求用递归和非递归的也要都写	
 */

#ifndef BISORTTREE2_H
#define BISORTTREE2_H

#include "../../Unit_1/src/myDefine.c"


#ifndef BISORTELEMTYPE
#define BISORTELEMTYPE

typedef int BiSortElemType;		//以后就算是char也用int类型 ,<The C Programming Language> 中强烈推荐！

#endif

typedef struct node{
	BiSortElemType	data;			//数据
	struct node *lchild,*rchild;		//左右孩子指针
}node,*Node;

typedef node biSortTree;
typedef Node BiSortTree;


//--------------------基本操作----------------------------------------
Status CreateBiSortTree(BiSortTree *T , BiSortElemType datas[] , int len);	//按长度为len的define构造二叉排序树T(逐点插入法,关键是InsertNode函数)

//三个主要的问题：插入/删除/查找一个节点
Bool InsertBiSortNode(BiSortTree *T,BiSortElemType e);	//插入一个节点,递归算法

Bool InsertBiSortNode2(BiSortTree *T,BiSortElemType e);	//插入一个节点，非递归算法

Bool DeleteBiSortNode(BiSortTree *T,BiSortElemType e);	//删除一个节点
Node SearchBiSortNode(BiSortTree T,BiSortElemType e);	//查找一个节点,递归算法
Node SearchBiSortNode2(BiSortTree T,BiSortElemType e);	//查找一个节点，非递归算法

Status InOrderTraverse(BiSortTree T,Bool Visit(Node node));	//遍历有一个中序遍历就够了

//-------------Visit()----------------------------
Bool Visit(Node node);
#endif
