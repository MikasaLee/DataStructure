#include "../src/MergeList_DL.c"
void main(){
	DuLinkList a,b,c;
	int i,j=1;
	InitList_DL(&a);
	InitList_DL(&b);

	printf("\n没有归并前：\n");
	//交换ab再次验证
	for(i = 0;i<10;i+=2){
		ListInsert_DL(b,j++,i);
	}
	Print_DL(b);
	j =1;
	for(i = -5;i<5;i++){
		ListInsert_DL(a,j++,i);
	}
	Print_DL(a);
	printf("\n归并后：\n");
	MergeList_DL(&a,&b,&c);
	Print_DL(a);
	Print_DL(b);
	Print_DL(c);
}
