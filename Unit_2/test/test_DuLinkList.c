#include "../src/DoubleLinkList.c"
void main(){
	DuLinkList L;
	int i,j;
	ElemType e[6]={1,3,-1,-2,5,4},e1;
	printf("\n------测试IninList_DL(DuLinkList *DL)----------\n");
	if(InitList_DL(&L)){
		printf("\n构造双向链表成功！\n");
		Print_DL(L);
	}else{
		printf("\n构造双向链表失败！\n");
		exit(OVERFLOW);
	}

	printf("\n------测试ListInsert_DL(DuLinkList DL,int i,ElemType e)----------\n");
	for(i=0;i<6;i++)			
		ListInsert_DL(L,ListLength_DL(L)+1,e[i]);	//往最后插入
	ListInsert_DL(L,1,e[0]);		//往头插入
	ListInsert_DL(L,3,0);			//往中间插入
	Print_DL(L);

	printf("\n------测试GetElem_DL(DuLinkList DL,int i,ElemType *e)----------\n");
	for(i = 0; i< 10 ;i++)	//同时测出了超过范围的，第一个，中间的，最后的
		if(GetElem_DL(L,i,&e1))
				printf("第%d个节点的data值为%d\n",i,e1);
	
	printf("\n------测试LocateElem_DL(DuLinkList DL,ElemType e,Bool (*compare)(ElemType,ElemType))----------\n");
	printf("data为1的节点位序是:%d\n",LocateElem_DL(L,1,equals));
	printf("data为-2的节点位序是:%d\n",LocateElem_DL(L,-2,equals));
	printf("data为4的节点位序是:%d\n",LocateElem_DL(L,4,equals));
	printf("data为404的节点位序是:%d\n",LocateElem_DL(L,404,equals));

	printf("\n------测试PriorElem_DL(DuLinkList DL,ElemType cur_e,ElemType *pre_e)----------\n");
	if(PriorElem_DL(L,1,&e1))
		printf("data为1的前一个节点的data为:%d\n",e1);
	if(PriorElem_DL(L,4,&e1))
		printf("data为4的前一个节点的data为:%d\n",e1);
	if(PriorElem_DL(L,404,&e1))
		printf("data为404的前一个节点的data为:%d\n",e1);

	printf("\n------测试NextElem_DL(DuLinkList DL,ElemType cur_e,ElemType *next_e)----------\n");
	if(NextElem_DL(L,1,&e1))
		printf("data为1的后一个节点的data为:%d\n",e1);
	if(NextElem_DL(L,4,&e1))
		printf("data为4的后一个节点的data为:%d\n",e1);
	if(NextElem_DL(L,404,&e1))
		printf("data为404的后一个节点的data为:%d\n",e1);

	printf("\n------测试ListTraverse_DL(DuLinkList DL,Bool (*visit)(ElemType))----------\n");
	if(ListTraverse_DL(L,visit))
		printf("\nListTraverse_DL is OK!\n");

	printf("\n------测试ListDelete_DL(DuLinkList DL,int i,ElemType *e)----------\n");
	printf("\n打印未删除前的双向链表：\n");
	Print_DL(L);
	if(ListDelete_DL(L,1,&e1)){
		printf("删除的节点的data为:%d\n",e1);
		printf("打印删除第一个节点的双向链表:\n");
		Print_DL(L);
	}
	if(ListDelete_DL(L,ListLength_DL(L),&e1)){
		printf("删除的节点的data为:%d\n",e1);
		printf("打印删除最后一个节点的双向链表:\n");
		Print_DL(L);
	}
	if(ListDelete_DL(L,3,&e1)){
		printf("删除的节点的data为:%d\n",e1);
		printf("打印删除第三个的双向链表:\n");
		Print_DL(L);
	}
/**	ClearList_DL和DestroyLisy_DL函数分开测试
	printf("\n------测试ClearList_DL(DuLinkList *DL)----------\n");
	if(!ListEmpty_DL(L))
		ClearList_DL(&L);
	if(ListEmpty_DL(L)){
		printf("\n清空成功！\n");
		Print_DL(L);
	}
**/
	printf("\n------测试DestroyList_DL(DuLinkList *DL)----------\n");
	DestroyList_DL(&L);
	if(!L)
		Print_DL(L);
}		
