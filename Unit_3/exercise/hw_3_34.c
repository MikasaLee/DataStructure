/**
 * 3.34 假设在如教科书3.4.1节中图3.9所示的铁道转轨网的输入端有n节车厢：硬座、硬卧和软卧（分别以P，H和S表示）等待调度，要求这三种车厢在输出端铁道上的排列次序为：硬座（P）在前，软卧（S）在中，硬卧（H）在后
 * 	试利用输出受限（只允许队头出列）的双端队列对这n节车厢进行调度，编写算法输出调度的操作序列：分别以字符‘E’和‘D’表示对双端队列的头端进行入队列和出队列的操作；以字符A表示对双端队列的尾端进行入队列的操作。
 */

#ifndef HW_3_34_C
#define HW_3_34_C
#include "../src/Queue.h"
#include "../src/Queue.c"

Status hw_3_34();
Status hw_3_34(){
	ElemType e,str[81];
	Queue temp;
	Node node;
	int length,i = 0;
	printf("请输入任意数目的车厢(@为结束标记)：\n");
	while(scanf("%c",&e)){
		if(e == '@')	break;
		if(e != '\n')	str[i++] = e;
	}
	length = i;
	i = 0;
	if(InitQueue(&temp)){
		while(i != length){
			e = str[i];
			if(e == 'P'){	//硬座
				printf("E");	//头部入队列操作
				printf("D");	//头部出队列
			}else if(e == 'H'){	//硬卧
				EnQueue(temp,e);	//入队尾
				printf("A");
			}else if(e == 'S'){
				printf("E");	//头部入队列操作
				node = (Node)malloc(sizeof(node));
				node -> data = e;
				node -> next = temp -> head;
				temp -> head = node;
			}else{
				printf("不是PHS,程序失败退出!\n");
				exit(OVERFLOW);
			}
		i++;
		}//while
		//按顺序输出temp即可
		while(!QueueEmpty(temp)){
			DeQueue(temp,&e);
			printf("D");
		}
		return OK;
	}
	return ERROR;
}

int main(int argc,char **args){
	hw_3_34();	//重写入队列
	printf("\n");	
}
#endif
