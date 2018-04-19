#ifndef POLYNOMIAL_C
#define POLYNOMIAL_C

#include "Polynomial.h"

Status CreatePolyn(Polynomial *p,int m){
	int i;
	if(m < 0){
		printf("\n创建一元多项式失败：输入的项数必须是大于0的整数！\n");
		(*p) = NULL;
		return ERROR;
	}
	(*p) = (Polynomial)malloc(sizeof(poly));
	if((*p)){		//创建头结点成功
		Polynomial q = (*p);
		q -> head = NULL;
		q -> length = 0;
		for( i = 1;i <= m;i++){
			float coef;
			int expn;
			printf("\n输入第%d项的系数和指数：\n",i);
			printf("  系数(保留两位小数):");
			scanf("%f",&coef);
			printf("  指数:");
			scanf("%d",&expn);
			AddNode(q,coef,expn);	//添加该项
		}
		return OK;
	}
	printf("\n创建一元多项式失败：申请空间失败！\n");
	return ERROR;
}

Status DestroyPolyn(Polynomial *p){
	if(!(*p)) return OK;
	LinkList L = (*p) -> head;
	while(L){
		LinkList temp = L -> next;
		free(L);
		L = temp;
	}
	if(!L){
		free((*p));
		(*p) = NULL;
		return OK;
	}
	printf("\n销毁一元多项式操作失败：项数没有全部释放掉！\n");
	return ERROR;
}

void PrintPolyn(Polynomial p){
	if(!p){
		printf("\n打印一元多项式失败：不存在此一元多项式\n");
		return;
	}
	printf("\n该一元多项式的项数为：%d\n",PolynLength(p));
	if(PolynLength(p)){
		printf("----------------------------------------------\n");	
		LinkList L = p -> head;
		int i = 1;
		while(L){
			printf("第%d项的系数(保留两位小数)为：%.2f,指数为：%d\n",i,L -> data.coef,L ->data.expn);
			/*
			 //想看地址可以打开该注释
			 printf("第%d项的地址为：%d,下一跳的地址为：%d\n",i,L,L ->next);
			 */
			i++;
			L = L -> next;
		}
		printf("----------------------------------------------\n");	
	}
}

int PolynLength(polynomial p){
	if(p)	return p -> length;
	return -1;
}

Status AddNode(Polynomial p,float coef,int expn){
	LinkList L,q,head;
	if(!p){
		printf("多项式不存在！\n");
		return ERROR;
	}
	if(fabs(coef) < infinitesimal)	return OK;	//系数为0，不用添加
 	
	L =(LinkList)malloc(sizeof(LNode));
	if(L){
		//临时加一个头结点
		head = (LinkList)malloc(sizeof(LNode));
		head -> data.coef = 0;
		head -> data.expn = 0;
		head -> next = p -> head;
		p -> head = head;
		q = p -> head;
	
		L -> data.coef = coef;
		L -> data.expn = expn;
		while((q -> next) && (q -> next -> data.expn) < expn){
			q = q -> next;
		}//while

		if(!(q -> next)){		//不满足while第一个条件
			L -> next = q -> next;
			q -> next = L;
			(p -> length)++;
		}else{				//不满足while第二个条件
			if(q -> next -> data.expn == expn){	//指数相等，合并,注意合并有可能出现系数和为0的情况
				q -> next -> data.coef += coef;
				if(fabs(q -> next -> data.coef) < infinitesimal){
					LinkList temp = q -> next;
					q -> next = q -> next -> next;
					free(temp);
					(p -> length)--;
				}
		}	
				
			else{
				L -> next = q -> next;
				q -> next = L;
				(p -> length)++;
			}
		}//if(!q)
		//删掉头结点
		p -> head = p -> head -> next;
		free(head);
		return	OK;
	}
	printf("\n添加项失败：申请项空间失败！\n");
	return ERROR;
}

