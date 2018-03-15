
#ifndef TEST_C
#define TEST_C
typedef struct ElemType{
	int data;
}ElemType;
#include "../src/SqStack.c"
#endif
Bool visit_struct(ElemType e);
int main(int argc,char **args){
	printf("--------");
	SqStack_L S;
	int i;
	ElemType *e;
	
	if(InitStack_Sq(&S)){
		for(i = 0;i<10;i++){
			e = (ElemType *)malloc(sizeof(ElemType));
			e -> data = i;
			Push_Sq(S,*e);
		}
		StackTraverse_Sq(S,visit_struct);
	}
}
Bool visit_struct(ElemType e){
	printf("%d ",e.data);
	return TRUE;
}
