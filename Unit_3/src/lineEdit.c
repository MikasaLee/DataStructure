/**
 * p49 3.2.3 行编辑程序
 * 	# 表示退格
 * 	@ 表示当前行中的字符均无效
 */

#ifndef LINEEDIT_C
#define LINEEDIT_C

#include "SqStack.c"

void lineEdit(){
	SqStack_L S;
	int i,j;
	ElemType e,c[81],p;
	if(InitStack_Sq(&S)){
		printf("请输入:");
		scanf("%s",c);
		i = 0;
		p = c[i];
		while(p != '\0'){
			if(p == '#') Pop_Sq(S,&e);
			else if(p == '@') ClearStack_Sq(S);
			else Push_Sq(S,p);
			p = c[++i];
		}
		StackTraverse_Sq(S,visit);
	}
}


#endif
