/**
 * 3.32❹试利用循环队列编写求k阶菲波那契序列中前n+1项的算法，要求满足fn≤max而fn+1≥max，其中max为某个约定的常数。
 * （注意：本题所用循环队列的容量仅为k，则在算法执行结束时，留在循环队列中的元素应是所求k阶菲波那契序列中的最后k项）
 */
#define MAIN
typedef int ElemType;
#include "hw_3_30.c"

void hw_3_32(TagCSQ t,int max){
	int n = 1,i,j,fn = 0;	//n表示项数
	ElemType temp;
	if(!t)	exit(OVERFLOW);
	while(TRUE){
		if(n == 1 || n == 2)	fn = 1;
		else fn = t -> base[(t -> tail -1 + MAX_SIZE)%MAX_SIZE] + t -> base[(t -> tail - 2 + MAX_SIZE)%MAX_SIZE];
		n++;
		if(fn > max) break;
		if(t -> length == MAX_SIZE)	DeTagCylSqQueue(t,&temp);
		EnTagCylSqQueue(t,fn);
	}
	return;
}
void show1(TagCSQ q){
	if(!q)  exit(OVERFLOW);
	if(q -> length == 0)    return; //空队列
	int i = (q -> tail - q -> length + MAX_SIZE)%MAX_SIZE;
	do{
		printf("%d ",q -> base[i]);
		i = (++i)%MAX_SIZE;
	}while(i != q -> tail);
	printf("\n");
}

int main(int argc,char **args){
	TagCSQ t;
	if(InitTagCylSqQueue(&t)){
		hw_3_32(t,200);
	}
	show1(t);	//不能用show，show是char类型
}
