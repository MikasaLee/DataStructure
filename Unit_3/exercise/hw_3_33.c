/**
 * 3.33 在顺序存储结构上实现输出受限的双端循环队列的入列和出列（只允许队头出列）算法。设每个元素表示一个待处理的作业，元素值表示作业的预计时间。
 * 入队列采取简化的短作业优先原则，若一个新提交的作业的预计执行时间小于队头和队尾作业的平均时间，则插入在队头，否则插入在队尾。
 */
#ifndef HW_3_33_C
#define HW_3_33_C
typedef int ElemType;
#include "../src/CylSqQueue.h"
#include "../src/CylSqQueue.c"

Status EnQueue_3_33(CylSqQueue q,ElemType e);	//重写入队列函数
Status EnQueue_3_33(CylSqQueue q,ElemType e){
	if(!q) exit(OVERFLOW);
	if((q -> tail + 1 + MAX_SIZE)%MAX_SIZE == q -> head)	return ERROR;
	if((q -> base[q -> head] + q -> base[(q -> tail - 1 +MAX_SIZE)%MAX_SIZE])/2 < e){
		q -> base[q -> tail] = e;
		q -> tail = (q -> tail +1 + MAX_SIZE)%MAX_SIZE;
	}else{
		q -> head = (q -> head -1 + MAX_SIZE)%MAX_SIZE;
		q -> base[q -> head] = e;
	}
	return OK;

}
Bool visit1(ElemType e){
	printf("%d ",e);
	return TRUE;
}


int main(int argc,char **args){
	CylSqQueue cq;
	ElemType e[20] = {1,23,23536,45,6,32,4,536,23,64,345,435};
	int i;
	if(InitCylSqQueue(&cq)){
		for(i = 0;i<10;i++){
			EnQueue_3_33(cq,e[i]);
		}
		CylSqQueueTraverse(cq,visit1);
		printf("\n");
	}
	return 0;
}
#endif
