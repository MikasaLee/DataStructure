/*************************************************************************
	> File Name: printLastK.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 19 Nov 2019 10:25:55 PM CST
 ************************************************************************/
/**
 * 请写一算法，依次输出通过键盘输入的一组整型数据中的最后k个元素
 * 约定：以Ctrl+z作为键盘输入的结束，并假设k小于等于输入元素的个数
 * 限制：算法中不允许使用数组，也不允许有计算输入数据个数的过程
 */

/** 
 * 说白了就是让用链表+头尾指针来操作
 * (Linux中Ctrl+d表示向scanf输入EOF windows中为Ctrl+z)
 */

#include "stdio.h"
#include "stdlib.h"


typedef struct Node{
	int data;
	struct Node *next;
} Node,*LinkList;

int main(int argc,char **argv){

	LinkList p,head,rear;
	int k,i,n;
	printf("请输入k:");
	scanf("%d",&k);
	
	if((p = (LinkList)malloc(sizeof(Node))) == NULL) exit(1);
	head = rear = p;

	printf("请输入整型数据:\n");

	for(i = 1;i<k;i++){
		scanf("%d",&n);
		rear -> next = (LinkList)malloc(sizeof(Node));
		rear = rear -> next;
		rear -> data = n;
		rear -> next = NULL;
	}

	while(scanf("%d",&n) > 0){
		rear -> next = (LinkList)malloc(sizeof(Node));
		rear = rear -> next;
		rear -> data = n;
		rear -> next = NULL;
		head = head -> next;
	}
	
	printf("\n最后%d个数为：\n",k);
	while(head != NULL){
		printf("%d ",head -> data);
		head = head -> next;
	}

	return 0;
}
