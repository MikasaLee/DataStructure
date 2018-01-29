/**
 * 实现A并B的操作（链表版）
 *
 */
#include "./LinkList.c"
void Union_L(LinkList *La,LinkList *Lb){
	//将Lb表并入La表，同时废除Lb表
	LinkList p,q;
	if(!(*Lb)) return;
	if(!(*La)){
		(*La) = (*Lb);
		(*Lb) = NULL;
		return;
	}
	p = (*La);
	q = (*Lb) -> next;
	while(q){
		if(!LocateElem_L(p,q->data,equals))	
			ListInsert_L(p,ListLength_L(p)+1,q->data);
		q = q->next;
	}
	DestroyList_L(Lb);
	return;
}
