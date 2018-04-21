#include "../src/SqList.c"
Bool max(ElemType a,ElemType b){
	return a<b?TRUE:FALSE;
}
Bool isLess_Than100(ElemType e){
	if(e<100)
		return TRUE;
	return FALSE;

}
void main(){

	SqList L;
	ElemType e;
	int i;

	//测试InitList_Sq(&L)
	printf("\n-------测试InitList_Sq(&L)----------\n");
	if(InitList_Sq(&L)){
		printf("初始化线性表成功\n");
		PrintList_Sq(L);
	}
	else
		printf("初始化线性表失败\n");

	//测试ListInsert_Sq(&L,i,e)
	printf("\n-------测试ListInsert_Sq(L,i,e)----------\n");
	for(i = -10 ; i< 10 ;i++){
		ListInsert_Sq(L,1,i);		//逆序插入
	}
	for(i = 1 ; i< 4 ;i++){
		ListInsert_Sq(L,i,i*123-89);		//往开始端插入
	}
	ListInsert_Sq(L,ListLength_Sq(L)+1,i*123-89);		//往最后插入,插入的位置为：在第二个参数的位置之前。也就是数组下标为[第二个参数的值减-1]的位置为插入的元素，原来该位置及后面的元素后移一位。
	PrintList_Sq(L);



	printf("\n-------测试ListDelete(&L,i,&e)----------\n");
	ListDelete_Sq(L,1,&e);			//删第一个
	printf("\n%d---\n",e);
	PrintList_Sq(L);
	ListDelete_Sq(L,7,&e);			//删中间的
	printf("\n%d---\n",e);
	PrintList_Sq(L);
	ListDelete_Sq(L,ListLength_Sq(L),&e);			//删最后一个
	printf("\n%d---\n",e);
	PrintList_Sq(L);

/**
	printf("\n-------测试ClearList(L)----------\n");
	if(ClearList_Sq(L)){
		printf("清空操作成功\n");
	}
	
	printf("\n-------测试ListEmpty(L)----------\n");
	if(ListEmpty_Sq(L)){
		printf("线性表为空\n");
	}

	PrintList_Sq(L);
**/
	
	printf("\n-------测试GetElem(L,i,&e)----------\n");
	if(GetElem_Sq(L,22,&e)){
		printf("%d\n",e);
	}
	else
		printf("Get ERROR");
	PrintList_Sq(L);


	printf("\n-------测试LocateElem(L,e,compare())---------\n");
	printf("该线性表中第一个比100大的数是第%d个",LocateElem_Sq(L,100,max));
	
	printf("\n-------测试PriorElem_Sq(L,cur_e,&pre_e)---------\n");
	if(PriorElem_Sq(L,403,&e))		//403还需要测试成-10,-9,157,280
		printf("\n该线性表中，元素的前驱为%d",e);
	else
		printf("\n不存在该元素或者该元素为第一个");

	printf("\n-------测试NextElem_Sq(L,cur_e,&next_e)---------\n");
	if(NextElem_Sq(L,-9,&e))		//403还需要测试成-10,-9,157,280
		printf("\n该线性表中，元素的后继为%d",e);
	else
		printf("\n不存在该元素或者该元素为最后一个");
	
	printf("\n-------测试ListTreverse_Sq(L,visit())---------\n");
		if(ListTraverse_Sq(L,isLess_Than100)){
			printf("该线性表所有的值都小于100");
		}
		else
			printf("该线性表存在比100大的值");

}

