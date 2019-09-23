/*************************************************************************
	> File Name: SqBiTree.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 22 Aug 2018 05:59:09 PM CST
 ************************************************************************/

#ifndef SQBITREE_C
#define SQBITREE_C
#include "./SqBiTree.h"

Status InitBiTree_Sq(SqBiTree T){		//构造空二叉树T
	int i;
	for(i = 0;i<MAX_TREE_SIZE;i++){
		T[i] = NULL;
	}
	return OK;
}

Status DestroyBiTree_Sq(SqBiTree T){	//销毁二叉树T
	ClearBiTree_Sq(T);			//无法销毁，只能清空
	return OK;
}

Status CreateBiTree_Sq(SqBiTree T,SqElemType_Bt *define,int len){	//按defin构造二叉树T
	int i;
	if(InitBiTree_Sq(T)){
		for(i = 0;i < len;i++){
			if((T[0] == NULL) || (i != 0)&&(T[(i+1)/2-1]!=NULL))		//必须有父节点
				T[i] = CreateNode_Sq(define[i]);
			else if(i != 0){
				printf("CreateBiTree_Sq ERROR:第%d个节点没有父节点!\n",i+1);
				exit(OVERFLOW);
			}
		}
		return OK;
	}
	return ERROR;
}

Node CreateNode_Sq(SqElemType_Bt data){
	Node n = NULL;
	if((data!='#') && ((n = (Node)malloc(sizeof(node)))!=NULL)){	//用#表示null节点
		n -> data = data;
		return n;
	}
	return NULL;
}

Status ClearBiTree_Sq(SqBiTree T){		//清空二叉树T
	int i;
	for(i = 0;i<MAX_TREE_SIZE;i++){
		if(T[i]!=NULL){
			free(T[i]);
			T[i] = NULL;
		}
	}
	return OK;
}

Bool BiTreeEmpty_Sq(SqBiTree T){		//若T为空二叉树，返回TRUE；否则返回FALSE
	return T[0] == NULL?TRUE:FALSE;		//是否有root
}

int BiTreeDepth_Sq(SqBiTree T){		//返回二叉树T的深度
	int i,k;
	if(T[0] == NULL) return 0;
	for(i = k = 0;i<MAX_TREE_SIZE;i++){		//得到最后一个节点
		if(T[i] !=NULL) k = i;
	}
	++k;
	//公式：floor(log<sup>2</sup>(k))+1
	//log<sup>2</sup>(k))可以用C语言库函数log10+log结合换底公式实现，也可以自己实现一个。
	i = 0;
	while(k!=0){
		k/=2;
		i++;
	}
	return i;
}

Node Root_Sq(SqBiTree T){				//返回二叉树T的根
	return T[0];
}

int getPosByNode(SqBiTree T,Node n){
	int i;
	for(i = 0;i<MAX_TREE_SIZE;i++){
		if(n == T[i]) break;
	}
	return i;
}

SqElemType_Bt Value_Sq(SqBiTree T,Node n){	//返回二叉树T中n节点的data
	int i = getPosByNode(T,n);
	return i == MAX_TREE_SIZE?-1:T[i] -> data;
}
Status Assign_Sq(SqBiTree T,Node n,SqElemType_Bt e){	//将二叉树中n节点的值设置为e
	int i = getPosByNode(T,n);
	if(i == MAX_TREE_SIZE){
		return ERROR;
	}
	n -> data = e;
	return OK;
}
Node Parent_Sq(SqBiTree T,Node n){		//返回二叉树T中n节点的父节点
	int i = getPosByNode(T,n);
	if((i == MAX_TREE_SIZE) || (i == 0)){
		return NULL;
	}
	return T[(i+1)/2-1];
}
Node LeftChild_Sq(SqBiTree T,Node n){	//返回二叉树T中n节点的左孩子
	int i = getPosByNode(T,n);
	i = (i+1)*2-1;
	if(i >= MAX_TREE_SIZE){
		return NULL;
	}
	return T[i];
}
Node RightChild_Sq(SqBiTree T,Node n){	//返回二叉树T中n节点的右孩子
	int i = getPosByNode(T,n);
	i = (i+1)*2;
	if(i >= MAX_TREE_SIZE){
		return NULL;
	}
	return T[i];
}
Node LeftSibling_Sq(SqBiTree T,Node n){	//返回二叉树T中n节点的左兄弟
	int i = getPosByNode(T,n);
	if((i != 0) && (i % 2 == 0) && (i < MAX_TREE_SIZE)){
		return T[i-1];
	}
	return NULL;
}
Node RightSibling_Sq(SqBiTree T,Node n){//返回二叉树T中n节点的右兄弟
	int i = getPosByNode(T,n);
	if((i != 0) && (i % 2 == 1) && (i < MAX_TREE_SIZE)){
		return T[i+1];
	}
	return NULL;
}
Status PreOrderTraverse(SqBiTree T,Status Visit(Node node),int i){	//先序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。
	if(i >= MAX_TREE_SIZE) return ERROR;
	if(T[i] != NULL){
		if(!Visit(T[i])) return FALSE;
		PreOrderTraverse(T,Visit,2*(i+1)-1);
		PreOrderTraverse(T,Visit,2*(i+1));
	}
	return OK;
}
Status InOrderTraverse(SqBiTree T,Status Visit(Node node),int i){	//中序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。
	if(i >= MAX_TREE_SIZE) return ERROR;
	if(T[i] != NULL){
		InOrderTraverse(T,Visit,2*(i+1)-1);
		if(!Visit(T[i])) return FALSE;
		InOrderTraverse(T,Visit,2*(i+1));
	}
	return OK;
}
Status PostOrderTraverse(SqBiTree T,Status Visit(Node node),int i){	//后序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。
	if(i >= MAX_TREE_SIZE) return ERROR;
	if(T[i] != NULL){
		PostOrderTraverse(T,Visit,2*(i+1)-1);
		PostOrderTraverse(T,Visit,2*(i+1));
		if(!Visit(T[i])) return FALSE;
	}
	return OK;
}

Status LevelOrderTraverse(SqBiTree T,Status Visit(Node node)){	//层序遍历二叉树T，对每一个节点调用visit()函数，若有一个调用失败返回false。
	int i,k;
	if(T[0] == NULL) return 0;
	for(i = k = 0;i<MAX_TREE_SIZE;i++){		//得到最后一个节点
		if(T[i] !=NULL) k = i;
	}

	for(i = 0;i<=k;i++){
		if((T[i]!=NULL)&&(!Visit(T[i]))) return FALSE;
	}
	return OK;
}

Status visitByChar(Node node){
	if(node == NULL) printf("NULL");
	else printf("%c",node -> data);
	return OK;
}

#endif
