#ifndef MYSTRING_H
#define MYSTRING_H

#include "../../Unit_1/src/myDefine.c"

typedef char ElemType;
#define init_length 10
typedef struct{
	ElemType *Base;
	int size;
}str,*myString;

Status StrAssigh(myString *str,char *chars);	//chars
#endif
