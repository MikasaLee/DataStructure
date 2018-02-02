#include "../src/ExtendLinkList.c"
void Print_ELNode(Link L);
void main(){
	ELinkList L,La,Lb;
	ElemType e[10] = {1,1,3,2,1,5,-1,0,-1,-1};
	ElemType ea[10] = {5,5,4,3,4,3,1,6,2,2};
	ElemType eb[10] = {-5,-5,-4,-3,-4,-3,-1,-6,-2,-2};
	Link p,q;
	int i;
	printf("\n-------------测试InitList_EL(ELinkList *L)----------------\n");
	if(InitList_EL(&L)){
		Print_EL(L);
	}else{
		printf("构造链表失败！\n");
	}
	
	printf("\n-------------测试InsFirst_EL(ELinkList L,Link s)函数----------------\n");
	for(i = 0;i<10;i++){
		MakeNode_EL(&p,e[i]);
		InsFirst_EL(L,p);
	}
	Print_EL(L);

	printf("\n-------------测试DelFirst_EL(ELinkList L,Link *s)函数----------------\n");
	for(i = 0;i<3;i++){
		DelFirst_EL(L,&p);
	}
	Print_EL(L);

	printf("\n-------------测试Append_EL(ELinkList La,ELinkList Lb,int begin)函数----------------\n");
	if(InitList_EL(&La) && InitList_EL(&Lb)){
		for(i = 0;i<10;i++){
		//分两次测试，当La为空时和La不为空时
			MakeNode_EL(&p,ea[i]);
			InsFirst_EL(La,p);
			MakeNode_EL(&p,eb[i]);
			InsFirst_EL(Lb,p);
		}
	
		if(Append_EL(La,Lb,3))
			Print_EL(La);
			Print_EL(Lb);
	}
	printf("\n-------------测试Remove(ELinkList *L,Link *q)函数----------------\n");
	for(i = 0;i<3 ;i++){
		Remove(L,&p);
		printf("\n删除节点的data为：%d\n",p->data);
	}
	Print_EL(L);

	printf("\n-------------测试InsBefore(LinkList L,Link *p,Link s)函数----------------\n");
	for(i = 0;i<10;i++){
		MakeNode_EL(&p,e[i]);
		InsFirst_EL(L,p);
	}
	Print_EL(L);
	MakeNode_EL(&p,100);
	
	q = L -> head;
	printf("\n原来的q的信息：\n");
	Print_ELNode(q);
	/**
	 * 注意InsBefore中的第二个参数不能直接写L->next这样，因为该函数会使得第二个参数的指针发生变化
	 */ 
	if(InsBefore_EL(L,&q,p)){	//往原来第一个位置前插入100
		Print_EL(L);
		printf("\n现在的q的信息：\n");
		Print_ELNode(q);
	}
	if(InsBefore_EL(L,&q,p)){	//往原来第二个位置前上插入100
		Print_EL(L);
		printf("\n现在的q的信息：\n");
		Print_ELNode(q);
	}

	printf("\n-------------测试InsAfter(LinkList L,Link *p,Link s)函数----------------\n");
	q = L -> head;
	MakeNode_EL(&p,-100);
	printf("\n原来的q的信息：\n");
	Print_ELNode(q);
	if(InsAfter_EL(L,&q,p)){	//往原来第一个位置后插入-100
		Print_EL(L);
		printf("\n现在的q的信息：\n");
		Print_ELNode(q);
	}
	if(InsAfter_EL(L,&q,p)){	//往原来第二个位置后插入-100
		Print_EL(L);
		printf("\n现在的q的信息：\n");
		Print_ELNode(q);
	}

	printf("\n-------------测试GetHead_EL(ELinkList L)函数----------------\n");
	Print_ELNode(GetHead_EL(L));

	printf("\n-------------测试GetLast_EL(ELinkList L)函数----------------\n");
	Print_ELNode(GetLast_EL(L));

	printf("\n-------------测试PriorPos_EL(List p)函数----------------\n");
	Print_ELNode(PriorPos(L->tail));

	printf("\n-------------测试NextPos_EL(List p)函数----------------\n");
	Print_ELNode(NextPos(L->head));
	
	printf("\n-------------测试LocateElem_EL(ELinkList L,ElemType e,Bool (*compare)(ElemType,ElemType))函数----------------\n");
	Print_ELNode(LocateElem_EL(L,100,equals));
	Print_ELNode(LocateElem_EL(L,2,equals));
	Print_ELNode(LocateElem_EL(L,112312,equals));

	printf("\n-------------测试LocatePos_EL(ELinkList L,int i, Link *p)函数----------------\n");
	if(LocatePos_EL(L,1,&p)){	//得到第一个节点
		Print_ELNode(p);
	}
	if(LocatePos_EL(L,3,&p)){	//得到中间的节点
		Print_ELNode(p);
	}
	if(LocatePos_EL(L,ListLength_EL(L),&p)){	//得到第一个节点
		Print_ELNode(p);
	}

	printf("\n-------------测试ListTraverse(LinkList L,Status (*visit)())函数----------------\n");
	if(ListTraverse_EL(L,visit))
		printf("\nOK!!!\n");
}

void Print_ELNode(Link L){
	if(!L){
		printf("\n该节点不存在!\n");
		return;
	}
       	printf("当前节点的地址 \t当前节点的data \t当前节点的prior \t当前节点的next\n");
	printf("--------------\t--------------\t---------------\t--------------\n");
	printf("%d\t%d\t\t%d\t%d\n",L,L->data,L->prior,L->next);
	printf("--------------\t--------------\t---------------\t--------------\n");
}
