#ifndef EXTENDLINKLIST_C
#define EXTENDLINKLIST_C

#include "ExtendLinkList.h"

Status MakeNode_EL(Link *L,ElemType e){
	(*L)  = (Link)malloc(sizeof(ELNode));
	if(!(*L)){
		printf("\n申请空间失败！\n");
		exit(OVERFLOW);
	}

	(*L) -> data = e;
	(*L) -> next = (*L) -> prior= NULL;
	return OK;
}

void FreeNode_EL(Link *L){
	Link p = *L;
	free(p);
	(*L) = NULL;
}

Status InitList_EL(ELinkList *L){
	(*L) = (ELinkList)malloc(sizeof(ELink));
	if(!(*L)){
		printf("\n申请空间失败!\n");
		exit(OVERFLOW);
	}	

	(*L) -> head = (*L) -> tail = NULL;
	(*L) -> length = 0;
	return OK;
}

Status DestroyList_EL(ELinkList *L){
	ELinkList p = *L;
	Link q;
	if(!p)	return OK;		//本来就没有链表的话，那就直接返回呗
	q = p -> head;			//指向第一个节点
	while(q){
		Link temp = q -> next;
		FreeNode_EL(&q);
		q = temp;
	}
	if(!q){
		free(p);
		(*L) = NULL;
		return OK;
	}
	printf("\n没有销毁所有的节点,操作失败\n");
	return ERROR;
}

Status ClearList_EL(ELinkList *L){
	ELinkList p = (*L);
	Link q;
	if(!p){
		printf("\n链表不存在，清空失败！\n");
		return ERROR;
	}
	
	q = p -> head;
	while(q){
		Link temp = q -> next;
		FreeNode_EL(&q);
		q = temp;
	}
	if(!q){
		p -> length = 0;
		p -> head = p -> tail =NULL;
		return OK;
	}
	printf("\n没有清空所有的节点，清空失败\n");
	return ERROR;
}

int ListLength_EL(ELinkList L){
	return L -> length;
}

Bool ListEmpty_EL(ELinkList L){
	if(!L){
		printf("\n链表不存在！\n");
		return FALSE;
	}
	if(L && (L -> head == NULL) && (L -> tail == NULL) && (L -> length == 0)){
		return TRUE;
	}
	return FALSE;
}

Position GetHead_EL(ELinkList L){
	if(!L){
		printf("\n链表不存在！\n");
		return NULL;
	}
	return L?L->head:NULL;
}

Position GetLast_EL(ELinkList L){
	if(!L){
		printf("\n链表不存在！\n");
		return NULL;
	}
	return L?L->tail:NULL;
}

Status ListInsertElemType_EL(ELinkList L,int i,ElemType e){
	Link p,q;
	int j = 0;
	if(!L){
		printf("\n链表不存在！\n");
		return ERROR;
	}
	p = L -> head;
	if(i < 1 || i > ListLength_EL(L)+1){
		printf("\n输入的%d超出范围,插入失败\n",i);
		return ERROR;
	}
	if(MakeNode_EL(&q,e)){
		while(p && j != i -1){
			p = p -> next;
			j++;
		}
		if(j == i -1){		
			if(i == 1){		//往第一个节点插入
				q -> next = L -> head;		//添加新加入节点的下一跳为原来的第一个节点
				q -> prior = NULL;		//添加新加入节点的前一跳为NULL
				if(L -> head)			//仔细琢磨琢磨，如果没有这个ifelse而是直接L -> head -> prior = q ;的话会发生什么
					L -> head -> prior = q;		//更改原来第一个节点的前一跳为新节点
				else
					L -> tail = q;
				L -> head = q;			//更改头结点为新加入的节点

			}
			else if(i == (ListLength_EL(L)+1)){		//往最后插入
				q -> next = NULL;
				q -> prior = L -> tail;
				L -> tail -> next = q;
				L -> tail = q;
			}
			else{			//往其他节点插入
				q -> next =p ;		//添加新加入节点的下一跳为原来节点
				q -> prior = p -> prior;		//添加新加入节点的前一跳为原节点的前一个节点
				p -> prior -> next = q;			//更改原节点的前一个节点的next
				p -> prior = q;			//更改原节点的下一个节点的prior
			}
			
			(L -> length)++;
			return OK;
		}
	}
	return ERROR;
}

