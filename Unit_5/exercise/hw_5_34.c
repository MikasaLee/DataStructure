/*************************************************************************
	> File Name: hw_5_34.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 29 May 2018 07:42:48 PM CST
 ************************************************************************/

/**
 * 5.34❺试编写递归算法，逆转广义表中的数据元素。
 *
 *         例如：将广义表
 *         (a, ((b, c), ()), (((d), e), f))
 *         转成
 *         ((f, (e, (d))), ((), (c, b)), a)。
 */
#ifndef MAIN
#define MAIN

#include "../test/test_EGList.c"

Status reverse(EGList *L,EGList parent){	//L为当前节点,parent为该层的父节点
	EGList next,p;
	if(*L == NULL || (((*L) -> tag == LIST)&&((*L) -> Union.hp == NULL)&&((*L) -> tp == NULL))) return OK;
	p = *L;
	if(parent == NULL){			//对于第一层来说，没有父节点
		if(p -> tag == ATOM) return OK;
		if(!InitEGList(&parent)) exit(OVERFLOW);

		parent -> tag = LIST;
		parent -> tp = NULL;
		parent -> Union.hp = p;

		reverse(&p,parent);		//反转第一层

		*L = parent -> Union.hp;
		free(parent);
	}else{
		if(p -> tag == LIST) {
			reverse(&(p -> Union.hp),p);
		}
		if(p -> tp == NULL){	//p指向最后一个节点了。
			if(parent -> Union.hp != p){
				parent -> Union.hp -> tp = NULL;		//将首节点的下一跳设为NULL
				parent -> Union.hp = p;		//更改首节点
			}
		}else{
			next = p -> tp;
			reverse(&next,parent);
			next -> tp = p;
		}
	}
	return OK;
}

int main(int argc,char **argv){
	EGList L,g1,g2,g3;
	SString S1,S2,S3;
	char *s1 ="(((a,b,c),d,e),(b,c,d))";
	
	StrAssign(S1,s1);
	if(CreateEGList(&g1,S1)){
		Traverse_EGL(g1,visit);
		printf("\n");
		reverse(&g1,NULL);
		Traverse_EGL(g1,visit);
		printf("\n");
	}
	return 0;
}
#endif
