/**
 * 循环队列的实现
 */
#ifndef CYLSQQUEUE_C
#define CYLSQQUEUE_C
#include "CylSqQueue.h"

Status InitCylSqQueue(CylSqQueue *q){
	(*q) = (CylSqQueue)malloc(sizeof(cylSqQueue));
	if(!(*q))	exit(OVERFLOW);
	(*q) -> base = (ElemType *)malloc(sizeof(ElemType)*MAX_SIZE);
	if(!((*q) ->base))	exit(OVERFLOW);
	(*q) -> head = (*q) -> tail = 0;
	return OK;
}

Status DestroyCylSqQueue(CylSqQueue *q){
	if(!(*q))	return OK;
	free((*q)->base);
	free(*q);
	(*q) = NULL;
	return OK;
}

Status ClearCylSqQueue(CylSqQueue q){
	if(!q)	exit(OVERFLOW);
	q -> head = q -> tail = 0;
	return OK;
}

Bool CylSqQueueEmpty(CylSqQueue q){
	if(!q)	exit(OVERFLOW);
	return q -> head == q -> tail?TRUE:FALSE;
}

int CylSqQueueLength(CylSqQueue q){
	if(!q)	exit(OVERFLOW);
	return (q -> tail - q -> head + MAX_SIZE)%MAX_SIZE;
}

Status GetHead_CSQ(CylSqQueue q,ElemType *node){
	if(!q)	exit(OVERFLOW);
	if(CylSqQueueEmpty(q)){
		(*node) = '\0';
		return OK;
	}
	(*node) = q -> base[q -> head];
	return OK;
}

Status EnCylSqQueue(CylSqQueue q,ElemType e){
	if(!q)	exit(OVERFLOW);
	if((q -> tail + 1 + MAX_SIZE)%MAX_SIZE == q -> head){
		printf("循环队列已满,添加失败！\n");
		return ERROR;
	}
	q -> base[q -> tail] = e;
	q -> tail = (q -> tail + 1 + MAX_SIZE)%MAX_SIZE;
	return OK;
}

Status DeCylSqQueue(CylSqQueue q,ElemType *e){
	if(!q)	exit(OVERFLOW);
	if(CylSqQueueEmpty(q)){
		printf("\n循环队列为空，删除失败\n");
		return ERROR;
	}
	(*e) = q -> base[q -> head];
	q -> head = (q -> head + 1 + MAX_SIZE)%MAX_SIZE;
	return OK;
}
Status CylSqQueueTraverse(CylSqQueue q,Bool visit(ElemType)){
	int i;
	if(!q)	exit(OVERFLOW);
	i = q -> head;
	while(i != q -> tail){
		if(!visit(q->base[i]))	return FALSE;
		i = (i+1)%MAX_SIZE;
	}
	return TRUE;
}
Bool visit(ElemType e){
	printf("%c ",e);
	return TRUE;
}
#endif
