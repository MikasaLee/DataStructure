/*************************************************************************
	> File Name: BiThr.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 13 Nov 2018 09:21:33 AM CST
 ************************************************************************/

#ifndef BITHR_C
#define BITHR_C

#include "./BiThr.h"	

Node pre;		//前一节点

//按长度为len的define构造二叉树T   构造层序序列,无线索化
Status CreateBiTree_Thr(ThrTree *T,ListElemType_Thr *define,int i,int len){
	ThrTree p;
	if((i >= len) || (define[i] == '#')) return OK;
	if(!((*T) = (Node)malloc(sizeof(node)))) exit(OVERFLOW);
	p = (*T);
	p -> data = define[i];
	p -> lchild = p -> rchild = NULL;

	CreateBiTree_Thr(&(p->lchild),define,2*(i+1)-1,len);
	if((p-> lchild) == NULL) p -> ltag = Thread;
	else p -> ltag = Link;

	CreateBiTree_Thr(&(p->rchild),define,2*(i+1),len);
	if((p -> rchild) == NULL) p -> rtag = Thread;
	else p -> rtag = Link;

	return OK;
}


//中序全线索化
void InTheading_Thr(ThrTree T){
	if(!T) return;
	InTheading_Thr(T -> lchild);
	if(T -> ltag == Thread) T -> lchild = pre;
	if(pre -> rtag == Thread) pre -> rchild = T;
	pre = T;
	InTheading_Thr(T -> rchild);
}

Status InOrderThreading_Thr(ThrTree *Thead,ThrTree T){
	ThrTree head;
	if(!T) return ERROR;
	if(!((*Thead) =(ThrTree)malloc(sizeof(node)))) exit(OVERFLOW);
	head = *Thead;
	head -> ltag = Link;
	head -> lchild = T;
	head -> rtag = Thread;
	pre = head;
	InTheading_Thr(T);
	head -> rchild = pre;
	pre -> rchild = head;
	return OK;
	
}
//中序遍历中序全二叉树（非递归算法）
Bool InOrderTraverse_Thr(ThrTree Thead,Bool Visit(Node)){
	Bool flag = TRUE;
	ThrTree p;
	if(!Thead){printf("头结点为空，请检查是否进行线索化\n"); return FALSE;}
	p = Thead -> lchild;	//p指向根节点
	
	while(p != Thead){
		while(p -> ltag == Link) p = p -> lchild;
		flag = Visit(p);
		while((p -> rtag == Thread) &&(p -> rchild !=Thead)){		//访问后继节点
			p = p -> rchild;
			flag = Visit(p);
		}
		p = p -> rchild;
	}
	return flag;
}

void PreThreading_Thr(ThrTree T){ //先序全线索化
	if(!T) return;
	if(T -> ltag == Thread) T -> lchild = pre;
	if(pre -> rtag == Thread) pre -> rchild = T;
	pre = T;
	PreThreading_Thr(T -> lchild);
	PreThreading_Thr(T -> rchild);

}

Status PreOrderThreading_Thr(ThrTree *Thead,ThrTree T){
	ThrTree p;
	if(!T) return ERROR;
	if(!((*Thead) = (ThrTree)malloc(sizeof(node)))) exit(OVERFLOW);
	p = *Thead;
	p -> ltag = Link;
	p -> lchild = T;
	p -> rtag = Thread;
	pre = p;
	printf("aaa\n");
	PreThreading_Thr(T);
	printf("aaa\n");
	p -> rchild = pre;
	pre -> rchild = p;

	return OK;
}

Bool PreOrderTraverse_Thr(ThrTree Thead,Bool Visit(Node)){		//先序遍历二叉树（非递归算法）
	Bool flag = TRUE;
	ThrTree p;
	if(!Thead){printf("头结点为空，请检查是否进行线索化\n"); return FALSE;}
	p = Thead -> lchild;
	while(p != Thead){
		flag = Visit(p);
		printf("aaa\n");
		while(p -> ltag == Link){ p = p -> lchild;}
		while((p -> rtag == Thread)&&(p -> rchild != Thead)){
			p = p -> rchild;
			flag = Visit(p);
		}
		p = p -> rchild;
	}
	return flag;
}
Bool visitByChar(Node node){
	if(node == NULL) printf("NULL");
	else printf("%c",node -> data);
	return TRUE;
}
#endif
