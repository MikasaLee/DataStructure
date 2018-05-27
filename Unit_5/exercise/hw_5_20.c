/*************************************************************************
	> File Name: hw_5_20.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sun 27 May 2018 07:58:50 PM CST
 ************************************************************************/

/**
 *		5.20 类似于以一维数组表示一元多项式，以m维数组：（aj1j2…jm），0≤ji≤n，i=1，2，…，m，表示m元多项式，数组元素ae1e2…em表示多项式中x1e1x2e2…xmem的系数。
 *	    
 *	    试编写一个算法将m维数组表示的m元多项式以常规表示的形式（按降幂顺序）输出。可将其中一项ckx1e1x2e2…xmem印成ckx1Ee1x2Ee2…xmEem（其中m，ck和ej（j=1，2，…，m）印出它们具体的值），当ck或ej（j=1，2，…，m）为1时，ck的值或“E”和ej的值可省略不印。
 */


#include "../../Unit_1/src/myDefine.c"

#ifndef ELEMTYPE
#define ELEMTYPE
typedef int ElemType;
#endif

/**
 * 假设以三维为例,且主顺序为x,y,z
 */
void hw_5_20(int arr[][3][3],int m,int n,int l){
	int i,j,k;
	for(i = m-1;i>=0;i--){
		for(j = n-1;j >=0;j--){
			for(k = l-1;k >= 0;k--){
				if(arr[i][j][k] == 0) continue;
				else if(arr[i][j][k] != 1) printf("%d",arr[i][j][k]);
				
				if(i > 1) printf("xE%d",i);
				else if(i == 1) printf("x");
				if(j > 1) printf("yE%d",j);
				else if(j == 1) printf("y");
				if(k > 1) printf("zE%d",k);
				else if(k == 1) printf("z");

				if((i !=0)&&(j != 0)&&(k !=0)) printf("+");
			}
		}
	}
	printf("\n");
}


int main(int argc,char **argv){
	int a[3][3][3] = {
		-3,2,4,6,-1,0,-3,9,8,
		11,-2,-3,8,3,5,7,3,-5,
		2,3,5,-7,9,-3,3,0,1};
	
	hw_5_20(a,3,3,3);
	return 0;
}