Status AddPolyn(Polynomial *Pa,polynomial *Pb){
	Polynomial Pc;
	LinkList pa,pb,pc,head;	
	if(!(*Pa) || !(*Pb)){
		printf("\n至少一个一元多项式为空！操作失败\n");
		return ERROR;
	}
	if(CreatePolyn(&Pc,0)){

		//临时加一个头结点
		head = (LinkList)malloc(sizeof(LNode));
		head -> data.coef = 0;
		head -> data.expn = 0;
		head -> next = Pc -> head;
		Pc -> head = head;

		pa = (*Pa) -> head;
		pb = (*Pb) -> head;
		pc = Pc -> head;
		while(pa && pb){
			if(pa -> data.expn < pb -> data.expn){
				pc -> next = pa;
				pa = pa -> next;
				pc = pc -> next;
				(Pc -> length)++;
			}else if(pa -> data.expn == pb -> data.expn){	//合并操作，注意二者合并可能是0.平且注意pa pb是同时移动，所以很可能出现pa pb同时为NULL的情况
				pa -> data.coef += pb -> data.coef;
				if(fabs(pa -> data.coef) < infinitesimal){
					LinkList temp = pa -> next;
					free(pa);
					pa = temp;

					temp = pb -> next;
					free(pb);
					pb = temp;
				}else{
					pc -> next = pa;
					pa = pa -> next;
					pc = pc -> next;
					(Pc -> length)++;
					LinkList temp = pb -> next;
					free(pb);
					pb = temp;
				}
			}else{
				pc -> next = pb;
				pb = pb -> next;
				pc = pc -> next;
				(Pc -> length)++;
			}	
		}//while(pa && pb)
		pc -> next = pa?pa:pb;
		while(pc -> next){
			(Pc -> length)++;
			pc = pc -> next;
		}
		//删掉头结点
		Pc -> head = Pc -> head -> next;
		free(head);

		free(*Pa);
		//将Pc赋给*Pa
		(*Pa) = Pc;
		//销毁Pb
		free(*Pb);
		(*Pb) = NULL;
		return OK;
	}
	printf("\n合并失败！\n");
}

Status SubtractPolyn(Polynomial *Pa,polynomial *Pb){
	Polynomial Pc;
	LinkList pa,pb,pc,head;	
	if(!(*Pa) || !(*Pb)){
		printf("\n至少一个一元多项式为空！操作失败\n");
		return ERROR;
	}
	if(CreatePolyn(&Pc,0)){

		//将Pb全部的系数全部置反,因为该函数调用之后，会将Pb废除，所以允许在这里就更改Pb的原数据。
		pb = (*Pb) -> head;
		while(pb){
			pb -> data.coef = -pb -> data.coef;
			pb = pb -> next;
		}
		//临时加一个头结点
		head = (LinkList)malloc(sizeof(LNode));
		head -> data.coef = 0;
		head -> data.expn = 0;
		head -> next = Pc -> head;
		Pc -> head = head;

		pa = (*Pa) -> head;
		pb = (*Pb) -> head;
		pc = Pc -> head;
		while(pa && pb){
			if(pa -> data.expn < pb -> data.expn){
				pc -> next = pa;
				pa = pa -> next;
				pc = pc -> next;
				(Pc -> length)++;
			}else if(pa -> data.expn == pb -> data.expn){	//合并操作，注意二者合并可能是0.平且注意pa pb是同时移动，所以很可能出现pa pb同时为NULL的情况
				pa -> data.coef += pb -> data.coef;
				if(fabs(pa -> data.coef) < infinitesimal){
					LinkList temp = pa -> next;
					free(pa);
					pa = temp;

					temp = pb -> next;
					free(pb);
					pb = temp;
				}else{
					pc -> next = pa;
					pa = pa -> next;
					pc = pc -> next;
					(Pc -> length)++;
					LinkList temp = pb -> next;
					free(pb);
					pb = temp;
				}
			}else{
				pc -> next = pb;
				pb = pb -> next;
				pc = pc -> next;
				(Pc -> length)++;
			}	
		}//while(pa && pb)
		pc -> next = pa?pa:pb;
		while(pc -> next){
			(Pc -> length)++;
			pc = pc -> next;
		}
		//删掉头结点
		Pc -> head = Pc -> head -> next;
		free(head);

		free(*Pa);
		//将Pc赋给*Pa
		(*Pa) = Pc;
		//销毁Pb
		free(*Pb);
		(*Pb) = NULL;
		return OK;
	}
	printf("\n作差失败！\n");
}

