#ifndef LINKLIST_C
#define LINKLIST_C

#include "LinkList.h"

Status InitList_L(LinkList *L){
	(*L) = (LinkList)malloc(sizeof(LNode));
	if(!(*L))	exit(OVERFLOW);		//分配失败
	(*L) -> data = 0;
	(*L) -> next = NULL;
	return OK;
}

Status DestroyList_L(LinkList *L){
	while(*L){		
		LinkList p = *L;
		(*L) = (*L) -> next;
		free(p);
	}
	if(!(*L)){
		(*L) = NULL;		
		return OK;
	}
	printf("--------销毁操作失败！----------");
	return ERROR;	
}
Status ClearList_L(LinkList *L){
	if(!(*L)){
		printf("不是链表，清空失败！\n");
		return ERROR;
	}
	LinkList q = (*L) -> next;		//让q指向第一个节点
	while(q){		
		LinkList p = q;
		q = q -> next;
		free(p);
	}
	if(!q){				//清空成功！
		(*L) -> next = NULL;
		(*L) -> data = 0;
		return OK;
	}
	printf("--------清空操作失败！----------");
	return ERROR;	
}

Bool ListEmpty_L(LinkList L){
	if(!(*L).data && !(*L).next){
		return TRUE;
	}
	return FALSE;
}

int ListLength_L(LinkList L){
	LinkList p= L ->next;
	int i = 0;
	while(p){
		p = p->next;
		i++;
	}
	return i;
}

Status GetElem_L(LinkList L,int i,ElemType *e){
	int j = 0;
	LinkList p = L;
	if( i < 1 || i>ListLength_L(L)){
		printf("不存在第%d个节点",i);
		return ERROR;
	}
	while(j!=i){
		p = p->next;
		j++;
	}
	(*e) = p -> data;
	return OK;
}

Bool max(ElemType a,ElemType b){
	return a > b?TRUE:FALSE;
}
Bool equals(ElemType a,ElemType b){
	return a == b?TRUE:FALSE;
}

int LocateElem_L(LinkList L,ElemType e,Bool (*compare)(ElemType a,ElemType b)){
	int i =1;
	LinkList p = L;
	p = p ->next;
	while(p && !compare(e,p -> data)){	//while里面的顺序不能乱，否则当p = NULL时， p->data溢出
		p = p ->next;
		i++;
	}
	if(p)	return i;	//找见了
	return 0;
}

Status PriorElem_L(LinkList L,ElemType cur_e,ElemType *pre_e){
	LinkList p,q;
	if(!L -> next){
		printf("-----该表为空表，操作失败-----\n");
		return ERROR;
	}
	p = L -> next;
	q = p -> next;
	//排除cur_e为第一个节点的数据域
	/**
	 * 2018-1-31更新：在写双向链表的测试函数时，发现一个Bug：
	 * 如果cur_e = 第一个节点的data = 第二个节点的data. 那么pre_e会指向第一个节点的data
	 * 但是实际情况应该是说明cur_e为第一个节点的data，不存在前一个节点。
	 */
	if(q && (p -> data == q -> data) && (cur_e == p ->data)){
		printf("\n%d为第一个节点，不存在前一个节点\n",cur_e);
		pre_e = NULL;
		return ERROR;
	}		
	while(q && q ->data != cur_e){
		p = q;
		q = q->next;
	}
	if(q){		//找见了
		(*pre_e) = p->data;
		return OK;
	}
	printf("！！！PriorElem_L():	表中不存在这个数据\n");
	pre_e = NULL;
	return ERROR;
}

Status NextElem_L(LinkList L,ElemType cur_e,ElemType *next_e){
	LinkList p,q;
	if(!L -> next){
		printf("-----该表为空表，操作失败-----\n");
		return ERROR;
	}
	q = L -> next;
	p = q -> next;
	
	while(p && q -> data != cur_e){
		q = p;
		p = p -> next;
	}
	if(p){		//找见了
		(*next_e) = p -> data;
		return OK;
	}
	//printf("！！！NextElem_L():	表中不存在这个数据\n");
	next_e = NULL;
	return ERROR;
}

Status ListInsert_L(LinkList L,int i,ElemType e){
	LinkList p,q;
	int j;
	if(i<1 || i> (ListLength_L(L)+1)){
		printf("---插入位置值%d超出表的范围，插入失败---",i);
		return ERROR;
	}
	p = L;
	j = 0;
	while(j != i-1 ){	//指向第i-1个节点
		p = p->next;
		j++;
	}
	
	q = (LinkList)malloc(sizeof(LNode));
	q -> data = e;
	q ->next = p->next;
	p ->next = q;
	(L -> data)++;		//别忘了有规定当ElemType为int/long时，head节点的数据域为节点个数
	return OK;
}//时间复杂度为O(n),n = i < ListLength_L(L);

Status ListDelete_L(LinkList L,int i,ElemType *e){
	LinkList p,q;
	int j;
	if(i<1 || i>ListLength_L(L)){
		printf("---删除位置值%d超出表的范围，删除失败---",i);
		return ERROR;
	}
	p = L;
	j = 0;

	while(j!= i-1){		//指向i-1个节点
		p = p->next;
		j++;
	}
	q = p -> next;
	p -> next = q -> next;
	(L ->data)--;		//规定

	(*e) = q ->data;
	free(q);
	return OK;
}//时间复杂度为O(n),n = i < ListLength_L(L);
//---------------------
Bool visit(ElemType e){
	printf("[");
	printf("%d",e);
	printf("]");
	return OK;
}

Status ListTraverse_L(LinkList L,Bool visit(ElemType e)){
	LinkList p = L;
	if(!p){
		printf("线性表不存在，Traverse操作失败！\n");
		return ERROR;
	}
	p = p -> next;
	while(p && visit(p -> data)){
		p = p->next;
	}
	if(!p)	return OK;
	return ERROR;
}

void Print_L(LinkList L){
	LinkList p;
	if(!L){
		printf("\n----链表不存在----\n");
		return;
	}
	printf("\nhead节点的data：%d\n",L->data);
	p = L->next;
	if(p){
		printf("当前节点的地址\t当前节点的data\t当前节点的next\n");
		printf("-------------\t------------\t------------\n");
		while(p){
			printf(" %d\t%d\t\t%d\n",p,p->data,p->next);
			p = p->next;
		}
		printf("-------------\t------------\t------------\n");
		printf("节点总数为：%d\n",ListLength_L(L));
	}
	else printf("当前该链表为空链表");
	printf("\n");
}
#endif
