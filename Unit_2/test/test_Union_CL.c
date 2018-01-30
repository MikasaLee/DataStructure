#include "../src/Union_CL.c"
void main(){
	CLinkList a,b;
	int i,j=1;
	InitList_CL(&a);
	InitList_CL(&b);
	for(i = 0;i<10;i+=2){
		ListInsert_CL(a,j++,i);
	}
	j = 1;
	for(i = -5;i<5;i++){
	       	ListInsert_CL(b,j++,i);
	}
	Union_CL(&a,&b);
	Print_CL(a);
	Print_CL(b);
}
