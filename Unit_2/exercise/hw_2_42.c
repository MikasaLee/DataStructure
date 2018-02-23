/**
 * 2.42 试编写算法，将一个用循环链表表示的稀疏多项式分解成两个多项式，使这两个多项式中各自仅含奇次项或偶次项，并要求利用原链表中的结点空间构成这两个链表。
 */
#include "../src/Polynomial.c"
void hw_2_42(Polynomial *L,Polynomial *L_odd,Polynomial *L_even){
	if(!L) exit(OVERFLOW);
	LinkList pa,pb,pc;
	if(CreatePolyn(L_odd,0) && CreatePolyn(L_even,0)){
		pa = pb = NULL;
		pc = (*L) -> head;
		while(pc){
			if((pc -> data.expn)%2 == 1){
				if(pa == NULL){
					(*L_odd) -> head = pc;
					pa = (*L_odd) -> head;
				}else{
					pa -> next = pc;
					pa = pa -> next;	
				}
				((*L_odd) -> length)++;
			}else{
				if(pb == NULL){
					(*L_even) -> head = pc;
					pb = (*L_even) -> head;
				}else{
					pb -> next = pc;
					pb = pb -> next;	
				}
				((*L_even) -> length)++;
			}
			pc = pc -> next;
		}//while
		pb -> next = pa -> next = NULL;
		free(*L);
		(*L) = NULL;
	}
}
void main(){
	Polynomial p,p_odd,p_even;
	printf("\n------------测试CreatPolyn(Polynomial *p,int m)函数----------------\n");
	if(CreatePolyn(&p,3)){
		PrintPolyn(p);
	}
	hw_2_42(&p,&p_odd,&p_even);
	PrintPolyn(p_odd);
	PrintPolyn(p_even);
	PrintPolyn(p);
}
