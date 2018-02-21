/**
 * 2.37 设以带头结点的双向循环链表表示的线性表L=(a1, a2, ..., an)，试写一时间复杂度为O(n)的算法，将L改造为L=(a1, a3, ..., an, ..., a4, a2)。
 */
#include "../../Unit_1/src/myDefine.c"
#include "stdio.h"
#include "stdlib.h"

typedef char ElemType;
typedef struct test_link{
	ElemType data;
	struct test_link *next;
	struct test_link *prior;
}testLink,*testList;

void CreateList(testList *L,ElemType *e,int length){
	testList p,q,temp;
	int i = 1;
	(*L) = (testList)malloc(sizeof(testLink));
	p = (*L);
	p -> next = p -> prior = p;
	p -> data = e[0];
	while(i!=length){
		temp = (testList)malloc(sizeof(testLink));
		temp -> data = e[i];
		temp -> next = p -> next;
		temp -> prior = p;
		
		q = p -> next;
		p -> next = temp;
		q -> prior = temp;

		p = p -> next;
		i++;
	}
}
int ListLength_DL(testList L){
	int i = 1;
	testList p = L -> next;
	while(p!=L){
		p = p -> next;
		i++;
	}
	return i;
}
void Print(testList DL){
	testList p;
	if(!DL){
		printf("\n该双向链表不存在\n");
		return;
	}
	p = DL -> next;
	printf("\n------------------------\n");
	printf("双向链表的长度为:%d\n",ListLength_DL(DL));
	if(p){
		printf("当前节点的地址\t当前节点的data\t当前节点的prior\t当前节点的next\n");
		printf("--------------\t--------------\t---------------\t--------------\n");
		printf("%d\t%c\t\t%d\t%d\n",DL,DL->data,DL->prior,DL->next);
		while(p != DL){
			printf("%d\t%c\t\t%d\t%d\n",p,p->data,p->prior,p->next);
			p = p -> next;
		}
		printf("--------------\t--------------\t---------------\t--------------\n");
		return;
	}
	printf("\n该双向链表为空链表\n");
	return;
}
void hw_2_37(testList L){
	testList p,q = L,end = L -> prior;
	int i=1,k;
	k = ListLength_DL(L);
	while(i < k/2){
		testList temp = q -> next;
		p = temp -> next;
		
		temp -> next = end -> next;
		temp -> prior = end;
		end -> next -> prior = temp;
		end -> next = temp;

		p -> prior = q;
		q -> next = p;
		q = q -> next;

		i++;
	}	

}
void main(){
	testList L;
	ElemType e[6] = {'a','b','c','d','e','f'};
	CreateList(&L,e,6);
	Print(L);
	hw_2_37(L);
	Print(L);
}

