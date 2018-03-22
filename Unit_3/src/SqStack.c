/**
 * 顺序栈的实现
 */
#ifndef SQSTACK_C
#define SQSTACK_C

#include "SqStack.h"
Bool visit(ElemType);	

Status InitStack_Sq(SqStack_L *S){
	SqStack_L p;
	(*S) = (SqStack_L)malloc(sizeof(SqStack));
	if((*S)){
		p = (*S);
		p -> base = (ElemType *)malloc(sizeof(ElemType)*STACK_INIT_SIZE);
		p -> top = p -> base;
		p -> capacity = 0;
		return OK;
	}
	return ERROR;
}

Status DestroyStack_Sq(SqStack_L *S){
	if(!(*S))	return OK;
	free((*S)->base);
	free(*S);
	(*S) = NULL;
	return OK;
}

Status ClearStack_Sq(SqStack_L S){
	if(!S)	exit(OVERFLOW);
	S -> base = S -> top;
	return OK;
}

Bool StackEmpty_Sq(SqStack_L S){
	if(!S)	exit(OVERFLOW);
	return ((S -> top - S -> base) == 0)?TRUE:FALSE;
}

int StackLength_Sq(SqStack_L S){
	if(!S)	exit(OVERFLOW);
	return S -> top - S -> base;
}

Status GetTop_Sq(SqStack_L S,ElemType *e){
	if(!(S))	exit(OVERFLOW);
	if(S -> top == S -> base){return ERROR;}
	ElemType *p = (S -> top) -1;
	(*e) = (*p);
	return OK;
}

Status Push_Sq(SqStack_L S,ElemType e){
	if(!S)	exit(OVERFLOW);
	if(S -> top - S -> base == S -> capacity){	//扩容
		S -> base = realloc(S -> base,((S ->capacity)+STACKINCREMENT)*sizeof(ElemType));
		S -> top = S -> base + S -> capacity;
		S -> capacity +=STACKINCREMENT;
	}
	*(S -> top) = e;	//先放入元素
	S -> top++;		//再抬高栈顶
	return OK;
}

Status Pop_Sq(SqStack_L S,ElemType *e){
	if(!S)	exit(OVERFLOW);
	if(S -> top == S -> base){
		e = NULL;
		return ERROR;
	}
	S->top--;		//降低栈顶
	(*e) = *(S -> top);	//得到元素
	return OK;
}

Status StackTraverse_Sq(SqStack_L S,Bool visit(ElemType)){
	if(!S)	exit(OVERFLOW);
	ElemType *e = S -> base;
	while(e != S -> top){
		if(!visit(*e))	return FALSE;
		e++;
	}
	return OK;
}

Bool visit(ElemType e){
	printf("%c ",e);
	return TRUE;
}

#endif
