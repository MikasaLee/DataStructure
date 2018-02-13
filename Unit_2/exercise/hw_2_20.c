/**
 * 2.20:同2.19题条件（递增有序排列）.
 * 试写一高效的算法，删除表中所有值相同的多余元素（使得操作后的线性表中所有元素的值均不相同），同时释放被删结点空间.
 * 并分析你的算法的时间复杂度。
 */
#include "../src/LinkList.c"
void hw_2_20(LinkList L){
	LinkList p,q;
	if(!L)	exit(OVERFLOW);
	p = L -> next;
	q = p -> next;
	while(q){
		if(q -> data == p -> data){
			p -> next = q -> next;
			free(q);
		}else	p = p -> next;
		q = p -> next;
	}
}//算法的时间复杂度为O(n),n = ListLength_L(L);
void main(){
	 LinkList p,q;
	 int i,j;
	 if(InitList_L(&p) && InitList_L(&q)){
		  for(i = 0;i<10;i++){
			ListInsert_L(p,ListLength_L(p)+1,i);
		  	ListInsert_L(p,ListLength_L(p)+1,i);
		  	ListInsert_L(p,ListLength_L(p)+1,i);
		  }
		  Print_L(p);
		  hw_2_20(p);
		  Print_L(p);
	}
}