Status ListInsertELinkList_EL(ELinkList L1,int i,Link L2_head,Link L2_tail,int k){
	Link p;
	int j = 0;
	if(!L1){
		printf("\n链表不存在\n");
		return ERROR;
	}
	if(i<1 || i > (ListLength_EL(L1)+1) ){
		printf("\n输入的%d超出范围,插入失败\n",i);
		return ERROR;
	}
	if(L2_head == L2_tail) return OK;
	p = L1 -> head;
	
	while(p && j != i-1){
		p = p -> next;
		j++;
	}
	if(j == i-1){
		if(i == 1){		//往第一个节点插入
			L2_head -> prior = NULL;
			L2_tail -> next = L1 -> head;
			
			if(L1 -> head)		//原理同上
				L1 -> head -> prior = L2_tail;
			else 
				L1 -> tail = L2_tail;		
			L1 -> head = L2_head;
		}else if(i == ListLength_EL(L1)+1){		//往最后插入
			L2_head -> prior = L1 -> tail;
			L2_tail -> next = NULL;
			L1 -> tail -> next = L2_head;
			L1 -> tail = L2_tail;
		}else{			//往其他节点插入
			L2_head -> prior = p -> prior;	
			L2_tail -> next = p;
			p -> prior -> next = L2_head;
			p -> prior = L2_tail;
		}
		(L1 -> length) +=k;
		return OK;
	}
	return ERROR;
}

Status ListDelete_EL(ELinkList L,int i,Link *e){
	int j = 0;
	Link p;
	if(!L){
		printf("\n链表不存在\n");
		(*e) = NULL;
		return ERROR;
	}
	if(i < 1 || i > ListLength_EL(L)){
		printf("\n没有第%d个节点\n",i);
		(*e) = NULL;
		return ERROR;
	}
	p = L -> head;
	
	while(p && j != i-1){
		p = p-> next;
		j++;
	}
	if(j == i-1){
		if(i == 1){	//删除第一个节点
			p = L -> head;
			p -> next -> prior = NULL;
			L -> head = p-> next;
		}else if(i == ListLength_EL(L)){	//删除最后一个
			p = L -> tail;
			p -> prior -> next = NULL;
			L -> tail = p -> prior;
		}else{
			p -> prior -> next = p -> next;
			p -> next -> prior = p -> prior;
		}
		(*e) = p;	
		(L -> length)--;
		return OK;
	}
	printf("\n删除操作ERROR\n");
	return ERROR;
}

Link ListSearch_EL(ELinkList L,int *begin,int end,ElemType e){
	Link p;
	int j = 1;
	if(!L){
		printf("\n链表不存在\n");
		return NULL;
	}	
	if((*begin)+1 <= end){
		p = L -> head;
		while(p && j != (*begin)+1){
			p = p -> next;
			j++;
		}
		if(p){
			while(p && j != end){
				if(e == p -> data){
					(*begin) = j;
					return p;
				}
				j++;
				p = p -> next;
			}
		}
		return NULL;
	}	
	printf("\nbegin不能大于end!\n");
	return NULL;
}

Status LocatePos_EL(ELinkList L,int i,Link *e){
	int j = 0;
	Link p;
	if(!L){
		printf("\n链表不存在\n");
		e = NULL;
		return ERROR;
	}
	if(i < 1 || i > ListLength_EL(L)){
		printf("\n没有第%d个节点\n",i);
		e = NULL;
		return ERROR;
	}
	p = L -> head;
	while(p && j != i-1){
		p = p -> next;
		j++;
	}
	if(p){
		(*e) = p;
		return OK;
	}
	printf("\n LocatePos_EL:ERROR!! \n");
	return ERROR;
}