Status MultiplyPolyn(polynomial *Pa,polynomial *Pb){
	polynomial Pc,temp;
	LinkList pa,pb;
	if(!(*Pa) || !(*Pb)){
		printf("\n至少有一个一元多项式为空！操作失败\n");
		return ERROR;
	}
	if(CreatePolyn(&Pc,0)){
		pa = (*Pa) -> head;
		pb = (*Pb) -> head;
	}
	while(pa){
		if(CreatePolyn(&temp,0)){
			while(pb){
				AddNode(temp,(pa ->data.coef)*(pb->data.coef),(pa ->data.expn)+( pb->data.expn));
				pb = pb -> next;
			}	
		}
		AddPolyn(&Pc,&temp);
		pa = pa -> next;
		pb = (*Pb) -> head;
	}
	//释放掉Pa和Pb
	pa = (*Pa) -> head;
	while(pa){	//借用一下pb当缓存
		pb = pa -> next;
		free(pa);
		pa = pb;
	}
	free(*Pa);
	(*Pa) = Pc;

	pb = (*Pb) -> head;
	while(pb){	//借用一下pa当缓存
		pa = pb -> next;
		free(pb);
		pb = pa;
	}
	free(*Pb);
	(*Pb) = NULL;

	return OK;
}
/**  版本2.0以后可能会用到
//将一元多项式化为非递减的最简式
Status SimplesetPolyn(Polynomial p){
	LinkList pa,pb,head;
	if(!p){
		printf("\n不存在该一元多项式！\n");
	       	return ERROR;
	}
	//临时加一个头结点
	head = (LinkList)malloc(sizeof(LNode));
	head -> data.coef = 0;
	head -> data.expn = 0;
	head -> next = p -> head;
	p -> head = head;
	
	pb = pa = p -> head;
	//先用冒泡排序将p按指数非递减排序
	int i,j;
	for(i=1;i<PolynLength(p);i++){
		LinkList temp = pb -> next,temp1,temp2;		//temp当作游标的前一个节点，pb为当前最小指数的前一个节点

		for(j=i;j<PolynLength(p);j++){
			if(temp -> next -> data.expn < pb -> next -> data.expn)
				pb = temp;
			else if(temp -> next -> data.expn == pb -> next -> data.expn){	//指数相等的话也合并了,但是此时不要去判断系数是否为0
				pb -> next -> data.coef += temp -> next -> data.coef;

				LinkList t = temp -> next;
				temp -> next = temp -> next -> next;
				free(t);
				(p -> length)--;
			}
			temp = temp -> next;
		}//内层for循环结束
		
		//交换pa 的下一跳(temp1)和pb的下一跳(temp2)
		//先交换temp1 和 temp2的下一跳
		//再交换pa的下一跳和pb的下一跳
		temp1 = pa -> next;
		temp2 = pb -> next;
		
		temp = temp1 -> next;
		temp1 -> next = temp2 -> next;
		temp2 -> next = temp;
 		
		temp = pa -> next;
		pa -> next = pb -> next;
		pb -> next = temp;

		pb = pa = pa -> next;		//将游标归位
	}//外层for循环结束

	//判断是否有系数是0？
	pa = p -> head;
	while(pa -> next){
		if(fabs(pa -> next -> data.coef) < infinitesimal){
			pb = pa -> next;
			pa -> next = pa -> next -> next;
			free(pb);
			(p->length)--;
		}
	}
	//删掉头结点
	p -> head = p -> head -> next;
	free(head);
	return OK;
}

**/
#endif
