#ifndef DOUBLELINKLIST_c
#define DOUBLELINKLIST_c

#include "DoubleLinkList.h"

Status InitList_DL(DuLinkList *DL){	//规定头结点的data为0,prior为NULL
	(*DL) = (DuLinkList)malloc(sizeof(DuLNode));
	if(!(*DL))	exit(OVERFLOW);
	(*DL) -> data = 0;
	(*DL) -> next = (*DL) -> prior = NULL;
	return OK;
}

Status DestroyList_DL(DuLinkList *DL){
	DuLinkList p;
	if(!(*DL))	return OK;
	p = (*DL);
	while(p){
		DuLinkList q = p -> next;
		free(p);
		p = q;
	}	
	if(!p){
		(*DL) = NULL;
		return OK;
	}
	printf("\n销毁双向链表失败\n");
	return ERROR;
}

Status ClearList_DL(DuLinkList *DL){
	DuLinkList p,q;
	if(!(*DL)){
		printf("\n不存在该双向链表，清空失败！\n");
		return ERROR;
	}
	p = (*DL) -> next;
	while(p){
		q = p -> next;
		free(p);
		p = q;
	}
	if(!p){
		(*DL) -> next = NULL;
		return OK;
	}
	printf("\n清空双向链表失败\n");
	return ERROR;
}

Bool ListEmpty_DL(DuLinkList DL){
	if(DL && !(DL -> next))	return TRUE;
	return FALSE;
}

int ListLength_DL(DuLinkList DL){
	int i = 0;
	DuLinkList p = DL -> next;
	if(ListEmpty_DL(DL))	return 0;
	else{
		while(p){
			i++;
			p = p -> next;
		}
		return i;
	}
}

Status GetElem_DL(DuLinkList DL,int i,ElemType *e){
	DuLinkList p = DL;
	int j = 0;
	if(i < 1 || i > ListLength_DL(DL)){
		printf("\n输入的%d超过该双向链表的范围\n",i);
		return ERROR;
	}
	while(p && j != i){
		p = p-> next;
		j++;
	}

	if(j == i){
		(*e) = p -> data;
		return OK;
	}else{
		printf("\n查找失败！\n");
		return ERROR;
	}
}
//---------compare函数-----------------------
Bool equals(ElemType a,ElemType b){
	return a == b?TRUE:FALSE;
}

int LocateElem_DL(DuLinkList DL,ElemType e,Bool (*compare)(ElemType,ElemType)){
	DuLinkList p = DL -> next;
	int i = 1;
	if(!ListEmpty_DL(DL)){
		while(p && !compare(e,p->data)){
			i++;
			p = p -> next;
		}
	}
	if(p)	return i;	//找见了
	return 0;
}
//如果cur_e是第一个节点的data，那么pre_e也是NULL
Status PriorElem_DL(DuLinkList DL,ElemType cur_e,ElemType *pre_e){
	DuLinkList p; 
	if(ListLength_DL(DL) <=1 ){
		printf("\n该双向链表的长度小于1，不存在前一个节点！\n");
		pre_e = NULL;
		return ERROR;
	}
	p = DL -> next ->next;		//p直接跳过第一个节点，指向第二个节点
	//一个特例：如果第一个节点和第二个节点的data相等并且等于cur_e,那么也应该说明
	if(p && (p -> prior -> data == p -> data ) && (p -> data == cur_e)){
		printf("\n%d为第一个节点的data,不存在前一个节点！\n",cur_e);
		pre_e = NULL;
		return ERROR;
	}
	while(p && p -> data != cur_e)	p = p-> next;
	if(p){
		(*pre_e) = p -> prior -> data;
		return OK;
	}
	printf("\n此双向链表中不存在%d这个数据\n",cur_e);
	pre_e = NULL;
	return ERROR;
}

