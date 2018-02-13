/**
 * 测试2.16 ~ 2.18的三个函数
 */
#include "stdio.h"
#include "stdlib.h"
#include "./NoHeadLinkList.h"
int ListLength_L(LinkList L){
	int i = 0;
	while(L){
		L = L -> next;
		i++;
	}
	return i;
}
void Print_L(LinkList L){
	LinkList p;
	if(!L)	return;
	p = L;
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
	return;
}
#include "./hw_2_16.c"
#include "./hw_2_17.c"
#include "./hw_2_18.c"
void main(){
	LinkList L,p,q;
	L = q = p = NULL;
	int i;
	printf("\n------------测试hw_2_17.c------------\n");
	for(i = 0;i<10;i++) hw_2_17(&L,ListLength_L(L)+1,i);
	Print_L(L);
	//往第一个位置插
	hw_2_17(&L,1,-100);
	Print_L(L);
	printf("\n-------------------------------------\n");

	printf("\n------------测试hw_2_18.c------------\n");
	//删除第一个：
	hw_2_18(&L,1);
	//删除最后一个
	hw_2_18(&L,ListLength_L(L));
	Print_L(L);
	printf("\n-------------------------------------\n");

	printf("\n------------测试hw_2_16.c------------\n");
	for(i = 0;i<10;i++) hw_2_17(&p,ListLength_L(p)+1,i);
	for(i = 0;i<10;i++) hw_2_17(&q,ListLength_L(q)+1,i);
	printf("\n\t原来的p和q:\n\n");
	Print_L(p);
	Print_L(q);
	//DeleteAndInsertSub(&p,&q,1,1,3);		//case 1：i == 1 && j == 1
	//DeleteAndInsertSub(&p,&q,1,2,3);		//case 2：i == 1 && j != 1
	//DeleteAndInsertSub(&p,&q,2,1,3);		//case 1：i != 1 && j == 1
	DeleteAndInsertSub(&p,&q,2,2,3);		//case 1：i != 1 && j != 1
	printf("\n\t操作后的p和q:\n\n");
	Print_L(p);
	Print_L(q);

}
