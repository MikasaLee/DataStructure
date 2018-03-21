/**
 * 3.17 
 * 试写一个算法，识别一次读入的一个以@为结束符的字符序列是否为形如‘序列1&序列2’模式的字符序列。
 * 其中序列1和序列2中都不含字符‘&’，且序列2是序列1的逆序列。例如，‘a+b&b+a’是属该模式的字符序列，而‘1+3&3-1’则不是。
 */
#include "../src/SqStack.c"

Bool hw_3_17(char *str){
	SqStack_L S;
	int i;
	ElemType temp;
	Bool check = FALSE;	//&符号以前是FALSE，&以后是TRUE
	if(InitStack_Sq(&S)){
		for(i = 0;str[i] != '@';i++){
			if(str[i] == '&' && check == FALSE)check = TRUE;
			else if(str[i] == '&' && check == TRUE)	{printf("\n出现大于一个的'&',程序结束\n"); exit(OVERFLOW);}
			else{	
				if(check == FALSE) Push_Sq(S,str[i]);
				else{
					Pop_Sq(S,&temp);
					if(str[i] != temp)	return FALSE;
				}
			}
		}
		if(StackEmpty_Sq(S))	return TRUE;
	}
	return FALSE;
}

int main(int argc,char **args){
	char a[81];
	printf("请输入一个字符串:\n");
	scanf("%s",a);
	if(hw_3_17(a))	printf("此字符串是回文\n");
	else printf("此字符串不是回文\n");
	return 0;
}
