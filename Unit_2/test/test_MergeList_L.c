#include "../src/MergeList_L.c"
void main(){
	LinkList a,b,c;
	int i,j=1;
	InitList_L(&a);
	InitList_L(&b);

	for(i = 0;i<10;i+=2){
		ListInsert_L(a,j++,i);
	}
	j = 1;
	for(i = -5;i<5;i++){
		ListInsert_L(b,j++,i);
	}
	MergeList_L(&a,&b,&c);
	Print_L(a);
	Print_L(b);
	Print_L(c);
}
