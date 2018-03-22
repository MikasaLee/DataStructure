
#ifndef TEST_C
#define TEST_C
typedef struct ElemType{
	int data;
}data,*ElemType;
#include "../src/SqStack.c"
#endif
Bool visit_struct(ElemType e);
int main(int argc,char **args){
	printf("--------");
	SqStack_L S;
	int i;
	ElemType e;
	
	if(InitStack_Sq(&S)){
		for(i = 0;i<10;i++){
			e = (ElemType )malloc(sizeof(data));
			e -> data = i;
			Push_Sq(S,e);
		}
		while(!StackEmpty_Sq(S)){
			Pop_Sq(S,&e);
			printf("%d", e->data);
			printf("e的指向：%d\n",e);
		}
		//StackTraverse_Sq(S,visit_struct);
	}
}
Bool visit_struct(ElemType e){
	printf("%d ",e -> data);
	return TRUE;
}
