/**
 * 2.41❷试以循环链表作稀疏多项式的存储结构，编写求其导函数的算法，要求利用原多项式中的结点空间存放其导函数（多项式），同时释放所有无用（被删）结点。
 */
#include "../src/Polynomial.c"

void hw_2_41(Polynomial L){
	if(!L) exit(OVERFLOW);
	LinkList p = L -> head,temp;
	if(p -> data.expn == 0){
			temp = p -> next;
			p -> next = temp -> next;
			free(temp);
	}else{
		(p -> data.coef)*=(p -> data.expn);
		(p -> data.expn)--;
	}
	while(p -> next){
		if(p -> next -> data.expn == 0){
			temp = p -> next;
			p -> next = temp -> next;
			free(temp);
		}else{
			(p -> next -> data.coef)*=(p -> next -> data.expn);
			(p -> next -> data.expn)--;
			p = p -> next;
		}
	}
}

void main(){
	Polynomial p;
	printf("\n------------测试CreatPolyn(Polynomial *p,int m)函数----------------\n");
	if(CreatePolyn(&p,3)){
		PrintPolyn(p);
	}
	hw_2_41(p);
	PrintPolyn(p);
}
