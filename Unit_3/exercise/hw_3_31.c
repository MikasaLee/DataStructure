/**
 * 3.31 假设称正读和反读都相同的字符序列为“回文”，例如，‘abba’和‘abcba’是回文，‘abcde’和‘ababab’则不是回文。
 * 试写一个算法判别读入的一个以‘@’为结束符的字符序列是否是“回文”。
 */
#define HW_3_31_C
typedef char ElemType;
#include "../src/Queue.h"
#include "../src/Queue.c"
#include "../src/SqStack.h"
#include "../src/SqStack.c"

Bool hw_3_31(){
	SqStack_L S,temp;
	Queue q;
	ElemType c,temp1,temp2;
	if(InitQueue(&q) && InitStack_Sq(&S) && InitStack_Sq(&temp)){
		printf("请输入字符串（以@结束）:\n");
		while(scanf("%c",&c)){
			if(c == '@')	break;
			if(c != '\n')Push_Sq(S,c);		//过滤掉换行
		}
		while(!StackEmpty_Sq(S)){
			GetTop_Sq(S,&c);
			Push_Sq(temp,c);
			EnQueue(q,c);
			Pop_Sq(S,&c);
		}
		while(!StackEmpty_Sq(temp)){
			Pop_Sq(temp,&temp1);
			DeQueue(q,&temp2);
			if(temp1 != temp2)	return FALSE;
		}
		return TRUE;
	}
	exit(OVERFLOW);
}

int main(int argc,char **args){
	if(hw_3_31())	printf("是回文\n");
	else printf("不是回文\n");
	return 0;
}
