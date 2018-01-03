#include "../src/MergeList_Sq.c"
void main(){
	SqList a,b,c;
	int i;
	InitList_Sq(&a);
	for(i = 10;i>-10;i--){
		ListInsert_Sq(&a,1,i);
	}
	InitList_Sq(&b);
	for(i = 15;i>0;i--){
		ListInsert_Sq(&b,1,i);
	}
	PrintList_Sq(a);
	PrintList_Sq(b);
	MergeList_Sq(a,b,&c);
	PrintList_Sq(c);
}

