/*************************************************************************
	> File Name: BiTreeTraverse.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sat 28 Sep 2019 10:43:20 PM CST
 ************************************************************************/

#ifndef BITREETRAVERSE_C
#define BITREETRAVERSE_C

#include "./BiTreeTraverse.h"

void PreOrder1(BiSortTree T,Bool Visit(Node node)){
	if(T){
		Visit(T);
		PreOrder1(T -> lchild,Visit);
		PreOrder1(T -> rchild,Visit);
	}
}

void InOrder1(BiSortTree T,Bool Visit(Node node)){	//中序
	if(T){
		InOrder1(T -> lchild,Visit);
		Visit(T);
		InOrder1(T -> rchild,Visit);
	}
}
void PostOrder1(BiSortTree T,Bool Visit(Node node)){	//后序
	if(T){
		PostOrder1(T -> lchild,Visit);
		PostOrder1(T -> rchild,Visit);
		Visit(T);
	}
}


//非递归算法需要借助栈来实现，可以使用第三章定义的栈，但是考试中不会提供栈及其方法
//所以这里就自己模拟一个栈来实现,且开始栈顶指针top是-1而不是0
/**
 * 思想：
 *		如果节点不为null：
 *			先访问此节点
 *			再将此节点入栈(保存起来已访问右孩子)
 *			将节点指向左孩子
 *			重复
 *		节点为null：
 *			弹出栈顶，将节点指向右孩子
 *			重复
 *
 */
#define MAX 50		//栈的大小为50	
void PreOrder2(BiSortTree T,Bool Visit(Node node)){	//先序,非递归
	Node Stack[MAX],p = T;
	int top = -1;
	while(p || top != -1){
		if(p){
			Visit(p);
			Stack[++top] = p;
			p = p -> lchild;
		}else{
			p = Stack[top--];
			p = p -> rchild;
		}
	}
}
/**
 * 中序遍历的非递归和前序思想一样，这里就不用重复说明了
 */
void InOrder2(BiSortTree T,Bool Visit(Node node)){	//中序
	Node Stack[MAX],p = T;
	int top = -1;
	while(p || top != -1){
		if(p){
			Stack[++top] = p;
			p = p -> lchild;
		}else{
			p = Stack[top--];
			Visit(p);
			p = p -> rchild;
		}
	}
}

/**
 * 前序遍历 根左右
 * 后序遍历 左右根
 * 后续遍历倒过来 根右左
 *   所以将前序遍历改成根右左然后在倒叙输出就是后续遍历
 */
void PostOrder2(BiSortTree T,Bool Visit(Node node)){	//后序
	Node Stack[MAX],Stack2[MAX], p =T;		//Stack2就是辅助栈，把前序遍历中的Visit操作改成Stack2的入栈操作，最后在输出Stack2就ok了
	int top = -1,top2 = -1;
	while(p || top != -1){
		if(p){
			Stack2[++top2] = p;		//原先是Visit 改成Stack2
			Stack[++top] = p;
			p = p -> rchild;
		}else{
			p = Stack[top--];
			p = p -> lchild;
		}
	}
	while(top2 != -1) Visit(Stack2[top2--]);

}


/**
 * 层序遍历是最简单的，因为之前二叉树中的层序遍历就是非递归实现，所以这里没有什么难度
 */
void LevelOrder2(BiSortTree T,Bool Visit(Node node)){	//层序
	Node List[MAX],p = T;
	int i,j;
	i = j =0;
	List[j++] = p;
	while(i < j){
		p = List[i++];
		if(p -> lchild) List[j++] = p -> lchild;
		if(p -> rchild) List[j++] = p -> rchild;
		Visit(p);
	}
}
#endif

