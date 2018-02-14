/**
 * 2.32 已知有一个单向循环链表，其每个结点中含三个域：pre，data和next，
 * 其中data为数据域，next为指向后继结点的指针域，pre也为指针域，但它的值为空(NULL)，
 * 试编写算法将此单向循环链表改为双向循环链表，即使pre称为指向前驱结点的指针域。
 */
#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"
typedef int ElemType;
typedef struct List_2_32{
	ElemType data;
	struct List_2_32 *next;
	struct List_2_32 *prior;
}List_2_32,*LinkList_temp;

Status CreateList_temp(LinkList_temp *L,int n,ElemType e[]){  //直接搞出一个满足题意的循环链表,要求L指向为NULL
	if(*L)  exit(OVERFLOW);
	int i = 0;
	LinkList_temp p = NULL,q = NULL;
	(*L) = (LinkList_temp)malloc(sizeof(List_2_32));
	if(*L){
		(*L) -> data = e[i];
		(*L) -> next = (*L);
		(*L) -> prior = NULL;

		q = (*L);
		for(i = 1;i<n;i++){
			p = (LinkList_temp)malloc(sizeof(List_2_32));
			if(p){
				p -> data = e[i];
				p -> prior = NULL;
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
int Length_temp(LinkList_temp L){
	int i = 1;
	LinkList_temp p = L;
	if(!L)	return 0;
	while(p -> next != L){
		p = p -> next;
		i++;
	}
	return i;
}
void Print(LinkList_temp L){
	LinkList_temp p;
	int i = 0;
	if(!L) exit(OVERFLOW);
	p = L -> next;
	i++;
	printf("\n---------------------------\n");
	printf("\n循环链表的长度为：%d\n",Length_temp(L));
	printf("当前节点的prior\t当前节点的地址\t当前节点的date\t当前节点的next\n");
	printf("---------------\t--------------\t--------------\t--------------\n\n");
	printf("%d\t\t%d\t%d\t\t%d\n",L->prior,L,L->data,L->next);
	while(p != L){
		printf("%d\t\t%d\t%d\t\t%d\n",p -> prior,p,p->data,p->next);
		p = p -> next;
		i++;
	}
	printf("--------------\t--------------\t--------------\n\n");
}
Status hw_2_32(LinkList_temp L){
	if(!L) exit(OVERFLOW);
	LinkList_temp p = L,temp;
	int i,n = Length_temp(L);
	for(i = 0;i<n;i++){
		temp = p;
		p = p -> next;
		p -> prior = temp;
	}
	return OK;
}

void main(){
	//ElemType e[6] = {12,-3,14,0,1,-545};
	//ElemType e[2] = {12,-3};
	ElemType e[1] = {12};
	LinkList_temp L = NULL;
	//CreateList_temp(&L,6,e);
	//CreateList_temp(&L,2,e);
	CreateList_temp(&L,1,e);
	Print(L);
	hw_2_32(L);
	Print(L);
}

