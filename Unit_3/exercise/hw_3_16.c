/**
 * 3.16:
 * 	假设如题3.1所属火车调度站的入口处有n节硬席或软席车厢（分别以H和S表示）等待调度，
 * 	试编写算法，输出对这n节车厢进行调度的操作（即入栈或出栈操作）序列，以使所有的软席车厢都被调整到硬席车厢之前。
 */
#include "../src/SqStack.c"

ElemType* CreateTrain(int n){		//生成一个n节的火车车厢
	ElemType *e;
	int i;
	e = (ElemType *)malloc(sizeof(ElemType)*n);
	if(e){
		for(i = 0;i<n;i++){
			switch(rand()%2){
				case 0:e[i] = 'H';
				       break;
				case 1:e[i] = 'S';
				       break;
			}
			printf("%c ",e[i]);
		}
		return e;
	}
	return NULL;
}

void hw_3_16(ElemType *e,int n){
	SqStack_L S;
	ElemType temp;
	int i,j;
	if(!e)	exit(OVERFLOW);
	if(InitStack_Sq(&S)){
		for(i = 0,j=0;i < n;i++){
			//printf("将第%d节车厢入栈",i+1);
			Push_Sq(S,e[i]);
			if(e[i] == 'S'){
			//	printf("将第%d节车厢出栈\n",i+1);
				printf("S ");
				Pop_Sq(S,&temp);
			}
		}
		//printf("所有软席车厢出站完毕，出站硬席车厢\n");
		while(!StackEmpty_Sq(S)) {printf(" H"); Pop_Sq(S,&temp);}
	}
}

int main(int argc,char **args){
	int n = 10;
	ElemType *e;
	if((e = CreateTrain(n)) != NULL){
		printf("\n创建成功！\n");
		printf("调整序列：\n");
		hw_3_16(e,n);
	}
}
