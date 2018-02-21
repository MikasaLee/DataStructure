/**
 *  在2.34至2.36题中，“异或指针双向链表”类型XorLinkedList和指针异或函数XorP定义为：
 */
#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"
typedef char ElemType;
typedef struct XorNode{
	ElemType data;
	struct XorNode *LRPtr;
}XorNode, *XorPointer;

typedef struct{	//无头结点的异或指针双向链表
	XorPointer Left, Right;	//分别指向链表的左端和右端
}XorLinkedList,*XorLinkList;

XorPointer XorP(XorPointer p, XorPointer q); //指针异或函数XorP返回指针p和q的异或(XOR)值

//实现异或双向链表
Status InitList_Xor(XorLinkList *Xor){
	(*Xor) = (XorLinkList)malloc(sizeof(XorLinkedList));
	if(*Xor){
		XorLinkList p = (*Xor);
		p -> Left = p -> Right = NULL;
		return OK;
	}
	printf("\n申请空间失败！\n");
	return ERROR;
}
XorPointer XorP(XorPointer p, XorPointer q){ //指针异或函数XorP返回指针p和q的异或(XOR)值
	return (XorPointer)((unsigned long)p^(unsigned long)q);
}
int ListLength_Xor(XorLinkList Xor){
	int i;
	XorPointer p,temp,q;
	if(!Xor)	return -1;	//不存在返回-1
	p = Xor -> Left;
	q = NULL;
	i = 0;
	while(p){
		temp = p;
		p = XorP(q,p->LRPtr);
		q = temp;
		i++;
	}
	return i;
}
Status ListInsert_Xor(XorLinkList Xor,int i,ElemType e){
	if(!Xor || i<1 || i > ListLength_Xor(Xor)+1)	exit(OVERFLOW);
	int k;
	XorPointer p,q,temp,E;		//p为当前节点，q为前一跳
	E = NULL;
	E =(XorPointer)malloc(sizeof(XorNode));
	if(E){
		E -> data = e;
		p = Xor -> Left;
		q = NULL;
		if(p){
			if(i==1){
				E -> LRPtr = XorP(NULL,p);
				temp = XorP(NULL,p -> LRPtr);
				p -> LRPtr = XorP(E,temp);
				Xor -> Left = E;
				return OK;
			}
			k = 1;
			while(p && k!= i){
				temp = p;
				p = XorP(q,p -> LRPtr);
				q = temp;
				k++;
			}//while
			if(p){	//不是往最后插入
				//p为第i个节点，q为第i-1个节点
				E -> LRPtr = XorP(q,p);
				temp = XorP(q,p -> LRPtr);
				p -> LRPtr = XorP(E,temp);
				temp = XorP(p,q -> LRPtr);
				q -> LRPtr = XorP(E,temp);
			}else{	//往最后插入,p为NULL
				E -> LRPtr = XorP(q,NULL);
				temp = XorP(NULL,q -> LRPtr);
				q -> LRPtr = XorP(E,temp);
				Xor -> Right = E;
			}
		}else{
			Xor -> Right = Xor -> Left = E;
			E -> LRPtr = XorP(NULL,NULL);
		}
		return OK;
	}
	printf("\n申请空间失败！\n");
	return ERROR;
}

Status ListDelete_Xor(XorLinkList Xor,int i){	//删除第i个节点
	if(!Xor || i<1 || i > ListLength_Xor(Xor))	exit(OVERFLOW);
	int k;
	XorPointer p,q,temp;		//p为当前节点，q为前一跳
	p = Xor -> Left;
	q = NULL;
	k = 1;
	while(p && k!= i){		
		temp = p;
		p = XorP(q,p -> LRPtr);
		q = temp;
		k++;
	}
	//删除p节点
	if(i == 1){
		temp = p;		//temp指向第一个节点
		p = XorP(q,p->LRPtr);	//p指向第二个节点
		q = XorP(temp,p -> LRPtr);	//q指向第三个节点
		p -> LRPtr = (NULL,q);	//修改第二个节点的异或域
		Xor -> Left = p;
		free(temp);
	}else if(i == ListLength_Xor(Xor)){
		temp = p;		//temp指向最后一个节点
		p = XorP(p,q->LRPtr);	//p指向倒数第三个节点
		q -> LRPtr = XorP(p,NULL);
		Xor -> Right = q;
		free(temp);
	}else{
		temp = p;
		p = XorP(q,p-> LRPtr);
		q -> LRPtr = XorP(XorP(temp,q ->LRPtr),p);
		p -> LRPtr = XorP(q,XorP(temp,p -> LRPtr));
		free(temp);
	}
	return OK;
}
void PrintList(XorPointer Xor){
	XorPointer p,q,temp;	//p为当前节点，q为前一跳节点
	if(Xor){	
		p = Xor;	
		q = NULL;
		printf("当前节点的地址\t当前节点的data\t当前节点的Xor域\n");
		printf("--------------\t---------------\t--------------\n");
		while(p){
			printf(" %d\t%c\t\t%d\n",p,p->data,p -> LRPtr);
			temp = p;
			p = XorP(q,p ->LRPtr);
			q = temp;
		}
		printf("-------------\t---------------\t--------------\n");
	}
}
void ShowList(XorLinkList Xor,int direct){	//direct为方向 0为从左，非0从右
	if(Xor){
		printf("该异或链表的左节点为：%d\n",Xor -> Left);
		printf("该异或链表的右节点为：%d\n",Xor -> Right);
		if(direct == 0){
			printf("\n从左遍历该异或节点\n");
			PrintList(Xor -> Left);
		}
		else{
			printf("\n从右遍历该异或节点\n");
			PrintList(Xor -> Right);
		}
		printf("节点总数为：%d\n",ListLength_Xor(Xor));
		return;
	}
	exit(OVERFLOW);
}
void main(){
	XorLinkList xor;
	int i;
	if(InitList_Xor(&xor)){
		for(i = 1;i<10;i++)	ListInsert_Xor(xor,ListLength_Xor(xor)+1,'a'+i);
		ListInsert_Xor(xor,1,'z');
		ShowList(xor,0);
		ShowList(xor,1);
		ListDelete_Xor(xor,1);
		ShowList(xor,0);
		ShowList(xor,1);
		ListDelete_Xor(xor,ListLength_Xor(xor));
		ShowList(xor,0);
		ShowList(xor,1);
	}
}
