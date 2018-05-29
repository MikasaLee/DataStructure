/*************************************************************************
	> File Name: test_EGList.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sat 26 May 2018 02:27:26 PM CST
 ************************************************************************/

#include "../src/EGList.c"

Bool visit(AtomType);
#ifndef MAIN
#define MAIN
int main(int argc,char **argv){
	EGList L,g1,g2,g3;
	SString S1,S2,S3;
	char *s1 ="()";
	char *s2 ="(e,f,g)";
	char *s3 ="(((a,b,c),d,e),(b,c,d))";
	printf("---------测试InitEGList()---------------\n");
	if(InitEGList(&L)) Traverse_EGL(L,visit);
	printf("\n");
	
	printf("---------测试CreateEGList()---------------\n");
	
	StrAssign(S1,s1);
	StrAssign(S2,s2);
	StrAssign(S3,s3);
	if(CreateEGList(&g1,S1)) Traverse_EGL(g1,visit);
	printf("\n");
	if(CreateEGList(&g2,S2)) Traverse_EGL(g2,visit);
	printf("\n");
	if(CreateEGList(&g3,S3)) Traverse_EGL(g3,visit);
	printf("\n");

	printf("---------测试DestroyEGList()---------------\n");
	if(DestroyEGList(&L)) Traverse_EGL(L,visit);

/**	
    if(DestroyEGList(&g1)) Traverse_EGL(g1,visit);
	if(DestroyEGList(&g2)) Traverse_EGL(g2,visit);
	if(DestroyEGList(&g3)) Traverse_EGL(g3,visit);
**/

	printf("---------测试CopyEGList()---------------\n");
	if(CopyEGList(g3,&L)) Traverse_EGL(L,visit);
	printf("\n");

	printf("---------测试EGListLength()---------------\n");
	printf("L表的元素个数为：%d\n",EGListLength(L));

	printf("---------测试EGListDepth()---------------\n");
	printf("L表的深度为：%d\n",EGListDepth(L));
	
	printf("---------测试InsertFirst_EGL()---------------\n");
	printf("插入前:\n");
	Traverse_EGL(L,visit);
	printf("\n");
	InsertFirst_EGL(&L,L);
	printf("插入后:\n");
	Traverse_EGL(L,visit);
	printf("\n");

	printf("---------测试DeleteFirst_EGL()---------------\n");
	printf("删除前:\n");
	Traverse_EGL(L,visit);
	printf("\n");
	DeleteFirst_EGL(&L,&g1);
	printf("删除后:\n");
	Traverse_EGL(L,visit);
	printf("\n");

	return 0;
}
#endif
Bool visit(AtomType e){
	printf("%c",e);
	return OK;
}

