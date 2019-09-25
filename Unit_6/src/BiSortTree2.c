/*************************************************************************
	> File Name: BiSortTree.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 23 Sep 2019 08:24:32 PM CST
 ************************************************************************/

#ifndef BISORTTREE2_C
#define BISORTTREE2_C

#include "./BiSortTree2.h"

Status CreateBiSortTree(BiSortTree *T,BiSortElemType datas[],int len){	//按长度为len的define构造二叉排序树T(逐点插入法,关键是InsertNode函数)
	int i;
	for(i = 0;i<len;i++){
		//InsertBiSortNode(T,datas[i]);
		InsertBiSortNode2(T,datas[i]);
	}
	return OK;

}

//三个主要的问题：插入/删除/查找一个节点
Status InsertBiSortNode(BiSortTree *T,BiSortElemType e){	//插入一个节点,递归实现
	Node p = NULL;
	if(*T == NULL){
		p = (Node)malloc(sizeof(node));
		p -> rchild = p -> lchild = NULL;
		p -> data = e;
		(*T) = p;
	}else{
		if( e < (*T) ->data) InsertBiSortNode(&((*T) -> lchild),e);
		else InsertBiSortNode(&((*T) -> rchild),e);
	}
	return OK;
}

Status InsertBiSortNode2(BiSortTree *T,BiSortElemType e){	//插入一个节点,非递归实现
	Node p = NULL,t,parent;
	p = (Node)malloc(sizeof(node));
	p -> rchild = p -> lchild = NULL;
	p -> data = e;

	if(*T == NULL)	(*T) = p;
	else{
		t = parent = (*T);
		while(t){
			parent = t;
			t = p -> data  < t -> data?t -> lchild:t -> rchild;
		}
		if(p -> data < parent -> data) parent -> lchild = p;
		else parent -> rchild = p;
	}
	return OK;
}

/**
 * 删除节点 
 *		如果删除的是叶子节点，那不需要移动其他节点
 *		但是如果删除的是非叶子节点，则需要将左子树中最大的节点或者右子树中最小的节点代替
 *		规定：先找左子树中最大的节点，如果没有就找右子树中最小的节点
 */
Status DeleteBiSortNode(BiSortTree *T,BiSortElemType e){	//删除一个节点
}


Node SearchBiSortNode(BiSortTree root,BiSortElemType e){	//查找一个节点
	Node p = NULL;
	if(root == NULL) return NULL;
	if(root -> data == e) return root;
	
	if(root -> data > e) p = SearchBiSortNode(root -> lchild,e);
	else p = SearchBiSortNode(root -> rchild,e);
	
	return p;
}


Status InOrderTraverse(BiSortTree T,Bool Visit(Node node)){ //遍历有一个中序遍历就够了
	if(T){
		InOrderTraverse(T->lchild,Visit);
		Visit(T);
		InOrderTraverse(T->rchild,Visit);
	}
	return OK;
}

//-------------Visit()----------------------------
Bool Visit(Node node){
	if(node == NULL) printf("NULL! ");
	else printf("%d ",node -> data);
	return TRUE;
}




#endif
