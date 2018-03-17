/**
 * 表达式求值的实现
 *
 * 实现后感受：没有用前缀中缀后缀的知识，纯属硬写。思路到不是很乱，但是感觉如果不用前缀中缀后缀的话，用栈实现不如用队列实现。
 */

#ifndef EXPRESSION_C
#define EXPRESSION_C
#include "Expression.h"

float operator(float a,char oper,float b){		//返回 a oper b
	if(oper != '+' && oper != '-' && oper != '*' && oper !='/')	exit(OVERFLOW);
	switch(oper){
		case '+':	return a+b; 
		case '-':	return a-b; 
		case '*':	return a*b; 
		case '/': 	return a/b;
	}
}

float Expression(){
	ElemType e,num1,num2,optr,subs[81];		//调用operator函数时需要num1,num2,optr
	int temp,i = 0;
	char s[81],curor;
	SqStack_L OPTR,OPND;	//OPTR 用来存储运算符；OPND用来存储数字
	printf("请输入表达式：");
	scanf("%s",s);
	curor = s[0];
	if(InitStack_Sq(&OPTR) && InitStack_Sq(&OPND)){	//初始化OPTR OPND
		while(curor != '\0'){		//此while循环负责将表达式中的数字或运算符按照规则放入OPTR 和OPND中，并且删除掉括号
			if(curor == '+' || curor == '-' || curor == '*' || curor == '/' || curor == '('){
				e = (ElemType)malloc(sizeof(opt));
				e -> type = 0;
				e -> optr = curor;
				Push_Sq(OPTR,e);

				i++;			//i表示下一个
			}else if(curor >= '0' && curor <= '9'){	//需要处理当输入的数字>=10;
				temp = curor - 48;
				while((curor = s[++i]) >= '0' && curor <= '9')	temp = temp*10 + (curor -48);
				e = (ElemType)malloc(sizeof(opt));
				e -> type = 1;
				e -> opnd = temp;	//自动类型转换，int -> float
				Push_Sq(OPND,e);

			}else if(curor == ')'){	 	//计算括号
				temp = 0;
				optr = (ElemType)malloc(sizeof(opt));
				optr -> optr = curor;
				while(optr -> optr != '('){		//将()中的子表达式都表示出来
					Pop_Sq(OPND,&num1);
					subs[temp++] = num1;
					Pop_Sq(OPTR,&optr);
					subs[temp++] = optr;		
				}
				subs[temp-1] = NULL;		//结束标记
				num2 =(ElemType)malloc(sizeof(opt));
				num2 -> type = 1;
				reverse(subs);
				num2 -> opnd= evaluate(subs);		//计算子表达式的值，该子表达式不存在括号
				Push_Sq(OPND,num2);
				
				i++;
			}else	exit(OVERFLOW);		//有其他的符号，表达式是错误的。

			curor = s[i];
		}//while
		//表达式转成没有()的子表达式了
		i = 0;
		Pop_Sq(OPND,&num1);
		subs[i++] = num1;
		while(!StackEmpty_Sq(OPND)){
			Pop_Sq(OPTR,&optr);
			subs[i++] = optr;
			Pop_Sq(OPND,&num1);
			subs[i++] = num1;
		}
		if(StackEmpty_Sq(OPTR)){
			subs[i] = NULL;		//结束标记
			reverse(subs);
			return evaluate(subs);	//OK!
		}
		printf("表达式错误！\n");
	}
	exit(OVERFLOW);
}

float evaluate(ElemType *sub){		//计算子表达式的值，该子表达式不存在括号，sub
	int i = 0;
	ElemType curor = sub[i],num1,optr;
	float sum = 0;
	SqStack_L OPTR,OPND;
	if(InitStack_Sq(&OPTR) && InitStack_Sq(&OPND)){
		while(curor != NULL){		//先将所有的乘除搞定！
			if(curor -> type == 1)	Push_Sq(OPND,curor);
			else if((curor -> optr == '*') || (curor -> optr == '/')){	//乘除的情况
				Pop_Sq(OPND,&num1);	
				num1 -> opnd = operator(num1 -> opnd,curor -> optr,sub[++i] -> opnd);
				Push_Sq(OPND,num1);
				curor = sub[i];
			}else Push_Sq(OPTR,curor);	//加减的情况
		
			i++;
			curor = sub[i];
		}//while
		//操作符栈中都是加减，剩下的就是直接计算了
		Pop_Sq(OPND,&num1);

		i = 0;
		sub[i] = num1;
		while(!StackEmpty_Sq(OPND)){
			Pop_Sq(OPTR,&optr);
			sub[++i] = optr;
			Pop_Sq(OPND,&num1);
			sub[++i] = num1;
		}
		for(sum = sub[i] -> opnd;i >0;i -=2){
			sum = operator(sum,sub[i-1]->optr,sub[i-2]->opnd);
		}
		if(StackEmpty_Sq(OPTR))	return sum;
		printf("子表达式错误！\n");
	}
	exit(OVERFLOW);
}

void reverse(ElemType *s){
	//反转s。
	int i,sum;
	for(i =0;s[i]!=NULL;i++);
	sum = i-1;	//sum为最后一个元素的下标
	for(i = 0;i < sum-i;i++){
		s[i] = (ElemType)((unsigned long)s[i]^(unsigned long)s[sum-i]);
		s[sum-i] = (ElemType)((unsigned long)s[sum-i]^(unsigned long)s[i]);
		s[i] = (ElemType)((unsigned long)s[sum-i]^(unsigned long)s[i]);
	}
}

#endif
