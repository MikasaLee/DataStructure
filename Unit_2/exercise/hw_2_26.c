/**
 * 2.26 要求同2.25题。试对单链表编写求C的算法。 
 */
#include "../src/LinkList.c"
void hw_2_26(LinkList A,LinkList B,LinkList *C){
	LinkList pa,pb,pc;
	if(InitList_L(C)){
		pa = A -> next;
		pb = B -> next;
		while(pa || pb){
			if(!pb || pa -> data < pb -> data){
				ListInsert_L(*C,ListLength_L(*C)+1,pa -> data);
				pa = pa -> next;
			}else if(!pa || pa -> data > pb -> data){
				ListInsert_L(*C,ListLength_L(*C)+1,pb -> data);
				pb = pb -> next;
			}else pa = pa -> next;
		}
	}	
	printf("\n申请空间失败！\n");
}

void main(){
	LinkList p,q,r;
	p = q = r = NULL;
	int i,j;
	if(InitList_L(&p) && InitList_L(&q)){
		for(i = 0;i<10;i++)     ListInsert_L(p,ListLength_L(p)+1,i);
		for(i = -5;i<5;i++)     ListInsert_L(q,ListLength_L(q)+1,i);
		Print_L(p);
		Print_L(q);
		Print_L(r);
		hw_2_26(p,q,&r);
		Print_L(p);
		Print_L(q);
		Print_L(r);
	}
}
