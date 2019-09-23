/*************************************************************************
	> File Name: BiSortTree.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 23 Sep 2019 08:24:32 PM CST
 ************************************************************************/

#ifndef BISORTTREE_C
#define BISORTTREE_C

#include "../BiSortTree.h"

Status InitBiSortTree(BiSortTree *T){		//构造空二叉排序树
	if(*T){
		free(*T)
		(*T) = NULL;
	}
	if(!((*T) = (BiSortTree)malloc(sizeof(biSortTree)))) exit(OVERFLOW);
	(*T) -> lchild = (*T) -> rchild = NULL;
	(*T) -> data = -1;				//初始-1
	return OK;
}

Status DestroyBiSortTree(BiSortTree *T){ //销毁二叉排序树T
	Node p = *T;
	if(!p) return OK;
	DestroyBiSortTree(&(p -> lchild));
	DestroyBiSortTree(&(p -> rchild));
	free(p);
	(*T) = NULL;
	return OK;

}

Status CreateBiSortTree(BiSortTree *T,BiSortElemType []define,int i,int len){	//按长度为len的define构造二叉排序树T(逐点插入法,关键是InsertNode函数)
	Node p;
	Bool flag = TRUE;
	if(InitBiSortTree(T)){
		p = *T;
		p -> data = define[0];
	}
	for(int i =1;i<len;i++){
		InsertBiSortNode(p,define[i]);			//插入一个节点
		if(!InsertBiSortNode(p,define[i])){	
			printf("\nERROR: InsertBiSortNode(p,%d) faild",define[i]);
			flag = FALSE;
		}
	}
	return flag == TRUE? OK : ERROR;
}


Node CreateNode(BiSortElemType data){			//创建一个Node，其值为data
	Node p = NULL;
	if(!(p = (Node)malloc(sizeof(node)))) exit(OVERFLOW);
	p ->lchild = p -> rchild = NULL;
	p -> data = data;
	return p;
}


Bool BiSortTreeEmpty(BiSortTree T){		//若T为空二叉排序树，返回TRUE；否则返回FALSE
	return T == NULL? TRUE:FALSE;
}

int BiSortTreeDepth(BiSortTree T){		//返回二叉排序树T的深度
	int ldepth,rdepth;
	ldepth = rdepth = 0;
	if(!T) return 0;
	
	ldepth = BiSortTreeDepth(T->lchild);
	rdepth = BiSortTreeDepth(T->rchild);
	
	return (left > right?left:right)+1;
}
BiSortElemType Value(Node n){			//返回二叉排序树T中n节点的data
	return n -> data;
}

//三个主要的问题：插入/删除/查找一个节点
Status InsertBiSortNode(BiSortTree root,BiSortElemType e);	//插入一个节点
Status DeleteBiSortNode(BiSortTree root,BiSortElemType e);	//删除一个节点
Node SearchBiSortNode(BiSortTree root,BiSortElemType e);	//查找一个节点

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
