/*************************************************************************
	> File Name: BiThr.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sun 19 Aug 2018 11:13:28 AM CST
 ************************************************************************/
/**
 * 链式线索二叉树的头文件		
 */

#ifndef BITHR_H
#define BITHR_H

#include "../../Unit_1/src/myDefine.c"

#ifndef LISTElemType_Bt
#define LISTElemType_Bt
typedef char ListElemType_Thr;
#endif
typedef enum{Link,Thread} PointerTag; //Link=0,指针,Thread=1线索
typedef struct node{
	ListElemType_Thr data;						//数据域
	PointerTag ltag,rtag;				//左右标志域
	struct node *lchild,*rchild;		//左右指针域
}node,*Node;					//节点

typedef node thrTree;
typedef Node ThrTree;


//------------------基本操作-------------------------------
Status CreateBiTree_Thr(ThrTree *T,ListElemType_Thr *define,int i,int len);	//按长度为len的define构造二叉树T(按层序序列构造，无线索化)
void InTheading_Thr(ThrTree T);	//中序遍历时进行全线索化
Status InOrderThreading_Thr(ThrTree *Thead,ThrTree T);	//中序全线索化,得到中序遍历的二叉链表，头节点为Thead,左孩子指向根节点，右孩子指向中序遍历的最后一个节点。
Bool InOrderTraverse_Thr(ThrTree T,Bool Visit(Node));		//中序遍历中序全二叉树（非递归算法）
void PreThreading_Thr(ThrTree T); //先序全线索化
Status PreOrderThreading_Thr(ThrTree *Thead,ThrTree T);	//先序遍历时进行全线索化
Bool PreOrderTraverse_Thr(ThrTree Thead,Bool Visit(Node));		//先序遍历中序全二叉树（非递归算法）
void PostThreading_Thr(ThrTree T); //后序全线索化
Status PostOrderThreading_Thr(ThrTree *Thead,ThrTree T);	//后序遍历时进行全线索化
Bool PostOrderTraverse_Thr(ThrTree T,Bool Visit(Node));		//后序遍历中序全二叉树（非递归算法）

//--------------Visit()----------
Bool Visit(Node node); 
#endif
