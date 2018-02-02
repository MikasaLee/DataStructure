/**
 * 线性表的顺序表示和实现
 * 同时约定完全用C语言实现（不能用c++的引用）
 */
#include <stdio.h>
#include "../../Unit_1/src/myDefine.c"
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode{
	//数据域
	ElemType data;
	//指针域
	struct LNode * next;
} LNode,*LinkList;

//构造一个空的链表（构造head节点,并规定当ELemType为int/long类型时，头结点的data为当前的节点个数）
Status InitList_L(LinkList *L){
	(*L) = (LinkList)malloc(sizeof(LNode));
	if(!(*L))	exit(OVERFLOW);		//分配失败
	(*L) -> data = 0;
	(*L) -> next = NULL;
	return OK;
}

//销毁链表（包括头结点也销毁）
Status DestroyList_L(LinkList *L){
	while(*L){		
		LinkList p = *L;
		(*L) = (*L) -> next;
		free(p);
	}
	if(!(*L)){
		(*L) = NULL;		
		return OK;
	}
	printf("--------销毁操作失败！----------");
	return ERROR;	
}
Status ClearList_L(LinkList *L){
	if(!(*L)){
		printf("不是链表，清空失败！\n");
		return ERROR;
	}
	LinkList q = (*L) -> next;		//让q指向第一个节点
	while(q){		
		LinkList p = q;
		q = q -> next;
		free(p);
	}
	if(!q){				//清空成功！
		(*L) -> next = NULL;
		(*L) -> data = 0;
		return OK;
	}
	printf("--------清空操作失败！----------");
	return ERROR;	
}

//判断链表是否为空。
Bool ListEmpty_L(LinkList L){
	if(!(*L).data && !(*L).next){
		return TRUE;
	}
	return FALSE;
}

//返回L中节点的个数
int ListLength_L(LinkList L){
	LinkList p= L ->next;
	int i = 0;
	while(p){
		p = p->next;
		i++;
	}
	return i;
}
//返回第i个节点的数据域(注意：实际应用中最好是将数据域置为vector或者各种数据存储格式(xml,yaml,json...)有利于数据域的扩展，但是链表的考察点不在这里，故只有一个data意思意思就行了)
Status GetElem_L(LinkList L,int i,ElemType *e){
	int j = 0;
	LinkList p = L;
	if( i < 1 || i>ListLength_L(L)){
		printf("不存在第%d个节点",i);
		return ERROR;
	}
	while(j!=i){
		p = p->next;
		j++;
	}
	(*e) = p -> data;
	return OK;
}
//--------------------------------------------------
//LocateElem_L的compare函数,第一个参数是否比第二个参数大
Bool max(ElemType a,ElemType b){
	return a > b?TRUE:FALSE;
}
Bool equals(ElemType a,ElemType b){
	return a == b?TRUE:FALSE;
}

//返回第一个与e满足关系compare函数的L的节点的节点次序
int LocateElem_L(LinkList L,ElemType e,Bool (*compare)(ElemType a,ElemType b)){
	int i =1;
	LinkList p = L;
	p = p ->next;
	while(p && !compare(e,p -> data)){	//while里面的顺序不能乱，否则当p = NULL时， p->data溢出
		p = p ->next;
		i++;
	}
	if(p)	return i;	//找见了
	return 0;
}

//得到数据域是cur_e的前一个数据，赋值给pre_e,若不存在,pre_e = NULL;
Status PriorElem_L(LinkList L,ElemType cur_e,ElemType *pre_e){
	LinkList p,q;
	if(!L -> next){
		printf("-----该表为空表，操作失败-----\n");
		return ERROR;
	}
	p = L -> next;
	q = p -> next;
	//排除cur_e为第一个节点的数据域
	/**
	 * 2018-1-31更新：在写双向链表的测试函数时，发现一个Bug：
	 * 如果cur_e = 第一个节点的data = 第二个节点的data. 那么pre_e会指向第一个节点的data
	 * 但是实际情况应该是说明cur_e为第一个节点的data，不存在前一个节点。
	 */
	if(q && (p -> data == q -> data) && (cur_e == p ->data)){
		printf("\n%d为第一个节点，不存在前一个节点\n",cur_e);
		pre_e = NULL;
		return ERROR;
	}		
	while(q && q ->data != cur_e){
		p = q;
		q = q->next;
	}
	if(q){		//找见了
		(*pre_e) = p->data;
		return OK;
	}
	printf("！！！PriorElem_L():	表中不存在这个数据\n");
	pre_e = NULL;
	return ERROR;
}
//得到cur_e的下一个数据域，并返回给next_e
Status NextElem_L(LinkList L,ElemType cur_e,ElemType *next_e){
	LinkList p,q;
	if(!L -> next){
		printf("-----该表为空表，操作失败-----\n");
		return ERROR;
	}
	q = L -> next;
	p = q -> next;
	
	while(p && q -> data != cur_e){
		q = p;
		p = p -> next;
	}
	if(p){		//找见了
		(*next_e) = p -> data;
		return OK;
	}
	printf("！！！NextElem_L():	表中不存在这个数据\n");
	next_e = NULL;
	return ERROR;
}

//在第i个节点的位置上插入元素e
Status ListInsert_L(LinkList L,int i,ElemType e){
	LinkList p,q;
	int j;
	if(i<1 || i> (ListLength_L(L)+1)){
		printf("---插入位置值%d超出表的范围，插入失败---",i);
		return ERROR;
	}
	p = L;
	j = 0;
	while(j != i-1 ){	//指向第i-1个节点
		p = p->next;
		j++;
	}
	
	q = (LinkList)malloc(sizeof(LNode));
	q -> data = e;
	q ->next = p->next;
	p ->next = q;
	(L -> data)++;		//别忘了有规定当ElemType为int/long时，head节点的数据域为节点个数
	return OK;
}

Status ListDelete_L(LinkList L,int i,ElemType *e){
	LinkList p,q;
	int j;
	if(i<1 || i>ListLength_L(L)){
		printf("---删除位置值%d超出表的范围，删除失败---",i);
		return ERROR;
	}
	p = L;
	j = 0;

	while(j!= i-1){		//指向i-1个节点
		p = p->next;
		j++;
	}
	q = p -> next;
	p -> next = q -> next;
	(L ->data)--;		//规定

	(*e) = q ->data;
	free(q);
	return OK;
}
//---------------------
//visit()
Bool visit(ElemType e){
	printf("[");
	printf("%d",e);
	printf("]");
	return OK;
}

//ListTraverse_L(L,visit()),对线性表L的每个元素调用visit，一旦visit()失败，则操作失败
Status ListTraverse_L(LinkList L,Bool visit(ElemType e)){
	LinkList p = L;
	if(!p){
		printf("线性表不存在，Traverse操作失败！\n");
		return ERROR;
	}
	p = p -> next;
	while(p && visit(p -> data)){
		p = p->next;
	}
	if(!p)	return OK;
	return ERROR;
}




//显示链表
void Print_L(LinkList L){
	LinkList p;
	if(!L){
		printf("\n----链表不存在----\n");
		return;
	}
	printf("\nhead节点的data：%d\n",L->data);
	p = L->next;
	if(p){
		printf("当前节点的地址\t当前节点的data\t当前节点的next\n");
		printf("-------------\t------------\t------------\n");
		while(p){
			printf(" %d\t%d\t\t%d\n",p,p->data,p->next);
			p = p->next;
		}
		printf("-------------\t------------\t------------\n");
		printf("节点总数为：%d\n",ListLength_L(L));
	}
	else printf("当前该链表为空链表");
	printf("\n");
}
