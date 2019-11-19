/*************************************************************************
	> File Name: check63.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 19 Nov 2019 11:23:50 PM CST
 ************************************************************************/

#include "stdio.h"

int main(int argc,char **argv){

	float a = 123.4567;
	printf("%f\n",(int)(a*100+0.5)/100.0);	//先 a*100+0.5 之后(int) 之后/100.0  -> 123.460000

	return 0;
}
