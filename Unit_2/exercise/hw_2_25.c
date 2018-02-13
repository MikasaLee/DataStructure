/**
 * 2.25❹ 假设以两个元素依值递增有序排列的线性表A和B分别表示两个集合（即同一表中的元素值各不相同），
 * 现要求另辟空间构成一个线性表C，其元素为A和B中元素的交集，且表C中的元素也依值递增有序排列。
 * 试对顺序表编写求C的算法。
 */
#include "../src/SqList.c"
void hw_2_25(SqList A,SqList B,SqList *C){
	int i,j;
	ElemType e1,e2;
	if(ListEmpty_Sq(A) || ListEmpty_Sq(B)) exit(OVERFLOW);	
	if(InitList_Sq(C)){
		i = j = 1;
		while(i != ListLength_Sq(A)+1 || j != ListLength_Sq(B)+1){
			if(i != ListLength_Sq(A) +1)	GetElem_Sq(A,i,&e1);	
			if(j != ListLength_Sq(B) +1)	GetElem_Sq(B,j,&e2);
			
			if(j == ListLength_Sq(B)+1 || e1 < e2){
				ListInsert_Sq(C,ListLength_Sq(*C)+1,e1);
				i++;
			}else if(i == ListLength_Sq(A)+1 || e1 > e2){
				ListInsert_Sq(C,ListLength_Sq(*C)+1,e2);
				j++;
			}else	i++;
		}
	}
}
void main(){
	SqList p,q,r;
	int i,j;
	if(InitList_Sq(&p) && InitList_Sq(&q)){
		for(i = 0;i<10;i++)     ListInsert_Sq(&p,ListLength_Sq(p)+1,i);
		for(i = -5;i<5;i++)     ListInsert_Sq(&q,ListLength_Sq(q)+1,i);
		PrintList_Sq(p);
		PrintList_Sq(q);
		hw_2_25(p,q,&r);
		PrintList_Sq(r);
	}
}
