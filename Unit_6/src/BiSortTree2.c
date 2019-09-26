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
 *		PS：1.这是数据结构上的删除算法思想，它将孩子是否为1或2也讨论，我自己实现的二叉排序树中只需考虑有没有孩子节点，两种删除后都不会影响二叉排序树的性质，也就是说删除后还是二叉排序树，但是树的结构不一样 
 *			2. 这里只以书上的为准，另一种思路在第一个版本的二叉排序树中已经实现了，这里就不再写了
 *			3. 991考试大纲中 删除操作应该不会要求代码实现，只需要了解删除操作即可
 *-----------------------------------------------------------------------------------------

 *		原则：1 被删除节点为叶节点，则直接删除
 *			  2 被删除节点无左子树，则用右子树的根节点取代被删除节点
 *			  3 被删除节点无右子树，则用左子树的根节点取代被删除节点
 *			  4 被删除节点的左右子树都存在，则用被删除节点的右子树中值最小的节点（或被删除节点的左子树中值最大的节点）取代被删除节点
 *
 *
 */
Status DeleteBiSortNode(BiSortTree *T,BiSortElemType e){	//删除一个节点,只有递归实现
	Node p,t,parent;
	if(*T == NULL) return ERROR;
	else if((*T) -> data == e){			//删根节点
		p = (*T);
		if((*T) -> lchild == NULL) (*T) = (*T) -> rchild;		//情况1 2
		else if((*T) -> rchild == NULL) (*T) = (*T) -> lchild;	//情况3
		else{													//情况4
			//得到右子树中最小的
			parent = (*T);
			t = parent -> rchild;
			while(t -> lchild != NULL) {parent = t;t = t -> lchild;}
			
			(*T) -> data = t -> data;		
			p = t;
			if(parent != (*T)) parent -> lchild = t -> rchild;
			else parent -> rchild = t -> rchild;
		}
		free(p);
	}
	else{						
		//本来是想的只有非递归实现，但是非递归实现的话此else和删除根节点的思路完全一样，代码几乎完全一样，所以还是复用一下上面的写成递归实现了
		// 如果想要非递归实现那就是把上面删根节点的代码完全复制下来然后小修一下就行了
		p = *T;
		if(e < p -> data) return DeleteBiSortNode(&(p -> lchild),e);
		else return DeleteBiSortNode(&(p -> rchild),e);	
	}
	return OK;
}


Node SearchBiSortNode(BiSortTree root,BiSortElemType e){	//查找一个节点,递归实现
	Node p = NULL;
	if(root == NULL) return NULL;
	if(root -> data == e) return root;
	
	if(e < root -> data) p = SearchBiSortNode(root -> lchild,e);
	else p = SearchBiSortNode(root -> rchild,e);
	
	return p;
}

Node SearchBiSortNode2(BiSortTree root,BiSortElemType e){	//查找一个节点,非递归实现
	Node p = root;
	while(p && (p -> data != e)) p = e < p -> data ? p -> lchild: p -> rchild;		
	
	return p ;
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
