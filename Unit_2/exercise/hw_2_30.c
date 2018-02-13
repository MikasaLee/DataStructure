/**
 * 2.30  要求同2.29题。试对单链表编写算法，请释放A表中的无用结点空间。
 */
#include "../src/LinkList.c"
void hw_2_30(LinkList A,LinkList B,LinkList C){
	ElemType ea;
	int i;
	if(ListEmpty_L(A) || ListEmpty_L(B) || ListEmpty_L(C)) exit(OVERFLOW);
	i = 1;
	while(i != ListLength_L(A)){
		GetElem_L(A,i,&ea);
		if(LocateElem_L(B,ea,equals) && LocateElem_L(C,ea,equals)){
			ListDelete_L(A,i,&ea);
		}else i++;
	}
}//时间复杂度为：O(n的三次方)

void main(){
	LinkList p,q,r;
	ElemType ea;
	int i,j;
	if(InitList_L(&p) && InitList_L(&q) && InitList_L(&r)){
		for(i = 0;i<10;i++)     ListInsert_L(p,ListLength_L(p)+1,i);
		for(i = -5;i<5;i++)     ListInsert_L(q,ListLength_L(q)+1,i);
		for(i = -10;i<10;i++)     ListInsert_L(r,ListLength_L(r)+1,i);
		Print_L(p);
		Print_L(q);
		Print_L(r);
		hw_2_30(p,q,r);
		Print_L(p);
	}
}
