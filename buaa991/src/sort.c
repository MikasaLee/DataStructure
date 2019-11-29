/*************************************************************************
	> File Name: sort.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Fri 29 Nov 2019 10:36:56 PM CST
 ************************************************************************/

/**
 * 假设长度为n的顺序表A[1..n]中每个数据元素为一整数，请写出按照下列思想将表中数据元素
 * 按值从小到大进行排序的算法：第一趟排序将最小值元素放在A[1]中，最大值元素放在A[n]，
 * 第二趟排序将最小值元素放在A[2]中，最大值元素放在A[n-1]中...依次下去，直至排序结束
 */

#include "stdio.h"

void sort(int *,int);
int main(int argc,char **argv){

	int A[12] = {0,1,3,34,24,5,23,645,2,45,25,6},i;	//第一个元素不考虑,总长度为11
	sort(A,11);
	for(i = 1;i<12;i++) printf("%d ",A[i]);
	printf("\n");
	return 0;
}

void sort(int A[],int n){		//1..n

	int min,max,head,rear,i,temp;
	head = 1;
	rear = n;
	while(head <= rear){
		for(max = min = head,i=head+1;i<=rear;i++){
			if(A[max] < A[i]) max = i;
			if(A[min] > A[i]) min = i;
		}

		//将最小值放到前面
		temp = A[head];
		A[head] = A[min];
		A[min] = temp;

		//将最大值放到后面
		if(head != max){   //***********************！！！！！！！！！！！！！！！！
			temp = A[rear];
			A[rear] = A[max];
			A[max] = temp;
		}else{
			temp = A[rear];
			A[rear] = A[min];
			A[min] = temp;
		}
		head++;
		rear--;
	
	}
}
