/**
 * 3.23 如题3.21的假设条件，试写一个算法，判断给定的非空后缀表达式是否为正确的逆波兰表达式，如果是，则将它转化为波兰式。
 */
#define HW_3_23_C
#include "hw_3_21.c"
Bool isRPN(char *str){
	int i = 0;
	SqStack_L OPND;
	ElemType temp,num1,num2;
	if(InitStack_Sq(&OPND)){
		for(i = 0;str[i]!='\0';i++){
			if(str[i] >='0' && str[i] <='9'){
				temp = (ElemType)malloc(sizeof(opt));		
				temp -> type = 1;
				temp -> opnd = str[i] - '0';
				Push_Sq(OPND,temp);
			}else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
				if(!Pop_Sq(OPND,&num2) || !Pop_Sq(OPND,&num1))	return FALSE;
				Push_Sq(OPND,num1);	//只是检查格式，所以这里不做计算
			}else	return FALSE;		//有其他符号
		}
		if(StackLength_Sq(OPND) == 1)	return TRUE;
	}
	return FALSE;
}
//后缀转前缀
//先跳过，前缀中缀后缀其实是一颗二叉树的先序遍历中序遍历和后序遍历，等到第6章树学完之后再来做这个题

int main(int argc,char **args){
	char str[81];
	printf("请输入一个后缀表达式:\n");
	scanf("%s",str);
	if(isRPN(str))	printf("表达式正确\n");
	else printf("表达式错误\n");
	return 0;
}
