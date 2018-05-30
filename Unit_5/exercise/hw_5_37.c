/*************************************************************************
	> File Name: hw_5_37.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 30 May 2018 04:15:22 PM CST
 ************************************************************************/

/**
 * 5.37 试编写递归算法，删除广义表中所有值等于x的原子项。
 */

#ifndef MAIN
#define MAIN
#include "../test/test_EGList.c"		//导入广义表

Status DelAtom(EGList *L,AtomType at){
	EGList p;
	if(!(*L)) return OK;
	if(((*L) -> tag == ATOM)&&((*L) -> Union.atom == at)){
		free(*L);
		*L = NULL;
		return OK;
	}

	p = (*L) -> Union.hp;
	if(p -> tag == ATOM){
		if(p -> Union.atom == at){		//需要删两个：该节点和父节点，并且将祖父节点指向父节点的tp
			free(p);
			(*L) -> Union.hp = NULL;
			DelAtom(&((*L) -> tp),at);
			p = *L;
			(*L) = p -> tp;
			free(p);
		}else{
			DelAtom(&((*L) -> tp),at);
		}
	}else{
		DelAtom(&((*L) -> Union.hp),at);  // **注意这里与DelAtom(&p,at)的区别**
		DelAtom(&((*L) -> tp),at);
	}
	return OK;
}

int main(int argc,char **argv){
	EGList L,g1,g2,g3;
	SString S1,S2,S3;
	char *s1 ="(((a,b,c),d,(a,d,c,a,c),e),(b,c,d))";
	char ch = 'a';
	
	StrAssign(S1,s1);
	if(CreateEGList(&g1,S1)){
		Traverse_EGL(g1,visit);
		printf("\n");
		DelAtom(&g1,ch);
		Traverse_EGL(g1,visit);
		printf("\n");
	}
	return 0;
}

#endif