Status GetElem_EL(ELinkList L,int i,ElemType *e){
	Link p;
	if(LocatePos_EL(L,i,&p)){
		(*e) = p -> data;
		return OK;
	}
	printf("\nGet方法失败!\n");
}

Status InsFirst_EL(ELinkList L,Link s){	
	return ListInsertElemType_EL(L,1,s->data);
}

Status DelFirst_EL(ELinkList L,Link *q){
	return ListDelete_EL(L,1,q);
}

Status AppendSome_EL(ELinkList La,int src,ELinkList Lb,int begin,int end){
	Link p,q;
	if(begin <= end){
		LocatePos_EL(Lb,begin,&p);
		LocatePos_EL(Lb,end,&q);
		return ListInsertELinkList_EL(La,src,p,q,end - begin +1);
	}
}

Status Append_EL(ELinkList La,ELinkList Lb,int begin){
	return AppendSome_EL(La,ListLength_EL(La)+1,Lb,begin,ListLength_EL(Lb));
}

Status Remove(ELinkList L,Link *p){
	return ListDelete_EL(L,ListLength_EL(L),p);
}

Status InsBefore_EL(ELinkList L,Link *p,Link s){
	Link q = NULL;
	int i = 1;
	if((*p) != L -> head)	//排除第一个节点，因为Search函数的每一次范围是(begin,end] 
		while(q != (*p))
		       	q = ListSearch_EL(L,&i,ListLength_EL(L),(*p) -> data);

	if(ListInsertElemType_EL(L,i,s ->data)){
		(*p) = (*p) -> prior;
		return OK;
	}	
}

Status InsAfter_EL(ELinkList L,Link *p,Link s){
	Link q = NULL;
	int i = 1;
	if((*p) != L -> head)
		while(q != (*p))
		       	q = ListSearch_EL(L,&i,ListLength_EL(L),(*p) -> data);

	if(ListInsertElemType_EL(L,i+1,s ->data)){
		(*p) = (*p) -> next;
		return OK;
	}
}

Status SetCurElem(Link p,ElemType e){
	p -> data = e;
	return OK;
}

ElemType GetCurElem(Link p){
	return p -> data;
}

Position PriorPos(Link p){
	return p -> prior;
}

Position NextPos(Link p){
	return p -> next;
}


Bool equals(ElemType a,ElemType b){
	return a == b?TRUE:FALSE;
}
Position LocateElem_EL(ELinkList L,ElemType e,Bool (*compare)(ElemType,ElemType)){
	Link p;
	if(!L){
		printf("\n链表为空！\n");
		return NULL;
	}
	p = L -> head;
	while(p && !compare(e,p->data))	p = p -> next;
	if(p) return p;
	printf("\n不存在满足关系的节点\n");
	return NULL;
}

Bool visit(ElemType e){
	printf("[%d] ",e);
	return TRUE;
}
Status ListTraverse_EL(ELinkList L,Bool (*visit)(ElemType)){
	Link p;
	if(!L){
		printf("\n链表为空！\n");
		return ERROR;
	}
	p = L -> head;
	while(p && visit(p -> data)){
		p = p -> next;
	}
	if(!p) return OK;
	return ERROR;
}
void Print_EL(ELinkList L){
	Link p;
	if(!L){
		printf("\n该扩展链表不存在\n");
		return;
	}
	p = L -> head;
	printf("\n-----------------\n");
	printf("链表节点的信息:\n");
	printf("链表节点的地址:%d\t\t链表节点的head:%d\t\t链表节点的tail:%d\n该链表的长度:%d\n",L,L->head,L->tail,ListLength_EL(L));
	if(p){
		printf("当前节点的地址 \t当前节点的data \t当前节点的prior \t当前节点的next\n");
		printf("--------------\t--------------\t---------------\t--------------\n");
		while(p){
			printf("%d\t%d\t\t%d\t%d\n",p,p->data,p->prior,p->next);
			p = p -> next;
		}
		printf("--------------\t--------------\t---------------\t--------------\n");
		return;
	}
	printf("\n该扩展链表为空链表\n");
	return;
}
#endif
