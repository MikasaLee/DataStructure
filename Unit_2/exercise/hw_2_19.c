/**
 * 习题 2.19 
 * 已知线性表中的元素以值递增有序排列，并以单链表作存储结构。
 * 试写一高效的算法，删除表中所有值大于mink且小于maxk的元素（若表中存在这样的元素），同时释放被删结点空间，
 * 并分析你的算法的时间复杂度（注意：mink和maxk是给定的两个参变量，它们的值可以和表中的元素相同，也可以不同）。
 */
#include "../src/LinkList.c"
void hw_2_19(LinkList L,ElemType mink,ElemType maxk){
	LinkList p,q,temp;
	if(!L || mink >= maxk)	exit(OVERFLOW);
	q = L;
	while(q -> next && q -> next -> data <= mink) q = q -> next;	//q -> next为第一个要删除的元素
	p = q;
	while(p -> next && p -> next -> data < maxk) p = p -> next;	//p为最后一个要删除的元素
	temp = q -> next;
	q -> next = p -> next;
	while(temp != p -> next){
		q = temp;		//这里的q与前面的q含义不一样，这里的q只是起到一个记录temp的prior的作用
		temp = temp -> next;
		free(q);
	}
}//该算法最大的执行次数的情况是：要删除的是所有的元素，此时的循环次数为2*ListLength_L(L),即时间复杂度为O(n)

void main(){
	LinkList p,q;
	int i,j;
	if(InitList_L(&p) && InitList_L(&q)){
		for(i = 0;i<10;i++)	ListInsert_L(p,ListLength_L(p)+1,i);
		hw_2_19(p,4,9);
		Print_L(p);
	}
}

