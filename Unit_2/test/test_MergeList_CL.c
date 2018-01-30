#include "../src/MergeList_CL.c"
void main(){
	CLinkList a,b,c;
	int i,j=1;
	InitList_CL(&a);
	InitList_CL(&b);

	printf("\n没有归并前：\n");
	//交换ab再次验证
	for(i = 0;i<10;i+=2){
		ListInsert_CL(b,j++,i);
	}
	Print_CL(b);
	j =1;
	for(i = -5;i<5;i++){
		ListInsert_CL(a,j++,i);
	}
	Print_CL(a);
	printf("\n归并后：\n");
	MergeList_CL(&a,&b,&c);
	Print_CL(a);
	Print_CL(b);
	Print_CL(c);
}
