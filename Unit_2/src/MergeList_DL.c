/**
 * 双向链表的并操作
 * DLa和DLb是非递减序列，归并DLa和DLb -> DLc,切DLc依然是非递减序列
 * 并且废弃DLa和DLb的头结点（并且废弃DLa和DLb的头结点，DLa的头结点由DLc接手且DLa为NULL，DLb的free掉）
 */
#include "./DoubleLinkList.c"
void MergeList_DL(DuLinkList *DLa,DuLinkList *DLb,DuLinkList *DLc){
	DuLinkList pa,pb,pc;
	if(ListEmpty_DL(*DLa)){
		(*DLc) = (*DLb);
		free(*DLa);
		(*DLa) = (*DLb) = NULL;
		return;
	}
	if(ListEmpty_DL(*DLb)){
		(*DLc) = (*DLa);
		free(*DLb);
		(*DLa) = (*DLb) = NULL;
		return;
	}
	pa = (*DLa) -> next;
	pb = (*DLb) -> next;
	pc = (*DLc) = (*DLa);
	while(pa && pb){
		if(pa -> data < pb -> data){
			//只需要改pc的next和pa的prior，原来的pc的next已经没有用了，pa的prior也没有用了
			pc -> next = pa;
			pa -> prior = pc;
			pa = pa -> next;
			pc = pc -> next;
		}
		else{
			pc -> next = pb;
			pb -> prior = pc;
			pb = pb -> next;
			pc = pc -> next;
		}
	}
	if(pa){	//pa还有剩余
		//还是只需要该pc的next和pa的prior
		pc -> next = pa;
		pa -> prior = pc;
	}else{
		pc -> next = pb;
		pb -> prior = pc;
	}

	free(*DLb);
	(*DLb) = (*DLa) = NULL;
	return ;
}
