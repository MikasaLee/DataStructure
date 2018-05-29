/*************************************************************************
	> File Name: hw_5_32.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 29 May 2018 07:03:18 PM CST
 ************************************************************************/

/**
 * 5.32 试编写判别两个广义表是否相等的递归算法。
 */
#ifndef MAIN
#define MAIN
#endif
#include "../test/test_EGList.c"		//广义表的扩展线性链表实现

Bool equals(EGList M,EGList N){	
	if(M == NULL) return N == NULL?TRUE:FALSE;
	EGList M_hp,M_tp,N_hp,N_tp;
	if(M -> tag == N -> tag){
		if(M -> tag == ATOM){
			return M -> Union.atom == N -> Union.atom?TRUE:FALSE;
		}else{
			M_hp = EGetHead(M);
			N_hp = EGetHead(N);
			M_tp = EGetTail(M);
			N_tp = EGetTail(N);
			return equals(M_hp,N_hp) & equals(M_tp,N_tp);
		}
	}
	return FALSE;
}

int main(int argc,char **argv){
	EGList L,g1,g2,g3;
	SString S1,S2,S3;
	char *s1 ="(((a,b,c),d,e),(b,c,d))";
	char *s2 ="(((a,b,c),d,e),(b,c,d))";
	char *s3 ="(((a,b,c),d,e),(b,c,d))";
	printf("---------测试InitEGList()---------------\n");
	if(InitEGList(&L)) Traverse_EGL(L,visit);
	printf("\n");
	
	printf("---------测试CreateEGList()---------------\n");
	
	StrAssign(S1,s1);
	StrAssign(S2,s2);
	if(CreateEGList(&g1,S1)) Traverse_EGL(g1,visit);
	printf("\n");
	if(CreateEGList(&g2,S2)) Traverse_EGL(g2,visit);
	printf("\n");

	if(equals(g1,g2)) printf("==\n");
	else printf("!=\n");
	return 0;
}
