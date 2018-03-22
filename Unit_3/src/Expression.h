/**
 * P52 3.2.5 表达式求值
 * 	只涉及到加减乘除和括号的表达式。
 * 	并且输入的数字只能为整数(为了更加精确，得到的是小数)
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H

typedef struct opt{
	int type;		//类型，0表示操作符或括号，1表示数字
	char optr;		//操作符
	float opnd;		//数字

}opt,*ElemType;
#include "SqStack.c"

float operator(float num1 ,char oper,float num2);
float Expression();
float evaluate(ElemType *sub);	//计算子表达式的值
void reverse(ElemType *s);
#endif
