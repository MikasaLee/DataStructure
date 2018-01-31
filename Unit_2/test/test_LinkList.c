#include "../src/LinkList.c"

void main(){
	LinkList L;
	ElemType e;
	int i,j;
	printf("\n------测试InitList_L(&L)--------\n");
	if(InitList_L(&L)){
		Print_L(L);
		printf("创建成功");
	
	}
	
	printf("\n------测试ListInsert_L(L,i,e)--------\n");
	for(i= -10;i<10;i++){
		ListInsert_L(L,1,i);
	}
	ListInsert_L(L,ListLength_L(L)+1,1000);	//往最后插入
	Print_L(L);

	printf("\n------测试PriorElem_L(*L,e,&pre_e)--------\n");
	//2018-1-31更新PriorElem_L的一个Bug。如果第一个节点的data = 第二个节点的data = cur_e，会得到错误的结果
	ListInsert_L(L,1,9);
	if(PriorElem_L(L,9,&e))		printf("data为9的前一个data为:%d\n",e);
	else printf("不存在data为9的节点,或者9为第一个节点\n");
	if(PriorElem_L(L,1000,&e))		printf("data为1000的前一个data为:%d\n",e);
	else printf("不存在data为1000的节点，或者1000为第一个节点\n");
	if(PriorElem_L(L,6,&e))		printf("data为6的前一个data为:%d\n",e);
	else printf("不存在data为6的节点，或者6为第一个节点\n");

	printf("\n------测试NextElem_L(*L,e,&next_e)--------\n");
	if(NextElem_L(L,9,&e))		printf("data为9的后一个data为:%d\n",e);
	else printf("不存在data为9的节点,或者9为最后一个节点\n");
	if(NextElem_L(L,1000,&e))		printf("data为1000的后一个data为:%d\n",e);
	else printf("不存在data为1000的节点，或者1000为最后一个节点\n");
	if(NextElem_L(L,6,&e))		printf("data为6的后一个data为:%d\n",e);
	else printf("不存在data为6的节点，或者6为最后一个节点\n");


	printf("\n------测试LocateElem_L(*L,e,compare(ElemType,ElemType))--------\n");
	printf("第一个比5小的节点:%d",LocateElem_L(L,5,max));
	//找出L链表中节点最小的data的下标
	ListInsert_L(L,1,100);
	ListInsert_L(L,ListLength_L(L)+1,100);
	ListInsert_L(L,4,101);
	
	Print_L(L);
	j = i = 1;
	while(1){
		GetElem_L(L,i,&e);
		j = i;
		i = LocateElem_L(L,e,max);
		if(!i){
			printf("最小的data是第%d个节点，值为%d\n",j,e);
			break;
		}
	}
	printf("\n------测试ListTraverse_L(L,visit)--------\n");
	if(ListTraverse_L(L,visit)){
		printf("\nTraverse()返回OK\n");
	}else 	printf("\nTraverse()返回ERROR\n");

	printf("\n------测试ListDelete_L(L,i,&e)--------\n");
	//分别测试删除第一个，中间任意一个和最后一个
	ListDelete_L(L,ListLength_L(L),&e);
	Print_L(L);
	printf("删除的元素值为：%d",e);
	ListDelete_L(L,1,&e);
	Print_L(L);
	printf("删除的元素值为：%d",e);
	ListDelete_L(L,ListLength_L(L)/2,&e);
	Print_L(L);
	printf("删除的元素值为：%d",e);

	
	printf("\n------测试GetElem_L(L,i,&e)--------\n");
	if(GetElem_L(L,1,&e)) 	printf("第一个节点的data：%d\n",e);
	if(GetElem_L(L,ListLength_L(L)/2,&e)) 	printf("中间节点的data：%d\n",e);
	if(GetElem_L(L,ListLength_L(L),&e)) 	printf("最后一个节点的data：%d\n",e);
	
	printf("\n------测试ListEmpty(L)--------\n");
	if(ListEmpty_L(L)){
		printf("链表为空!\n");
	}else{
		printf("链表不为空!\n");
	}
	printf("\n------测试ListLength_L(L)--------\n");
		printf("该链表的长度为：%d\n",ListLength_L(L));
	
	printf("\n------测试ClearList_L(&L)--------\n");
	if(ClearList_L(&L)){
		Print_L(L);		//输出链表不存在
		printf("清空成功");
	}
	printf("\n------测试DestroyList_L(&L)--------\n");
	if(DestroyList_L(&L)){
		Print_L(L);		//输出链表不存在
		printf("销毁成功");
	}
}
