/**
 * 数值转换
 *  默认实现十进制转换成八进制
 */
#ifndef CONVERSION_C
#define CONVERSION_C

#ifndef ElemType
typedef int ElemType;
#include "SqStack.c"
#endif

void conversion(){
	SqStack_L S;
	int i,j;
	ElemType e;
	if(InitStack_Sq(&S)){
		while(TRUE){
			printf("请输入一个非负的十进制整数:");
			scanf("%d",&i);
			if(i > 0)	break;
			else	printf("输入错误，请重新输入！\n");		
		}
		while(i !=0){
			j = i % 8;
			Push_Sq(S,j);
			i = i/8;
		}
		while(!StackEmpty_Sq(S)){
			Pop_Sq(S,&e);
			printf("%d",e);
		}
	}
}
#endif
