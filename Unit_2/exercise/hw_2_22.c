/**
 * 2.22❸ 试写一算法，对单链表实现就地逆置。(就地的意思是利用原表的存储空间而不生成申请的空间)
 */
#include "../src/LinkList.c"
/**
 * 非就地实现
void hw_2_22(LinkList L){
	ElemType e;
	int i;
	if(ListLength_L(L) < 1)	return;
	for(i = 1;i<=ListLength_L(L);i++){
		ListDelete_L(L,i,&e);		//时间复杂度为O(i)
		ListInsert_L(L,1,e);		//时间复杂度为O(1)
	}
}//时间复杂度为O(n的平方);
**/
/**
 * 就地逆序的实现思想：将原链表中的头结点和第一个元素节点断开（令其指针域为空），先构成一个新的空表，然后将原链表的各节点，从第一个节点起，依次插入这个新表的头部（即令每个插入的节点成为新的第一个元素即诶但）
 */
void hw_2_22(LinkList L){
	LinkList p,q;
	if(ListLength_L(L) < 1)	return;
	p = L -> next;
	L -> next = NULL;
	while(p){
		q = p -> next;	//保存p的下一跳

		//将p插入到L的首元节点
		p -> next = L -> next;
		L -> next = p;
		p = q; 
	}
}
void main(){
	LinkList p;
	int i,j;
	if(InitList_L(&p)){
		for(i = 0;i<10;i++)     ListInsert_L(p,ListLength_L(p)+1,i);
		Print_L(p);
		hw_2_22(p);
		Print_L(p);
	}
}
