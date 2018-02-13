/**
 * 2.29 已知A，B和C为三个递增有序的线性表，
 * 现要求对A表作如下操作：删去那些既在B表中出现，又在C表中出现的元素。
 * 试对顺序表编写实现上述操作的算法，并分析你的算法的时间复杂度（注意：同一表中各元素值可能相同）。
 */
#include "../src/SqList.c"
//compare函数
Bool equals(ElemType a,ElemType b){
	return a == b?TRUE:FALSE;
}

void hw_2_29(SqList *A,SqList B,SqList C){
	ElemType ea;
	int i;
	i = 1;
	if(ListEmpty_Sq(*A) || ListEmpty_Sq(B) || ListEmpty_Sq(C)) exit(OVERFLOW);
	while(i != ListLength_Sq(*A)+1){	
		GetElem_Sq(*A,i,&ea);		//时间复杂度为O(1)
		if(LocateElem_Sq(B,ea,equals) && LocateElem_Sq(C,ea,equals)){	//既在B表中出现又在C表中出现	时间复杂度为O(n)
			ListDelete_Sq(A,i,&ea);				//删掉；时间复杂度为O(n)
		}else i++;
	}
}//时间复杂度为：O(n的平方)

void main(){
	SqList p,q,r;
	ElemType ea;
	int i,j;
	if(InitList_Sq(&p) && InitList_Sq(&q) && InitList_Sq(&r)){
		for(i = 0;i<10;i++)     ListInsert_Sq(&p,ListLength_Sq(p)+1,i);
		for(i = -5;i<5;i++)     ListInsert_Sq(&q,ListLength_Sq(q)+1,i);
		for(i = -10;i<10;i++)     ListInsert_Sq(&r,ListLength_Sq(r)+1,i);
		PrintList_Sq(p);
		PrintList_Sq(q);
		PrintList_Sq(r);
		hw_2_29(&p,q,r);
		PrintList_Sq(p);
	}
}
