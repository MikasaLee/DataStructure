#include "stdio.h"
#include "../src/myDefine.c"

/**
 * 习题1.16: 试写一算法，自大到小依次输出顺序读入的三个整数X，Y和Z的值。
 */
void myPrint(int ,int ,int );
void main(){
	int x,y,z;
	x = 2;
	y = 1;
	z = 3;
	myPrint(x,y,z);
}

void myPrint(int x,int y,int z){
	if(x < y){
		int temp = x;
		x =y;
		y =temp;
	}
	if(x < z){
		int temp = x;
		x = z;
		z = temp;
	}
	if(y < z){
		int temp = y;
		y = z;
		z = temp;
	}
	printf("%d > %d > %d\n",x,y,z);

}
