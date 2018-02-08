#include "../src/Polynomial.c"

void main(){
	Polynomial p,q;
	printf("\n------------测试CreatPolyn(Polynomial *p,int m)函数----------------\n");
	if(CreatePolyn(&p,0)){
		PrintPolyn(p);
	}
	if(CreatePolyn(&p,2)){
		PrintPolyn(p);
	}
	
	if(CreatePolyn(&q,2)){
		PrintPolyn(q);
	}
/**
	printf("\n------------测试AddPolyn(Polynomial *Pa,Polynomial *Pb)函数----------------\n");
	if(AddPolyn(&p,&q)){
		PrintPolyn(p);
		PrintPolyn(q);
	}


	printf("\n------------测试SubtractPolyn(Polynomial *Pa,Polynomial *Pb)函数----------------\n");
	if(SubtractPolyn(&p,&q)){
		PrintPolyn(p);
		PrintPolyn(q);
	}
**/
	printf("\n------------测试MultiplyPolyn(Polynomial *Pa,Polynomial *Pb)函数----------------\n");
	if(MultiplyPolyn(&p,&q)){
		PrintPolyn(p);
		PrintPolyn(q);

	}
}
