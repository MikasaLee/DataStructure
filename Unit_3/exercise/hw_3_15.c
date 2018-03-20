/**
 * 习题3.15
 * 	假设以顺序存储结构实现一个双向栈，即在一维数组的存储空间中存在着两个栈，它们的栈底分别设在数组的两个端点。
 * 	试编写实现这个双向栈tws的三个操作：初始化inistack(tws)、入栈push(tws,i,x)和出栈pop(tws,i)的算法，其中i为0或1，用以分别指示设在数组两端的两个栈，
 * 	并讨论按过程(正/误状态变量可设为变参)或函数设计这些操作算法各有什么有缺点。
 */

#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"

typedef char ElemType;
#define N 30		//容量足够大
typedef struct{
	ElemType *data;
	int Left_Top;		
	int Left_Base;
	int Right_Top;
	int Right_Base;
}twStack,*TWStack;

Status iniStack(TWStack *S){
	(*S) = (TWStack)malloc(sizeof(twStack));
	if((*S)){
		(*S) -> data = (ElemType *)malloc(sizeof(ElemType)*N);
		(*S) -> Left_Top = (*S) -> Left_Base = 0;
		(*S) -> Right_Top = (*S) -> Right_Base = N;
		return OK;
	}
	exit(OVERFLOW);
}

Status push(TWStack tws,int dir,ElemType e){		//i表示方向，0表示左，1表示右
	if(!tws)	exit(OVERFLOW);
	if(tws -> Left_Top == tws -> Right_Top)	return ERROR;
	if(dir == 0){
		tws -> data[tws -> Left_Top] = e;
		(tws -> Left_Top)++;
	}else{
		(tws -> Right_Top)--;
		tws -> data[tws -> Right_Top] = e;
	}
	return OK;
}

Status pop(TWStack tws,int dir,ElemType *e){
	if(!tws)	exit(OVERFLOW);
	if(dir == 0){
		if(tws -> Left_Top == tws -> Left_Base)	return ERROR;
		(tws -> Left_Top)--;
		(*e) = tws -> data[tws -> Left_Top];
	}else{
		if(tws -> Right_Top == tws -> Right_Base)	return ERROR;
		(*e) = tws -> data[tws -> Right_Top];
		(tws -> Right_Top)++;
	}
	return OK;
}

void show(TWStack s){
	int i;
	for(i =s -> Left_Base;i<s -> Left_Top;i++){
		printf("%c ",s -> data[i]);
	}
	printf("\n");
	for(i =s -> Right_Base-1;i>=s -> Right_Top;i--){
		printf("%c ",s -> data[i]);
	}
	printf("\n");
}

int main(int argc,char **args){
	TWStack s;
	ElemType e;
	int i,j;
	if(iniStack(&s)){
		for(i = 0;i<25;i++)	push(s,0,i+48);
		for(i = 0;i<10;i++)	push(s,1,i+48);
		show(s);
		for(i = 0;i<10;i++)	pop(s,0,&e);
		for(i = 0;i<10;i++)	pop(s,1,&e);
		show(s);
	}
}
