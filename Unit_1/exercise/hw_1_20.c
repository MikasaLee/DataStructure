/**
 * 1.20❹  试编写算法求一元多项式的值Pn(x)，并确定算法中每一语句的执行次数和整个算法的时间复杂度。注意选择你认为较好的输入和输出方法。本题的输入为ai(i=0,1,…,n)，x0和n，输出为Pn(x0)。
 */

//借助课本2.14的算法
#include "../../Unit_2/src/Polynomial.c"
double myCalculate(double x,polynomial p);

void main(){
	Polynomial p;
	CreatePolyn(&p,3);
	PrintPolyn(p);
	printf("%f",myCalculate(3,p));
}

double myCalculate(double x,polynomial p){	//将x带入一元多项式p中计算结果
	LinkList L = p -> head;
	double sum = 0,temp;
	int i,j;
	while(L){
		if(L -> data.expn == 0) sum += L -> data.coef;
		else{
			temp = L -> data.coef;
			for(i = 0;i < L-> data.expn;i++){
				temp = temp * x;	
			}
			sum += temp;
		}
		L = L -> next;
	}
	return sum;
}
