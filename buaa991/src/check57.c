/*************************************************************************
	> File Name: check57.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 19 Nov 2019 11:14:28 PM CST
 ************************************************************************/

#include "stdio.h"

int ADD(int x,int y){return x+y;}
int main(int argc,char **argv){
	int k,(*f)(),x=5,y=10;
	f= ADD;

	k = (*f)(x,y);
	k = ADD(x,y);
	//k = *f(x,y);		//语法错误！
	k = f(x,y);

}
