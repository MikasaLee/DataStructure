
#ifndef QUEUE_C
#define QUEUE_C

#include "Queue.h"

Status InitQueue(Queue *q){
	(*q) = (Queue)malloc(sizeof(queue));
	if(*q){
		(*q) -> head = (*q) -> tail = NULL;	
		return OK;
	}
	exit(OVERFLOW);
}	

Status DestroyQueue(Queue *q){
	Node p,temp;
	if(!(*q))	return OK;
	p = (*q) -> head;
	while(p != NULL){
		temp = p;
		p = p -> next;
		free(temp);
	}
	free((*q));
	(*q) = NULL;
	return OK;
}

Status ClearQueue(Queue q){
	Node p,temp;
	if(!q)	return ERROR;
	p = q -> head;
	while(p !=NULL){
		temp = p;
		p = p -> next;
		free(temp);
	}
	q -> head = q -> tail = NULL;
	return OK;
}

Bool QueueEmpty(Queue q){
	if(!q)	return ERROR;
	return q -> head == NULL?TRUE:FALSE;
}

int QueueLength(Queue q){
	Node p;
	int i;
	if(!q)	return ERROR;
	p = q -> head;
	i = 0;
	while(p != NULL){
		p = p -> next;
		i++;
	}
	return i;
}

Status GetHead(Queue q,ElemType *node){
	if(!q)	return ERROR;
	(*node) = q -> head -> data;
	return OK;
}

Status EnQueue(Queue q,ElemType e){
	Node node;
	if(!q)	return ERROR;
	
	node = (Node)malloc(sizeof(node));
	node -> data = e;
	node -> next = NULL;
	if(q -> head == NULL){
	       	q -> head = q -> tail = node;
		return OK;
	}
	q -> tail -> next = node;
	q -> tail = node;
	return OK;
}

Status DeQueue(Queue q,ElemType *e){
	Node temp;
	if(!q)	return ERROR;

	if(QueueEmpty(q)){
		(*e) = 0;	//ElemType为结构体指针时返回NULL
	}else if(QueueLength(q) == 1){
		(*e) = q -> head -> data;
		free(q -> head);
		q -> head = q -> tail = NULL;
	}else{
		(*e) = q -> head -> data;
		temp = q -> head -> next;
		free(q -> head);
		q -> head = temp;
	}
	return OK;
}

Status QueueTraverse(Queue q,Bool visit(ElemType)){
	Node p;
	if(!q)	return ERROR;
	p = q -> head;
		
	while(p != NULL){
		if(!visit(p -> data))	return FALSE;
		p = p -> next;
	}
	return TRUE;
}

Bool visit1(ElemType e){
	printf("%c ",e);
	return TRUE;
}
#endif

