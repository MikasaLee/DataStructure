#ifndef SQLIST_C
#define SQLIST_C

#include "SqList.h"

Status InitList_Sq(SqList *L){
	(*L) = (sqList *)malloc(sizeof(sqList));
	if(*L){
		//对线性表进行初始化
		(*L)->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));	
		if(!((*L)->elem)){
			printf("ERROR:分配空间失败\n");	
			return ERROR;
		}
		(*L)->length = 0;
		(*L)->listsize = LIST_INIT_SIZE;
		return OK;
	}
	return ERROR;
}//InitList_Sq

Status DestroyList_Sq(SqList *L){
	if(!(*L)){
		printf("WARNNING:线性表不存在\n");
		return OK;
	}
	free((*L)->elem);				//free()函数只是释放内存，并不会把指针置为NULL
	free(*L);
	(*L) = NULL;
	return OK;
	
}//DestroyList_Sq

Status ClearList_Sq(SqList L){
	if(!L){
		printf("ERROR:线性表不存在\n");
		return ERROR;
	}
	L->length = 0;
	return OK;
}

Bool  ListEmpty_Sq(SqList L){
	return ListLength_Sq(L)?FALSE:TRUE;
}

int ListLength_Sq(SqList L){
	if(!(L -> elem)){
		printf("WARNNING：线性表为空\n");
		return 0;
	}
		
	return L -> length;
}

Status GetElem_Sq(SqList L,int i,ElemType *e){
	if(i < 1 || i > ListLength_Sq(L)){
		printf("ERROR:不存在第%d个元素",i);
		return ERROR;
	}
	(*e) = L -> elem[i-1];
	return OK;
}

int LocateElem_Sq(SqList L,ElemType e,Bool (*compare)(ElemType a,ElemType b)){
	int i;
	for(i=0;i<ListLength_Sq(L);i++){
		if(compare(e,L -> elem[i])){
			return i + 1;
		}
	}
	return 0;
}

Status PriorElem_Sq(SqList L,ElemType cur_e,ElemType *pre_e){
	int i;
	if(L -> elem == NULL || L -> length ==0){
		printf("ERROR:线性表为空");
		return ERROR;
	}
	for(i=1;i<ListLength_Sq(L);i++){
		if(cur_e == L -> elem[i]){
			(*pre_e) = L -> elem[i-1];
			return OK;
		}
	}
	
	pre_e = NULL;
	return ERROR;
}

Status NextElem_Sq(SqList L,ElemType cur_e,ElemType *next_e){
	int i;
	if(L -> elem == NULL || L -> length ==0){
		printf("ERROR:线性表为空");
		return ERROR;
	}
	for(i=0;i<ListLength_Sq(L)-1;i++){
		if(cur_e == L -> elem[i]){
			(*next_e) = L -> elem[i+1];
			return OK;
		}
	}
	
	next_e = NULL;
	return ERROR;
}

Status ListInsert_Sq(SqList L,int i,ElemType e){
	
	if(i<1 || i>ListLength_Sq(L)+1){
		printf("ERROR:不能往第%d个位置插入\n",i);
		return ERROR;
	}
	
	//容量是否足够？
	if(L -> length == L ->listsize){
	/*	以下写法不安全，如果分配失败也不知道
		L->elem =(ElemType *)realloc(L->elem,(L->listsize+LIST_INCREMENT)*sizeof(SqList));
	*/
	//改进：
		ElemType *newbase;
		newbase = (ElemType *)realloc(L->elem,(L->listsize+LIST_INCREMENT)*sizeof(ElemType));
		if(!newbase)	exit(OVERFLOW);		//没有分配成功
		L->elem = newbase;
		L->listsize +=LIST_INCREMENT;
	}

	//后移
	if(L->length < L->listsize){
	/**	这段代码有两个问题，
	 * 	1.当L->length的长度为0是，p为-1，那么L->elem[-1]报错没毛病
		2.移动的元素是[i,L->length],而本意应该是[i-1,L->length]	
	 	int p = L->length - 1 ;
		while(p != i-1 ){
			L->elem[p+1] = L->elem[p];
			p--;
		}
	**/
		int p = L->length;
	
		while(p != i-1){
			L->elem[p] = L->elem[p-1];
			p--;
		}
		L->elem[p] = e;
		L->length++;
		return OK;
	}
	return ERROR;
}
Status ListDelete_Sq(SqList L,int i,ElemType *e){
	if(i<1 || i>ListLength_Sq(L)){
		printf("ERROR:不存在第%d个元素，删除失败\n",i);
		return ERROR;
	}
	(*e) = L->elem[i-1];
	while(i!=L->length){
		L->elem[i-1] = L->elem[i];
		i++;
	}
	L->length--;
	return OK;
}

void PrintList_Sq(SqList L){
	int i;
	printf("\n该线性表的元素个数为：%d,\n该线性表的当前容量为：%d,\n",L -> length,L -> listsize);
	printf("元素分别为：[");
	for(i=0;i<L -> length;i++)
		printf("%d ",L -> elem[i]);
	printf("____%d ",L -> elem[i]);		//再输出L->elem[L->length]的值（当然实际上该值是无效的），用以判断
	printf("]\n");
}

Status ListTraverse_Sq(SqList L,Bool visit(ElemType e)){
	int i;
	for(i=0;i<ListLength_Sq(L);i++){
		if(!visit(L -> elem[i]))		//只要有一个元素调用失败，就ERROR
			return ERROR;
	}
	return OK;

}

#endif
