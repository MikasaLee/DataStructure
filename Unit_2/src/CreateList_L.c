/**
 * 算法2.11：逆位序输入n个元素的值，建立一个从表尾到表头的线性链表
 */
#include "LinkList.c"

Status CreateList_L(LinkList *L,int n){
	//L为指向线性链表的指针，n为输入的n个元素
	if(n<0){
		printf("\n输入的个数不能为负\n");
		return ERROR;
	}
	if(InitList_L(L)){
		ElemType e;
		int i = 0;
		while( i!= n){
			printf("请输入第%d个数:",i+1);
			scanf("%d",&e);
			ListInsert_L(*L,1,e);	//插入操作
			i++;	
		}
	}else{
		printf("Error: File CreateList_L: 14");
		return ERROR;
	}

}
