#include "../src/Union_DL.c"
void main(){
	DuLinkList a,b;
	int i,j=1;
	InitList_DL(&a);
	InitList_DL(&b);
	for(i = 0;i<10;i+=2){
		ListInsert_DL(a,j++,i);
	}
	j = 1;
	for(i = -5;i<5;i++){
	       	ListInsert_DL(b,j++,i);
	}
	Union_DL(&a,&b);
	Print_DL(a);
	Print_DL(b);
}
