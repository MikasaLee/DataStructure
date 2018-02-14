/**
 * 2.33❸ 已知由一个线性链表表示的线性表中含有三类字符的数据元素（如：字母字符、数字字符和其他字符），
 * 试编写算法将该线性链表分割为三个循环链表，其中每个循环链表表示的线性表中均只含一类字符。
 */
#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"
//没有头结点的单项循环链表
typedef char ElemType;
typedef struct NoHead_CLNode{			//借助hw_2_31的循环链表
	ElemType data;
	struct NoHead_CLNode *next;
}NoHead_CLNode,*NoHead_CL;

typedef struct temp_List{			//临时定义线性链表
	ElemType data;
	struct temp_List *next;
}temp_List,*temp_Link;

Status CreateTemp_L(temp_Link *L,int n,ElemType e[]){
	if(*L)	exit(OVERFLOW);
	int i;
	temp_Link p;
	(*L) = (temp_Link)malloc(sizeof(temp_List));
	(*L) -> data = 0;
	(*L) -> next = NULL;
	for(i=n-1;i>=0;i--){
		p = (temp_Link)malloc(sizeof(temp_List));
		p -> data = e[i];
		p -> next = (*L) -> next;
		(*L) -> next = p;	
	}
	return OK;
}
void Print_L(temp_Link L){
	temp_Link p;
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
			printf(" %d\t%c\t\t%d\n",p,p->data,p->next);
			p = p->next;
		}
		printf("-------------\t------------\t------------\n");
	}
	else printf("当前该链表为空链表");
	printf("\n");
}
Status Create_NHCL(NoHead_CL *L,int n,ElemType e[]){	//直接搞出一个满足题意的循环链表,要求L指向为NULL
	if(*L)	exit(OVERFLOW);
	int i = 0;
	NoHead_CL p = NULL,q = NULL;
	(*L) = (NoHead_CL)malloc(sizeof(NoHead_CLNode));
	if(*L){
		(*L) -> data = e[i];
		(*L) -> next = (*L);
		q = (*L);
		for(i = 1;i<n;i++){
			p = (NoHead_CL)malloc(sizeof(NoHead_CLNode));
			if(p){
				p -> data = e[i];
				q -> next = p;
				p -> next = (*L); 

				q = q -> next;
				p = NULL;
			}
		}
		return OK;

	}
	printf("\n申请空间失败！\n");
	return ERROR;
}

void Print(NoHead_CL L){
	NoHead_CL p;
	int i = 0;
	if(!L) exit(OVERFLOW);
	p = L -> next;
	i++;
	printf("\n---------------------------\n");
	printf("当前节点的地址\t当前节点的date\t当前节点的next\n");
	printf("--------------\t--------------\t--------------\n\n");
	printf("%d\t%c\t\t%d\n",L,L->data,L->next);
	while(p != L){
		printf("%d\t%c\t\t%d\n",p,p->data,p->next);
		p = p -> next;
		i++;
	}
	printf("--------------\t--------------\t--------------\n\n");

}
void hw_2_33(temp_Link L,int n,NoHead_CL *L_char,NoHead_CL *L_number,NoHead_CL *L_other){	//n为temp_Link的长度，不想写ListLength了，直接这样偷懒。。
	if(!L)	exit(OVERFLOW);
	ElemType sum_char[n],sum_number[n],sum_other[n];
	int i,j,k;
	i = j = k = 0;
	L = L -> next;
	while(L){
		if(L -> data >= '0' && L -> data <= '9'){
			sum_number[i] = L -> data;
			i++;
		}else if((L -> data >= 'a' && L -> data <= 'z') || (L -> data >= 'A' && L -> data <= 'Z')){
			sum_char[j] = L -> data;
			j++;
		}else{
			sum_other[k] = L -> data;
			k++;
		}
		L = L -> next;
	}
	Create_NHCL(L_char,j,sum_char);	//直接搞出一个满足题意的循环链表,要求L指向为NULL
	Create_NHCL(L_number,i,sum_number);	//直接搞出一个满足题意的循环链表,要求L指向为NULL
	Create_NHCL(L_other,k,sum_other);	//直接搞出一个满足题意的循环链表,要求L指向为NULL
}
void main(){
	temp_Link L = NULL;
	NoHead_CL L_char = NULL,L_number = NULL,L_other = NULL;
	ElemType e[6] = { '2','a','\\','?','0','S'};
	CreateTemp_L(&L,6,e);
	Print_L(L);
	hw_2_33(L,6,&L_char,&L_number,&L_other);
	Print_L(L);
	Print(L_char);
	Print(L_number);
	Print(L_other);
}
