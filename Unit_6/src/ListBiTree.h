/*************************************************************************
	> File Name: ListBiTree.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sun 19 Aug 2018 11:13:28 AM CST
 ************************************************************************/
/**
 * 二叉树的链式存储的头文件		
 */

#ifndef LISTBITREE_H
#define LISTBITREE_H

#include "../../Unit_1/src/myDefine.c"

#ifndef LISTElemType_Bt
#define LISTElemType_Bt
typedef char ListElemType_Bt;
#endif

typedef struct node{
	ListElemType_Bt data;						//数据域
	struct node *lchild,*rchild;		//左右孩子指针
}node,*Node;					//节点

typedef node lBiTree;
typedef Node LBiTree;


//------------------基本操作-------------------------------
Status InitBiTree_L(LBiTree *T);		//构造空二叉树T
Status DestroyBiTree_L(LBiTree *T);	//销毁二叉树T
Status CreateBiTree_L(LBiTree *T,ListElemType_Bt *define,int i,int len);	//按长度为len的define构造二叉树T(按层序序列构造)
Node CreateNode_L(ListElemType_Bt data);			//创建一个Node，其值为data
Bool BiTreeEmpty_L(LBiTree T);		//若T为空二叉树，返回TRUE；否则返回FALSE
int BiTreeDepth_L(LBiTree T);		//返回二叉树T的深度
Node Root_L(LBiTree T);				//返回二叉树T的根
ListElemType_Bt Value_L(Node n);	//返回二叉树T中n节点的data
Status Assign_L(Node n,ListElemType_Bt e);	//将二叉树中n节点的值设置为e
Node Parent_L(LBiTree T,Node n);		//返回二叉树T中n节点的父节点
Node LeftChild_L(Node n);	//返回二叉树T中n节点的左孩子
Node RightChild_L(Node n);	//返回二叉树T中n节点的右孩子
Node LeftSibling_L(LBiTree T,Node n);	//返回二叉树T中n节点的左兄弟
Node RightSibling_L(LBiTree T,Node n);//返回二叉树T中n节点的右兄弟
Status PreOrderTraverse(LBiTree T,Bool Visit(Node node));	//先序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。
Status InOrderTraverse(LBiTree T,Bool Visit(Node node));	//中序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。
Status PostOrderTraverse(LBiTree T,Bool Visit(Node node));	//后序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。
Status LevelOrderTraverse(LBiTree T,Bool Visit(Node node));	//层序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。

//--------------Visit()----------
Bool Visit(Node node); 
#endif
