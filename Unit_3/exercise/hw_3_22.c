/**
 * 3.22 如题3.21的假设条件，试写一个算法，对以逆波兰式表示的表达式求值。
 */
#define HW_3_22_C
#include "hw_3_21.c"
float answer(char *str);
float calculate(float num1,char optr,float num2);
float answer(char *str){
	SqStack_L OPND;
	ElemType num1,num2,temp;
	int i,j;
	if(InitStack_Sq(&OPND)){
		printf("%s\n",str);
		for(i = 0;str[i] != '\0';i++){
			if(str[i] >= '0' && str[i] <= '9'){
				temp = (ElemType)malloc(sizeof(opt));
				temp -> type = 1;
				temp -> opnd = str[i] - '0';
				Push_Sq(OPND,temp);
			}
			else{
				Pop_Sq(OPND,&num2);
				Pop_Sq(OPND,&num1);
				num1 -> opnd= calculate(num1 -> opnd,str[i],num2 -> opnd);
				Push_Sq(OPND,num1);
			}
		}
		Pop_Sq(OPND,&num1);
		return num1 -> opnd;
	}
	exit(OVERFLOW);
}
float calculate(float num1,char optr,float num2){
	switch(optr){
		case '+': return num1 + num2;
		case '-': return num1 - num2;
		case '*': return num1 * num2;
		case '/': return num1 / num2;
	}
}

int main(int argc,char **args){
	char *RPN = toRPN();
	if(RPN != NULL)	printf("=%.2f\n",answer(RPN)); 
}
