/**
 * 2.21 试写一算法，实现顺序表的就地逆置，即利用原表的存储空间将线性表(a1, a2, ..., an)逆置为(an, an-1, ..., a1)。
 */
#include "../src/SqList.c"

void hw_2_21(SqList L){
	int i;
	ElemType temp;
	if(!ListLength_Sq(L)) return;
	for(i = 0;i < ListLength_Sq(L)/2;i++){
		temp = L.elem[i];
		L.elem[i] = L.elem[ListLength_Sq(L)-1-i];
		L.elem[ListLength_Sq(L)-1-i] = temp;
	}
}
void main(){
	SqList p;
	int i;
	ElemType e[5] ={123,435,45,2,88};
	if(InitList_Sq(&p)){
		for(i = 0;i<5;i++)	ListInsert_Sq(&p,i+1,e[i]);
		PrintList_Sq(p);
		hw_2_21(p);
		PrintList_Sq(p);
	}
}