Status NextElem_DL(DuLinkList DL,ElemType cur_e,ElemType *next_e){
	DuLinkList p;
	if(ListEmpty_DL(DL)){
		printf("\n该双向链表为空链表，操作失败！\n");
		return ERROR;
	}
	p = DL -> next;
	while(p -> next && p -> data != cur_e)	p = p -> next;
	if(p -> next){
		(*next_e) = p -> next -> data;
		return OK;
	}
	printf("\n此双向链表中不存在%d这个数据,或者该数据为最后一个节点的data\n",cur_e);
	next_e = NULL;
	return ERROR;
}

Status ListInsert_DL(DuLinkList DL,int i,ElemType e){
	int j = 0;
	DuLinkList p = DL,q = NULL;
	if(!DL){
		printf("\n该双向链表不存在,添加失败!\n");
		return ERROR;
	}
	if(i<1 || i > ListLength_DL(DL)+1){
		printf("\n%d超出范围,添加失败！\n",i);
		return ERROR;
	}
	q = (DuLinkList)malloc(sizeof(DuLNode));
	if(q){
		while(p && j != i-1){
			p = p -> next;
			j++;
		}
		if(j == i-1){
			q -> data = e;		//设置新节点的data

			q -> prior = p;		//设置新节点的prior
			q -> next = p -> next;	//设置新节点的next
			p -> next =q;		//更改前一个节点的next

			if(q -> next)	 //更改后一个节点的prior		
				q -> next -> prior = q;	
			return OK;
		}
		printf("\nERROR:无法找到第%d节点!!\n",i);
		return OVERFLOW;
	}
	printf("\n申请空间失败！\n");
	return ERROR;
}

Status ListDelete_DL(DuLinkList DL,int i,ElemType *e){
	int j = 0;
	DuLinkList p = DL,q;
	if(!DL){
		printf("\n该双向链表不存在,删除失败!\n");
		return ERROR;
	}
	if(i<1 || i > ListLength_DL(DL)){
		printf("\n%d超出范围,删除失败！\n",i);
		return ERROR;
	}
	while(p && j != i-1){
		p = p -> next;
		j++;		
	}
	if(p){
		q = p -> next;		//q为要删除的节点
		(*e) = q -> data;	//保存下要删除节点的data
		p -> next = q -> next;	//更改前一个节点的next
		if(q -> next){		//更改后一个节点的prior,更改后一个节点的前提是存在后一个节点
			q -> next -> prior = p;
		}
		free(q);
		return OK;
	}
	
	printf("\nERROR:无法找到第%d节点!!\n",i);
	return OVERFLOW;
}

//------visit函数--------------
Bool visit(ElemType e){
	 printf("[");
	 printf("%d",e);
         printf("]");
         return OK; 
}

Status ListTraverse_DL(DuLinkList DL,Bool (*visit)(ElemType)){
	DuLinkList p = DL -> next;
	if(!ListEmpty_DL(DL)){
		while(p && visit(p -> data)){
			p = p -> next;
		}
	}
	if(!p) return OK;
	return ERROR;
}

void Print_DL(DuLinkList DL){
	DuLinkList p;
	if(!DL){
		printf("\n该双向链表不存在\n");
		return;
	}
	p = DL -> next;
	printf("\n------------------------\n");
	printf("头结点的信息：\n");
	printf("头结点的地址:%d\t\t头结点的next:%d\n",DL,DL -> next);
	printf("双向链表的长度为:%d\n",ListLength_DL(DL));
	if(p){
		printf("当前节点的地址\t当前节点的data\t当前节点的prior\t当前节点的next\n");
		printf("--------------\t--------------\t---------------\t--------------\n");
		while(p){
			printf("%d\t%d\t\t%d\t%d\n",p,p->data,p->prior,p->next);
			p = p -> next;
		}
		printf("--------------\t--------------\t---------------\t--------------\n");
		return;
	}
	
	printf("\n该双向链表为空链表\n");
	return;
}
#endif
