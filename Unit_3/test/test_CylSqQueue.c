#include "../src/CylSqQueue.c"

int main(int argc,char **args){
	CylSqQueue q;
	int i,j;
	ElemType e;
	if(InitCylSqQueue(&q)){
		for(i = 0;i<10;i++){
			if(CylSqQueueEmpty(q))	printf("队列为空\n");
			EnCylSqQueue(q,64+i);
		}
		CylSqQueueTraverse(q,visit);
		printf("队列的长度为：%d\n",CylSqQueueLength(q));
		DeCylSqQueue(q,&e);
		CylSqQueueTraverse(q,visit);
		if(CylSqQueueEmpty(q))	printf("队列为空\n");
		printf("队列的长度为：%d\n",CylSqQueueLength(q));
		printf("删除的元素为：%c\n",e);
	
		for(i = 0 ;i<10;i++){
			GetHead_CSQ(q,&e);
			printf("队列第一个元素为：%c\n",e);
			DeCylSqQueue(q,&e);
			CylSqQueueTraverse(q,visit);
			if(CylSqQueueEmpty(q))	printf("队列为空\n");
			printf("队列的长度为：%d\n",CylSqQueueLength(q));
			printf("删除的元素为：%c\n",e);
			printf("\n");
		}
		
	/**
		ClearCylSqQueue(q);
		CylSqQueueTraverse(q,visit);
		if(CylSqQueueEmpty(q))	printf("队列为空\n");
		printf("队列的长度为：%d\n",CylSqQueueLength(q));
	**/
	}
}
