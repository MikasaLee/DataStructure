/*************************************************************************
	> File Name: BiSortTree.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 23 Sep 2019 08:24:32 PM CST
 ************************************************************************/

#ifndef BISORTTREE_C
#define BISORTTREE_C

#include "./BiSortTree.h"
Status InitBiSortTree(BiSortTree *T){		//构造空二叉排序树,当作CreateBiSortTree的内部方法
	if(*T){
		free(*T);
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

Status CreateBiSortTree(BiSortTree *T,BiSortElemType datas[],int len){	//按长度为len的define构造二叉排序树T(逐点插入法,关键是InsertNode函数)
	Node p;
	Bool flag = TRUE;
	if(InitBiSortTree(T)){
		p = *T;
		p -> data = datas[0];
	}
	int i;
	for(i =1;i<len;i++){
		if(!InsertBiSortNode(p,datas[i])){	
			printf("\nERROR: InsertBiSortNode(p,%d) faild",datas[i]);
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
	
	return (ldepth > rdepth ? ldepth : rdepth)+1;
}
BiSortElemType Value(Node n){			//返回二叉排序树T中n节点的data
	return n -> data;
}

Node Parent(BiSortTree T,Node p){		//得到p节点的父节点，也是作为InsertBiSortNode的私有方法
	Node parent = NULL;
	if(!T) return NULL;
	if((T -> lchild == p) || (T -> rchild == p)) parent = T;
	else if((parent = Parent(T->lchild,p)) == NULL)
		parent = Parent(T->rchild,p);
	return parent;
}


//三个主要的问题：插入/删除/查找一个节点
Status InsertBiSortNode(BiSortTree root,BiSortElemType e){	//插入一个节点
	Node p;
	if(root == NULL) return ERROR;
	if(e < Value(root)){
		if(root -> lchild) InsertBiSortNode(root -> lchild,e);
		else root -> lchild = CreateNode(e);
	}else{
		if(root -> rchild) InsertBiSortNode(root -> rchild,e);
		else root -> rchild = CreateNode(e);
	}
	return OK;
}

/**
 * 删除节点 
 *		如果删除的是叶子节点，那不需要移动其他节点
 *		但是如果删除的是非叶子节点，则需要将左子树中最大的节点或者右子树中最小的节点代替
 *		规定：先找左子树中最大的节点，如果没有就找右子树中最小的节点
 */
Status DeleteBiSortNode(BiSortTree root,BiSortElemType e){	//删除一个节点
	Node p = NULL,parent = NULL,temp = NULL;
	if(root == NULL) return ERROR;
	if((p = SearchBiSortNode(root,e)) == NULL) return OK;	//无此节点
	else{
		if((p -> rchild == NULL) && (p -> lchild == NULL)){		//叶子节点
			parent = Parent(root,p);				//得到叶子节点的父节点
			printf("parent:%d\n",parent -> data);
			if(parent == NULL)						//此二叉树只有root节点，并且删除root
				parent -> data = -1;				//初始值为-1
			else{
				if(parent -> lchild == p) parent -> lchild = NULL;
				else parent -> rchild = NULL;
				free(p);
				return OK;
			}
		}else{						//非叶子节点
			if(p -> lchild){		//找左孩子
				temp = p -> lchild;
				
				while(temp -> rchild) temp = temp -> rchild;
				parent = Parent(root,temp);
				
				if(parent == p){
					parent -> lchild = NULL;
				}else{
					parent -> rchild = NULL;
				}
			}else{					//找右孩子
				temp = p -> rchild;

				while(temp -> lchild) temp = temp -> lchild;
				parent = Parent(root,temp);
				
				if(parent == p){
					parent -> rchild = NULL;
				}else{
					parent -> lchild = NULL;
				}

			}
			p -> data = temp -> data;		//删除节点
			free(temp);
		}
	}
	return OK;
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
