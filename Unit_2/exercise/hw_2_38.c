/**
 * 2.38❹设有一个双向循环链表，每个结点中除有pre，data和next三个域外，还增设了一个访问频度域freq。
 * 在链表被起用之前，频度域freq的值均初始化为零，而每当对链表进行一次LOCATE(L, x)的操作后，被访问的结点（即元素值等于x的结点）中的频度域freq的值便增1，
 * 同时调整链表中结点之间的次序，使其按访问频度非递增的次序顺序排列，以便始终保持被频繁访问的结点总是靠近表头结点，试编写符合上述要求的LOCATE操作的算法。
 */

#include "../../Unit_1/src/myDefine.c"
#include "stdio.h"
#include "stdlib.h"

typedef char ElemType;
typedef struct test_link{
	ElemType data;
	struct test_link *next;
	struct test_link *prior;
	int freq;
}testLink,*testList;

void CreateList(testList *L,ElemType *e,int length){
	testList p,q,temp;
	int i = 1;
	(*L) = (testList)malloc(sizeof(testLink));
	p = (*L);
	p -> next = p -> prior = p;
	p -> data = e[0];
	p -> freq = 0;
	while(i!=length){
		temp = (testList)malloc(sizeof(testLink));
		temp -> data = e[i];
		temp -> next = p -> next;
		temp -> prior = p;
		temp -> freq = 0;

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
		printf("当前节点的地址\t当前节点的data\t当前节点的prior\t当前节点的next\t当前节点的freq\n");
		printf("--------------\t--------------\t---------------\t--------------\t--------------\n");
		printf("%d\t%c\t\t%d\t%d\t%d\n",DL,DL->data,DL->prior,DL->next,DL -> freq);
		while(p != DL){
			printf("%d\t%c\t\t%d\t%d\t%d\n",p,p->data,p->prior,p->next,p -> freq);
			p = p -> next;
		}
		printf("--------------\t--------------\t---------------\t--------------\n");
		return;
	}
	printf("\n该双向链表为空链表\n");
	return;
}

testList LOCATE_2_38(testList *L,ElemType x){
	if(!(*L)) exit(OVERFLOW);
	if((*L) -> data == x){
		((*L) -> freq)++;
		return (*L);
	}
	testList p = (*L) -> next,q = (*L);
	while(p!=(*L)){
		if(p -> data == x){	//找到！
			(p -> freq)++;
			while(p -> freq < q -> freq){
				q = q -> next;
			}
			
			p -> prior -> next = p -> next;
			p -> next -> prior = p -> prior;

			p -> next = q;
			p -> prior = q -> prior;
			q -> prior -> next = p;
			q -> prior = p;
			if(q == (*L))	(*L) = p;
			return p;
		}
		p = p -> next;
	}
	return NULL;
}

void main(){
	testList L;
	ElemType e[6] = {'a','b','c','d','e','f'};
	CreateList(&L,e,6);
	Print(L);

	printf("\n--------测试LOCATE(L,x)函数-----------\n");
	LOCATE_2_38(&L,'c');
	LOCATE_2_38(&L,'b');
	LOCATE_2_38(&L,'c');
	Print(L);
}

