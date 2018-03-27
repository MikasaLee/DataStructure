#include "../src/Queue.c"

int main(int argc,char **args){
	Queue q;
	int i,j;
	ElemType e;
	if(InitQueue(&q)){
		for(i = 0;i<10;i++){
			if(QueueEmpty(q))	printf("队列为空\n");
			EnQueue(q,64+i);
		}
		QueueTraverse(q,visit1);
		printf("队列的长度为：%d\n",QueueLength(q));
		DeQueue(q,&e);
		QueueTraverse(q,visit1);
		if(QueueEmpty(q))	printf("队列为空\n");
		printf("队列的长度为：%d\n",QueueLength(q));
		printf("删除的元素为：%c\n",e);
		
		for(i = 0 ;i<10;i++){
			DeQueue(q,&e);
			QueueTraverse(q,visit1);
			if(QueueEmpty(q))	printf("队列为空\n");
			printf("队列的长度为：%d\n",QueueLength(q));
			printf("删除的元素为：%c\n",e);
		}
		
		/**
		ClearQueue(q);
		QueueTraverse(q,visit);
		if(QueueEmpty(q))	printf("队列为空\n");
		printf("队列的长度为：%d\n",QueueLength(q));
		**/
	}
}
