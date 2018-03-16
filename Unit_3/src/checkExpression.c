/*
 * P49 3.2.2 括号匹配的检验
 */

#ifndef CHECKEXPRESSION_C
#define CHECKEXPRESSION_C

#include "SqStack.c"

Bool checkExpression(){
	SqStack_L S;
	ElemType c[81],p,e;
	int i =0;
	if(InitStack_Sq(&S)){
		printf("请输入数学表达式：");
		scanf("%s",c);
		p = c[0];
		while(p != '\0'){
			if(p == '(' || p == '[' || p == '{') Push_Sq(S,p);
			else{
				if(p == ')'){
					Pop_Sq(S,&e);
					if(e != '(') return FALSE;
				}else if(p == ']'){
					Pop_Sq(S,&e);
					if(e != '[') return FALSE;
				}else if(p == '}'){
					Pop_Sq(S,&e);
					if(e != '{') return FALSE;
				}
			}
			i++;
			p = c[i];
		}//while
		if(StackEmpty_Sq(S))	return TRUE;	
	}
	return FALSE;
}

#endif
