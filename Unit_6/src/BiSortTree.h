/*************************************************************************
	> File Name: BiSortTree.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 23 Sep 2019 07:45:01 PM CST
 ************************************************************************/

/**
 * 二叉排序树(Binary Sort Tree)的链式实现
 *		性质：1 若根节点的左子树不为null，则左子树上所有节点的值都小于根节点的值
 *			  2	若根节点的右子树不为null，则右子树的所有节点的值都大于等于根节点的值
 *			  3 每一棵子树也分别是二叉排序树
 *
 *		重点是建立(逐点插入法)，删除/查找一个节点
 * 
 * (ps:二叉排序树严蔚敏老师的书上没涉及，但是唐发根老师的书提到了，并且也是991考纲的要求)
 */

#ifndef BISORTTREE_H
#define BISORTTREE_H

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
Status InitBiSortTree(BiSortTree *T);		//构造空二叉排序树
Status DestroyBiSortTree(BiSortTree *T);	//销毁二叉排序树T
Status CreateBiSortTree(BiSortTree *T , BiSortElemType datas[] , int len);	//按长度为len的define构造二叉排序树T(逐点插入法,关键是InsertNode函数)
Node CreateNode(BiSortElemType data);			//创建一个Node，其值为data
Bool BiSortTreeEmpty(BiSortTree T);		//若T为空二叉排序树，返回TRUE；否则返回FALSE
int BiSortTreeDepth(BiSortTree T);		//返回二叉排序树T的深度
Node Root(BiSortTree T);				//返回二叉排序树T的根
BiSortElemType Value(Node n);	//返回二叉排序树T中n节点的data
Node Parent(BiSortTree T,Node p);	//得到p节点的父节点

//三个主要的问题：插入/删除/查找一个节点
Bool InsertBiSortNode(BiSortTree root,BiSortElemType e);	//插入一个节点,递归算法

Bool InsertBiSortNode2(BiSortTree root,BiSortElemType e);	//插入一个节点，非递归算法

Bool DeleteBiSortNode(BiSortTree root,BiSortElemType e);	//删除一个节点
Node SearchBiSortNode(BiSortTree root,BiSortElemType e);	//查找一个节点

Status InOrderTraverse(BiSortTree T,Bool Visit(Node node));	//遍历有一个中序遍历就够了

//-------------Visit()----------------------------
Bool Visit(Node node);
#endif
