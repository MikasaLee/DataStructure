/**
 *	2.23 设线性表A=(a1, a2, ..., am)，B=(b1, b2, ..., bn)，试写一个按下列规则合并A，B为线性表C的算法，即使得

                     C=(a1, b1, ..., am, bm, bm+1, ..., bn)     当m<=n时；

	 或者	     C=(a1, b1, ..., an, bn, an+1, ..., am)     当m>n时。

	线性表A，B和C均以单链表作存储结构，且C表利用A表和B表中的结点空间构成。注意：单链表的长度值m和n均未显式存储。
*/
#include "../src/LinkList.c"
void hw_2_23(LinkList *A,LinkList *B,LinkList *C){	//废除A，B表
	if(!(*A) || !(*B))	exit(OVERFLOW);
	LinkList pa,pb,pc;
	(*C) = (*A);
	//pa,pb均指向首元结点,pc指向头节点
	pa = (*A) -> next;	
	pb = (*B) -> next;
	pc = (*C);

	while(pa && pb){
		pc -> next = pa;
		pa = pa -> next;
		pc = pc -> next;

		pc -> next = pb;
		pb = pb -> next;
		pc = pc -> next;
	}
	pc -> next = pa?pa:pb;
	(*A) = NULL;
	free(*B);
	(*B) = NULL;

}//时间复杂度为O(n) n = ListLength_L(*A) <= ListLength_L(*B) ? ListLength_L(*A) : ListLength_L(*B); 
void main(){
	 LinkList p,q,r;
	 p = q = r = NULL;
	 int i,j;
	 if(InitList_L(&p) && InitList_L(&q)){
		for(i = 0;i<10;i++)     ListInsert_L(p,ListLength_L(p)+1,i);
		for(i = -5;i<15;i++)     ListInsert_L(q,ListLength_L(q)+1,i);
		hw_2_23(&p,&q,&r);
	 	Print_L(p);	
	 	Print_L(q);	
	 	Print_L(r);
	 }
}

