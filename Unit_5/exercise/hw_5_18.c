/*************************************************************************
	> File Name: hw_5_18.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sun 27 May 2018 06:00:07 PM CST
 ************************************************************************/

//5.18 设计一个算法，将数组An中的元素A[0]至A[n-1]循环右移k位，并要求只用一个元素大小的附加存储，元素移动或交换次数为O(n)。

#include "../../Unit_1/src/myDefine.c"

#ifndef ELEMTYPE
#define ELEMTYPE
typedef int ElemType;
#endif

void reverse(ElemType arr[],int start,int end);
void print(ElemType arr[],int len);
void hw_5_18(ElemType arr[],int len,int k){
	if(k < 1) return;

	reverse(arr,0,len);

	reverse(arr,0,k);
	
	reverse(arr,k,len);
	
	return;
}

//逆序[start,end)
void reverse(ElemType arr[],int start,int end){
	ElemType temp;int i;
	for(i = 0;i<(end-start)/2;i++){
		temp = arr[start+i];
		arr[start+i] = arr[end-i-1];
		arr[end-i-1] = temp;
	}
}

void print(ElemType arr[],int len){
	int i;
	printf("[");
	for(i = 0;i<len-1;i++) printf("%d,",arr[i]);
	printf("%d]\n",arr[i]);
	return;
}

int main(int argc,char **argv){
	ElemType arr[10];
	int i,len=10;
	for(i = 0;i<len;i++){
		arr[i] = i;
	}
	print(arr,len);
	hw_5_18(arr,len,3);
	print(arr,len);

	return OK;
}
