/*************************************************************************
	> File Name: check59.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 19 Nov 2019 11:19:11 PM CST
 ************************************************************************/

#include "stdio.h"
#include "string.h"

int main(int argc,char **argv){
	
	char s1[]={'x','y','z'},s2[10]={'x','y','z'};	//关于字符数组最后加不加\0 这本来就是不同编译器不同结果
	printf("%d %d\n",strlen(s1),strlen(s2));	//3 3 和答案不一样，但还是按照答案记把，gcc毕竟和vc不一样

	return 0;
}
