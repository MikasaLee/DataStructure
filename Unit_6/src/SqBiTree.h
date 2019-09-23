/*************************************************************************
	> File Name: SqBiTree.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sun 19 Aug 2018 11:13:28 AM CST
 ************************************************************************/
/**
 * 二叉树的顺序存储的头文件
 *		按照顺序存储的定义，在此约定：用一组地址连续的存储单元依次自上而下、自左向右存储完全二叉树上的节点元素，
 *		即将完全二叉树上编号为i的节点元素存储在如上定义的依偎数组中下标为i-1的分量中，而对于一般的二叉树，则先
 *		每个结点与完全二叉树上的结点对应，然后存储到一维数组的相应分量中，不存在的节点用0\null表示。
 *
 *		对于完全二叉树甚至满二叉树而言，空间利用率高。但是对于一般的二叉树而言，空间利用率无法保证
 */

#ifndef SQBITREE_H
#define SQBITREE_H

#include "../../Unit_1/src/myDefine.c"

#ifndef SQELEMTYPE_BT
#define SQELEMTYPE_BT
typedef char SqElemType_Bt;
#endif

#define MAX_TREE_SIZE 100		//二叉树的最大节点数
typedef struct{
	SqElemType_Bt data;
}node,*Node;					//节点

typedef Node SqBiTree[MAX_TREE_SIZE];		//0号单元存放根节点，

//------------------基本操作-------------------------------
Status InitBiTree_Sq(SqBiTree T);		//构造空二叉树T
Status DestroyBiTree_Sq(SqBiTree T);	//销毁二叉树T
Status CreateBiTree_Sq(SqBiTree T,SqElemType_Bt *define,int len);	//按长度为len的define构造二叉树T
Node CreateNode_Sq(SqElemType_Bt data);			//得到一个Node，其值为data
Status ClearBiTree_Sq(SqBiTree T);		//清空二叉树T
Bool BiTreeEmpty_Sq(SqBiTree T);		//若T为空二叉树，返回TRUE；否则返回FALSE
int BiTreeDepth_Sq(SqBiTree T);		//返回二叉树T的深度
Node Root_Sq(SqBiTree T);				//返回二叉树T的根
SqElemType_Bt Value_Sq(SqBiTree T,Node n);	//返回二叉树T中n节点的data
Status Assign_Sq(SqBiTree T,Node n,SqElemType_Bt e);	//将二叉树中n节点的值设置为e
Node Parent_Sq(SqBiTree T,Node n);		//返回二叉树T中n节点的父节点
Node LeftChild_Sq(SqBiTree T,Node n);	//返回二叉树T中n节点的左孩子
Node RightChild_Sq(SqBiTree T,Node n);	//返回二叉树T中n节点的右孩子
Node LeftSibling_Sq(SqBiTree T,Node n);	//返回二叉树T中n节点的左兄弟
Node RightSibling_Sq(SqBiTree T,Node n);//返回二叉树T中n节点的右兄弟
Status PreOrderTraverse(SqBiTree T,Status Visit(Node node),int i);	//先序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。
Status InOrderTraverse(SqBiTree T,Status Visit(Node node),int i);	//中序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。
Status PostOrderTraverse(SqBiTree T,Status Visit(Node node),int i);	//后序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。
Status LevelOrderTraverse(SqBiTree T,Status Visit(Node node));	//层序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。

#endif
