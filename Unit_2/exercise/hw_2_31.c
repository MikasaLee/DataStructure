/**
 * 2.31 假设某个单向循环链表的长度大于1，
 * 且表中既无头结点也无头指针。已知s为指向链表中某个结点的指针，
 * 试编写算法在链表中删除指针s所指结点的前驱结点。
 */
#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"
//没有头结点的单项循环链表
typedef int ElemType;
typedef struct NoHead_CLNode{
	ElemType data;
	struct NoHead_CLNode *next;
}NoHead_CLNode,*NoHead_CL;

Status Create_NHCL(NoHead_CL *L,int n,ElemType e[]){	//直接搞出一个满足题意的循环链表,要求L指向为NULL
	if(*L)	exit(OVERFLOW);
	int i = 0;
	NoHead_CL p = NULL,q = NULL;
	(*L) = (NoHead_CL)malloc(sizeof(NoHead_CLNode));
	if(*L){
		(*L) -> data = e[i];
		(*L) -> next = (*L);
		q = (*L);
		for(i = 1;i<n;i++){
			p = (NoHead_CL)malloc(sizeof(NoHead_CLNode));
			if(p){
				p -> data = e[i];
				q -> next = p;
				p -> next = (*L); 

				q = q -> next;
				p = NULL;
			}
		}
		return OK;

	}
	printf("\n申请空间失败！\n");
	return ERROR;
}

void Print(NoHead_CL L){
	NoHead_CL p;
	int i = 0;
	if(!L) exit(OVERFLOW);
	p = L -> next;
	i++;
	printf("\n---------------------------\n");
	printf("当前节点的地址\t当前节点的date\t当前节点的next\n");
	printf("--------------\t--------------\t--------------\n\n");
	printf("%d\t%d\t\t%d\n",L,L->data,L->next);
	while(p != L){
		printf("%d\t%d\t\t%d\n",p,p->data,p->next);
		p = p -> next;
		i++;
	}
	printf("--------------\t--------------\t--------------\n\n");

}
void hw_2_31(NoHead_CL L){
	if(!L)	exit(OVERFLOW);
	NoHead_CL p = L,temp;
	while(p -> next -> next != L) p = p -> next;
	temp = p -> next;
	p -> next = L;
	free(temp);
	return;
}
void main(){
	//ElemType e[6] = {12,-3,14,0,1,-545};
	ElemType e[2] = {12,-3};
	//ElemType e[1] = {12};	//题中说长度大于1,所以不能用这个做测试
	NoHead_CL L = NULL;
	//Create_NHCL(&L,6,e);
	Create_NHCL(&L,2,e);
	//Create_NHCL(&L,1,e);
	Print(L);
	hw_2_31(L);
	Print(L);
}
