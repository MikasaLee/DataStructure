#include "../src/Union_Sq.c"
void main(){
	SqList a,b;
	int i;
	InitList_Sq(&a);
	for(i = -10;i<10;i++){
		ListInsert_Sq(&a,1,i);
	}
	InitList_Sq(&b);
	for(i = 0;i<15;i++){
		ListInsert_Sq(&b,1,i);
	}
	PrintList_Sq(a);
	PrintList_Sq(b);
	Union_Sq(&a,b);
	PrintList_Sq(a);
}

