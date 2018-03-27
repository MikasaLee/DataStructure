/**
 * 3.28 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点（注意不设头指针），试编写相应的队列初始化、入队列和出队列的算法。
 */

#include "../../Unit_2/src/CircularLinkList.c"	//循环链表

typedef struct{
	CLinkList element;
	CLinkList tail;

}cirLinkQueue,*CirLinkQueue;

Status InitCirQueue(CirLinkQueue *cq){
	(*cq) = (CirLinkQueue)malloc(sizeof(cirLinkQueue));
	if(*cq){
		InitList_CL(&((*cq) -> element));
		(*cq) -> tail = (*cq) -> element;
		return OK;
	}
	return ERROR;
}

Status EnCirQueue(CirLinkQueue cq,ElemType e){
	ListInsert_CL(cq -> element,ListLength_CL(cq -> element)+1,e);
	cq -> tail = cq -> tail -> next;
	return OK;
}

Status DeCirQueue(CirLinkQueue cq,ElemType *e){
	ListDelete_CL(cq -> element,1,e);
	return OK;
}

void Show(CirLinkQueue cq){
	CLinkList begin = cq -> tail -> next -> next;
	while(begin != cq -> tail -> next){
		printf("%d ",begin -> data);
		begin = begin -> next;
	}
	printf("\n");
}


int main(int argc,char **args){
	ElemType data[10] = {1,43,12,4,21,43,23,2,34,24},e;
	CirLinkQueue c;
	int i;
	if(InitCirQueue(&c)){
		for(i = 0;i<10;i++){
			EnCirQueue(c,data[i]);
		}
		Show(c);
		DeCirQueue(c,&e);
		for(i = 0;i<10;i++){
			DeCirQueue(c,&e);
		}
		Show(c);
	}

}
