/**
 * 2.24 假设有两个按元素值递增有序排列的线性表A和B，均以单链表作存储结构，
 * 请编写算法将A表和B表归并成一个按元素值递减有序（即非递增有序，允许表中含有值相同的元素）排列的线性表C，并要求利用原表（即A表和B表）的结点空间构造C表。
 */
#include "../src/LinkList.c"
void hw_2_24(LinkList *A,LinkList *B,LinkList *C){
	LinkList pa,pb,pc,temp;
	if(!(*A) || !(*B))	exit(OVERFLOW);
	(*C) = (*A);	

	pa = (*A) -> next;
	pb = (*B) -> next;
	pc = (*C);

	free(*B);
	(*A) = NULL;
	(*B) = NULL;
	(*C) -> next = NULL;

	while(pa || pb){
		if(!pb ||  pa -> data < pb -> data){
			temp = pa -> next;
			pa -> next = pc -> next;
			pc -> next = pa;
			
			pa = temp;
		}else{
			temp = pb -> next;
			pb -> next = pc -> next;
			pc -> next = pb;

			pb = temp;
		}	
	}
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
		hw_2_24(&p,&q,&r);
		Print_L(p);
		Print_L(q);
		Print_L(r);
	}
}
