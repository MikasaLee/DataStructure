/*************************************************************************
	> File Name: ListBiTree.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Fri 28 Sep 2018 04:43:04 PM CST
 ************************************************************************/
/**
 * 二叉树的链式存储的实现
 */


#ifndef LISTBITREE_C
#define LISTBITREE_C

#include "math.h"
#include "./ListBiTree.h"

Status InitBiTree_L(LBiTree *T){		//构造空二叉树T
	if(*T) free(*T);
	if(!((*T) = (LBiTree)malloc(sizeof(node)))) exit(OVERFLOW);
	(*T) -> lchild = (*T) -> rchild = NULL;
	return OK;
}

Status DestroyBiTree_L(LBiTree *T){	//销毁二叉树T
	Node p = *T;
	if(!(*T)) return OK;
	DestroyBiTree_L(&(p -> lchild));
	DestroyBiTree_L(&(p -> rchild));
	free(*T);
	(*T) = NULL;
	return OK;
}

Status CreateBiTree_L(LBiTree *T,ListElemType_Bt *define,int i,int len){
	Node p;
	if(*T) free(*T);
	(*T) = NULL;
	if((i < len) && ((*T = CreateNode_L(define[i]))!= NULL)){
		p = *T;
		CreateBiTree_L(&(p -> lchild),define,(i+1)*2-1,len);
		CreateBiTree_L(&(p -> rchild),define,(i+1)*2,len);
	}
	return OK;
}

Node CreateNode_L(ListElemType_Bt data){			//创建一个Node，其值为data;
	Node p = NULL;
	if(data != '#'){
		p = (Node)malloc(sizeof(node));
		p -> data = data;
		p -> lchild = p -> rchild = NULL;
	}
	return p;
}

Bool BiTreeEmpty_L(LBiTree T){		//若T为空二叉树，返回TRUE；否则返回FALSE
	return T == NULL?TRUE:FALSE;
}

int BiTreeDepth_L(LBiTree T){		//返回二叉树T的深度
	int left,right;
	left = right = 0;
	if(!T) return 0;
	if(T -> lchild) left = BiTreeDepth_L(T -> lchild);
	if(T -> rchild) right = BiTreeDepth_L(T -> rchild);
	return (left > right?left:right)+1 ;
}

Node Root_L(LBiTree T){				//返回二叉树T的根
	if(!T){
		printf("\nfunction Root_L:no root!\n");
		return NULL;
	}
	return T;
}

ListElemType_Bt Value_L(Node n){	//返回n节点的data
	return n -> data;
}
Status Assign_L(Node n,ListElemType_Bt e){	//将二叉树中n节点的值设置为e
	n -> data = e ;
	return OK;
}
Node Parent_L(LBiTree T,Node n){		//返回二叉树T中n节点的父节点
	Node parent;
	if(!T) return NULL;

	if((T -> lchild == n) || (T -> rchild == n)) return T;
	if((parent = Parent_L(T -> lchild,n))!= NULL) return parent;
	if((parent = Parent_L(T -> rchild,n))!= NULL) return parent;
	return NULL;
}

Node LeftChild_L(Node n){	//返回二叉树T中n节点的左孩子
	if(!n){
		printf("\nfunction LeftChild_L:this node is not exist!\n");
		return NULL;
	}
	return n ->lchild;
}
Node RightChild_L(Node n){	//返回二叉树T中n节点的右孩子
	if(!n){
		printf("\nfunction RightChild_L:this node is not exist!\n");
		return NULL;
	}
	return n ->rchild;
}

Node LeftSibling_L(LBiTree T,Node n){	//返回二叉树T中n节点的左兄弟
	Node parent = Parent_L(T,n);
	if(!parent){
		printf("\nfunction LeftSibling_L:this node is not exist!\n");
		return NULL;
	}
	if(parent -> rchild == n) return parent -> lchild;
	return NULL;
	
}
Node RightSibling_L(LBiTree T,Node n){	//返回二叉树T中n节点的右兄弟
	Node parent = Parent_L(T,n);
	if(!parent){
		printf("\nfunction RightSibling_L:this node is not exist!\n");
		return NULL;
	}
	if(parent -> lchild == n) return parent -> rchild;
	return NULL;
}

Bool PreOrderTraverse(LBiTree T,Bool Visit(Node node)){	//先序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。
	Bool flag = TRUE;
	if(!T) return ERROR;
	
	if(!Visit(T)) flag = FALSE;
	if(T -> lchild != NULL) PreOrderTraverse(T -> lchild,Visit);
	if(T -> rchild != NULL) PreOrderTraverse(T -> rchild,Visit);
	
	return flag;
}
Bool InOrderTraverse(LBiTree T,Status Visit(Node node)){	//中序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。
	Bool flag = TRUE;
	if(!T) return ERROR;

	if(T -> lchild != NULL) InOrderTraverse(T -> lchild,Visit);
	if(!Visit(T)) flag = FALSE;
	if(T -> rchild != NULL) InOrderTraverse(T -> rchild,Visit);
	
	return flag;
}
Bool PostOrderTraverse(LBiTree T,Status Visit(Node node)){	//后序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。
	Bool flag = TRUE;
	if(!T) return ERROR;

	if(T -> lchild != NULL) PostOrderTraverse(T -> lchild,Visit);
	if(T -> rchild != NULL) PostOrderTraverse(T -> rchild,Visit);
	if(!Visit(T)) flag = FALSE;

	return flag;
}	

Bool LevelOrderTraverse(LBiTree T,Status Visit(Node node)){	//层序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。
	if(!T) return ERROR;
	int size,i,j; //size = 2<sup>depth</sup>-1;
	Node *capacity,p = T;
	Bool flag = TRUE;
	size = pow(2,BiTreeDepth_L(T));
	if(!(capacity = (Node *)malloc(sizeof(Node)*size))) exit(OVERFLOW);
	i = j = 0;
	capacity[j++] = T;
	while(i < j){
		if(Visit(capacity[i]) == FALSE) flag = FALSE;;
		if(capacity[i] -> lchild) capacity[j++] = capacity[i] -> lchild;
		if(capacity[i] -> rchild) capacity[j++] = capacity[i] -> rchild;
		i++;
	}

	return flag;
}

Bool visitByChar(Node node){
	if(node == NULL) printf("NULL");
	else printf("%c",node -> data);
	return TRUE;
}
#endif
