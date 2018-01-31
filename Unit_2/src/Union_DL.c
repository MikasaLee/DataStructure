/**
 * 实现A并B的操作(链表版)
 *
 */
#include "./DoubleLinkList.c"
void Union_DL(DuLinkList *DLa,DuLinkList *DLb){
	//将DLb表并入DLa表,同时废除DLb表
	DuLinkList p,q;
	if(!(*DLb))	return;
	if(!(*DLa)){
		(*DLa) = (*DLb);
		(*DLb) = NULL;
		return;
	}
	p = (*DLa);
	q = (*DLb) -> next;
	while(q){
		if(!LocateElem_DL(p,q->data,equals))
			ListInsert_DL(p,ListLength_DL(p)+1,q -> data);
		q = q -> next;
	}
	DestroyList_DL(DLb);
	return ;
}

