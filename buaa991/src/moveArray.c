/*************************************************************************
	> File Name: moveArray.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sun 24 Nov 2019 10:06:18 PM CST
 ************************************************************************/

/**
 * 请设计一C语言程序，该程序的功能是用尽可能高的时间效率和空间效率将一个int
 * 类型的数组A[0..n-1]的所有元素一次循环右移k个位置
 *  例如 对于某数组 k=3时（即把数组所有元素循环右移3个位置）是将
 *   10 20 30 40 50 60 70  -->
 *   50 60 70 10 20 30 40
 */
#include "stdio.h"


/**
 * 先倒置前n-k个和后k个
 * 再倒置全部
 */

void reverse(int A[],int from,int to){
	int i,temp;
	for(i = 0;from+i<to-i;i++){
		temp = A[from+i];
		A[from+i] = A[to-i];
		A[to-i] = temp;
	}
}

int moveArray(int A[],int n,int k){
	reverse(A,0,n-k-1);
	reverse(A,n-k,n-1);
	reverse(A,0,n-1);
}

int main(int argc,char **argv){

	int k = 3,array[]={10,20,30,40,50,60,70},n=7,i;
	printf("\nbefore move：");
	for(i = 0;i<n;i++)
		printf("%d ",array[i]);
	moveArray(array,n,k);
	printf("\nafter move：");
	for(i = 0;i<n;i++)
		printf("%d ",array[i]);
	printf("\n");
	return 0;
}

