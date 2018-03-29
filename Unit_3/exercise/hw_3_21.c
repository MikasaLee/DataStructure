/**
 * 3.21 
 * 	假设表达式有单字母变量和双目四则运算符构成。试写一个算法，将一个通常书写形式且书写正确的表达式转换为逆波兰表达式。
 */
//关于表达式求值的在 ../src/Expression.c文件中，并且处理了多字母变量的问题，但是却没有使用波兰式
//此问题本质是将一个中缀表达式改为后缀表达式。
//也就是实现 a+b*c-d/f  ->  abc*+df/-
//波兰式/前缀表达式 ：PN    逆波兰式/后缀表达式 ：RPN
/**
 * 中缀转后缀：
 * 	1.遇到操作数，直接输出；
 *	 2.栈为空时，遇到运算符，入栈；
 *	 3.遇到左括号，将其入栈；
 *	 4.遇到右括号，执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出；
 *	 5.遇到其他运算符’+”-”*”/’时，弹出所有优先级大于或等于该运算符的栈顶元素，然后将该运算符入栈；
 *	 6.最终将栈中的元素依次出栈，输出。
 *	 经过上面的步骤，得到的输出既是转换得到的后缀表达式。 
 */
#include  "../src/Expression.h"		//借用此头文件

char* toRPN();
int operatorLevel(SqStack_L OPTR,char opt,char *RPN,int j);
char* toRPN(){		//也不用返回此后缀表达式，先能输出了再说
	char str[81],*RPN;
	ElemType temp;
	int i,j;
	SqStack_L OPTR;	//OPND 操作数栈
	printf("请输入表达式：\n");
	scanf("%s",str);
	if(InitStack_Sq(&OPTR)){
		RPN = (char *)malloc(sizeof(char)*81);
		for(i = 0,j=0;str[i] != '\0';i++){
			if(str[i] >= '0' && str[i] <= '9')	RPN[j++] = str[i];
			else j = operatorLevel(OPTR,str[i],RPN,j);
		}
		while(!StackEmpty_Sq(OPTR)){
			Pop_Sq(OPTR,&temp);
			RPN[j++] = temp -> optr;
		}
		RPN[j] = '\0';
		return RPN;
	}
	return NULL;
}
int operatorLevel(SqStack_L OPTR,char opt,char *RPN,int j){
	ElemType temp = (ElemType)malloc(sizeof(opt)),top;
	temp -> type = 0;
	temp -> optr = opt;
	if(StackEmpty_Sq(OPTR) || opt == '('){	//第一个操作符，直接入栈返回
		Push_Sq(OPTR,temp);
		return j;
	}
	if(opt == '*' || opt == '/'){
		GetTop_Sq(OPTR,&top);
		while(top !=NULL&&(top -> optr == '*' || top -> optr == '/')){
			Pop_Sq(OPTR,&top);
			RPN[j++] = top -> optr;
			GetTop_Sq(OPTR,&top);
		}
		Push_Sq(OPTR,temp);
		return j;
	}
	if(opt == '+' || opt == '-'){
		GetTop_Sq(OPTR,&top);
		while(top != NULL &&(top -> optr == '+' || top -> optr == '-' || top -> optr == '*' || top -> optr == '/')){
			Pop_Sq(OPTR,&top);
			RPN[j++] = top -> optr;
			if(!GetTop_Sq(OPTR,&top))	break;
		}
		Push_Sq(OPTR,temp);
		return j;
	}

	if(opt == ')'){
		GetTop_Sq(OPTR,&top);
		while(top != NULL&&(top -> optr != '(')){
			Pop_Sq(OPTR,&top);
			RPN[j++] = top -> optr;
			GetTop_Sq(OPTR,&top);
		}
		Pop_Sq(OPTR,&top);	//弹出左括号
		RPN[j++] = top -> optr;
		return j;
	}
	exit(OVERFLOW);
}

#if (!defined HW_3_22_C) &&(!defined HW_3_23_C)
int main(int argc,char **args){
	char *p = toRPN();
	printf("\n%s\n",p);
}
#endif
