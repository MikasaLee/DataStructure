/*************************************************************************
	> File Name: InOrderTraverse.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 03 Oct 2018 06:21:49 PM CST
 ************************************************************************/

#ifndef INORDERTRAVERSE_C
#define INORDERTRAVERSE_C

#include "./InOrderTraverse.h"

/**
 * 算法6.2
 *		先向左走到尽头，然后弹出并访问节点，再向右一步
 *		重复以上过程直到栈为空
 */
Status InOrderTraverse_1(LBiTree T,Bool Visit(Node node)){	//算法6.2
	SqStack_L S;
	Node p;
	Bool flag = TRUE;
	if(!InitStack_Sq(&S)) exit(OVERFLOW);
	if(!T) return OK;
	p = T;
	Push_Sq(S,p);
	while(!StackEmpty_Sq(S)){
		while(GetTop_Sq(S,&p) && p) Push_Sq(S,p -> lchild);
		Pop_Sq(S,&p);		//弹出null
		if(!StackEmpty_Sq(S)){
			Pop_Sq(S,&p);
			if(!Visit(p)) flag = FALSE;
			Push_Sq(S,p -> rchild);
		}
	}
	return flag;
}
/**
 * 算法6.3与算法6.2思路一样，但是每次少一次空指针退栈操作
 */
Status InOrderTraverse_2(LBiTree T,Bool Visit(Node node)){	//算法6.3
	SqStack_L S;
	Node p;
	Bool flag = TRUE;
	if(!InitStack_Sq(&S)) exit(OVERFLOW);
	p = T;
	if(!T) return OK;
	while(p || (!StackEmpty_Sq(S))){
		if(p){Push_Sq(S,p);p = p -> lchild;}
		else{
			Pop_Sq(S,&p);
			if(!Visit(p)) flag = FALSE;
			p = p -> rchild;
		}
	}
	return flag;
}

#endif
