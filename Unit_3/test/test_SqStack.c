#include "../src/SqStack.c"

int main(int argc,char **args){
	SqStack_L S;
	int i;
	ElemType e;
	
	if(InitStack_Sq(&S)){
		for(i=0;i<10;i++)
			Push_Sq(S,'A'+i);
		StackTraverse_Sq(S,visit);
		printf("length=%d \n",StackLength_Sq(S));
		Pop_Sq(S,&e);
		StackTraverse_Sq(S,visit);
		printf("\n");
		printf("%c",e);	
		printf("\n");
		for(i=0;i<10;i++){
			Pop_Sq(S,&e);
			printf("%c ",e);
			printf("栈顶地址：%d",S -> top);
		}
		printf("length=%d \n",StackLength_Sq(S));
		StackTraverse_Sq(S,visit);
		if(StackEmpty_Sq(S))	printf("栈为空");
	}
}
