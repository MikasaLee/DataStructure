/*************************************************************************
	> File Name: pugre.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sun 24 Nov 2019 09:35:50 PM CST
 ************************************************************************/

/**
 * 下列算法的功能是删除长度为n的顺序表A中重复出现的多余元素，即对于重复出现的多余元素，即对于重复出现的元素，表中只保留一个。请在算法的空白处填上必要的内容，使算法完整
 */
/** 
 * 直接用数组来代替顺序表 ，这个填空题主要是看k=j还是k=j+1（参考答案是前者，但是明显不对，特此验证一下）
 */
#include "stdio.h"

int pugre(int A[],int n){
	int i=0,j,k;
	while(i<n){
		j = i+1;
		while(j<n)
			if(A[j] == A[i]){
//				for(k=j;k<n;k++)
				for(k=j+1;k<n;k++)
					A[k-1] = A[k];
				n--;
			}else
				++j;
		++i;
	}

}
int main(int argc,char **argv){

	int a[12]={1,2,3,4,5,6,7,2,4,8,9,0},i;
	for(i = 0;i<12;i++)
		printf("%d ",a[i]);
	printf("\n");
	pugre(a,12);
	for(i = 0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
}

