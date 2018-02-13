/**
 * 2.27 对2.25题的条件作以下修改，对顺序表重新编写求得表C的算法。
 *
 *     （1）假设在同一表（A或B）中可能存在值相同的元素，但要求新生成的表C中的元素值各不相同.
 *     （2）利用A表空间存放表C。
 */
//(1) 2.25已实现。
//(2):
#include "../src/SqList.c"
//compare函数
Bool min(ElemType a,ElemType b){
	return a < b? TRUE:FALSE;
}
void hw_2_27(SqList A,SqList B,SqList *C){
	ElemType e1,e2;
	int i,j;
	if(ListEmpty_Sq(A) || ListEmpty_Sq(B))	exit(OVERFLOW);
	(*C) = A;
	for(j = i = 0;i<ListLength_Sq(B);i++){
		GetElem_Sq(B,i+1,&e1);
		if(j = LocateElem_Sq(*C,e1,min)){
			GetElem_Sq(*C,j-1,&e2);
			if(e1 !=e2)	ListInsert_Sq(C,j,e1);
		}else	ListInsert_Sq(C,ListLength_Sq(*C)+1,e1);
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
		hw_2_27(p,q,&r);
		PrintList_Sq(r);
	}
}
