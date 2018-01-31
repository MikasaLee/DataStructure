#include "../src/CircularLinkList.c"

void main(){
	CLinkList CL;
	int i,j;
	ElemType e[10] = {1,-1,12,32,13,23,444,-23,0,12},e1;
	
	printf("\n------------测试InitList_CL(CLinkList *CL)函数----------------\n");
	if(InitList_CL(&CL)){
		Print_CL(CL);
		if(ListEmpty_CL(CL) && (ListLength_CL(CL) == 0))	
			printf("\n构造线性循环链表成功\n");
	}

	printf("\n------------测试ListInsert_CL(CLinkList CL,int i,ElemType e)函数----------------\n");
	for(i=0;i<10;i++)
		ListInsert_CL(CL,i,e[i]);
	for(i=0;i<10;i++)
		ListInsert_CL(CL,ListLength_CL(CL)+1,e[i]);
	ListInsert_CL(CL,ListLength_CL(CL)+1,1001);
	Print_CL(CL);

	printf("\n------------测试GetElem_CL(CLinkList CL,int i,ElemType *e)函数----------------\n");
	for(i = 0;i<10;i++){
		if(GetElem_CL(CL,i,&e1))
			printf("第%d个的节点的data值为:%d\n",i,e1);
	}
	if(GetElem_CL(CL,ListLength_CL(CL),&e1)){
		printf("最后一个节点的data值为:%d\n",e1);
	}	
	
	printf("\n------------测试LocateElem_CL(CLinkList CL,ElemType e,Bool (*compare)(ElemType,ElemType))函数----------------\n");
	printf("data为1的节点位序是:%d\n",LocateElem_CL(CL,1,equals));
	printf("data为12的节点位序是:%d\n",LocateElem_CL(CL,12,equals));
	printf("data为123213的节点位序是:%d\n",LocateElem_CL(CL,123213,equals));
	
	printf("\n------------测试PriorElem_CL(CLinkList CL,ElemType cur_e,ElemType *pre_e)函数----------------\n");
	if(PriorElem_CL(CL,-1,&e1))
		printf("data为-1的前一个节点的data为：%d\n",e1);
	if(PriorElem_CL(CL,12,&e1))
		printf("data为12的前一个节点的data为：%d\n",e1);
	if(PriorElem_CL(CL,1000,&e1))
		printf("data为1000的前一个节点的data为：%d\n",e1);
	
	printf("\n------------测试NextElem_CL(CLinkList CL,ElemType cur_e,ElemType *next_e)函数----------------\n");
	if(NextElem_CL(CL,1000,&e1))
		printf("data为1000的后一个节点的data为：%d\n",e1);
	if(NextElem_CL(CL,12,&e1))
		printf("data为12的后一个节点的data为：%d\n",e1);
	if(NextElem_CL(CL,1001,&e1))
		printf("data为1001的后一个节点的data为：%d\n",e1);

	printf("\n------------测试ListTraverse_CL(CLinkList CL,Bool (*visit)(ElemType))函数----------------\n");
	if(ListTraverse_CL(CL,visit))
		printf("\nListTraverse_CL is OK!!\n");

	printf("\n------------测试ListDelete_CL(CLinkList CL,int i,ElemType *e)函数----------------\n");
	printf("删除前10个节点：\n");
	for(i=0;i<10;i++){
		if(ListDelete_CL(CL,1,&e1))
			printf("删除节点的data为:%d\n",e1);
	}
	Print_CL(CL);
/**	ClearList_CL和DestroyList_CL函数分开测试
	printf("\n------------测试ClearList_CL(CLinkList *CL)函数----------------\n");
	if(!ListEmpty_CL(CL))
		ClearList_CL(&CL);
	if(ListEmpty_CL(CL))
		Print_CL(CL);
**/
	printf("\n------------测试DestroyList_CL(CLinkList *CL)函数----------------\n");
	DestroyList_CL(&CL);
	if(!CL)
		Print_CL(CL);
}


