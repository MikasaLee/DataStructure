/*************************************************************************
	> File Name: SpiralArray.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Thu 14 Nov 2019 10:37:35 PM CST
 ************************************************************************/

/**
 * 请写一c语言程序，该程序对输入的任意正整数n，产生并且显示相应的n阶螺旋式数字方阵
 * 如 当n=5时 输出
 *	1  2  3  4  5
 *	16 17 18 19 6
 *	15 24 25 20 7
 *	14 23 22 21 8
 *  13 12 11 10 9
 */
#include "stdio.h"
#include "stdlib.h"


int main(int argc,char **argv){

	int n,i,j,k,direct = 0;	//direct为方向 0 1 2 3 -> 右 下 左 上 
	int **array;
	printf("请输入正整数n：");
	scanf("%d",&n);
	
	array = (int **)malloc(sizeof(int *)*n);
	for(i = 0;i<n;i++){			//初始化
		array[i] = (int *)malloc(sizeof(int)*n);
	}
	k = 1;
	i = j = 0;
	while(k <= n*n){
		array[i][j] = k++;
		
		//
		if((direct == 0) && ((j == n-1)|| array[i][j+1]!=0)) direct = 1;
		else if((direct == 1) && ((i == n-1)|| array[i+1][j]!=0)) direct = 2;
		else if((direct == 2) && ((j == 0)|| array[i][j-1]!=0)) direct = 3;
		else if((direct == 3) && ((i == 0)|| array[i-1][j]!=0)) direct = 0;

		switch(direct){
			case 0:++j;break;
			case 1:++i;break;
			case 2:--j;break;
			case 3:--i;break;
		}
	}
	for(i = 0;i<n;i++){			//初始化
		for(j = 0;j<n;j++){
			printf("%d\t ",array[i][j]);
		}
		printf("\n");
	}

}
