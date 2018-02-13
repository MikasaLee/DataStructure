/**
 * 2.15 已知指针ha和hb分别指向两个单链表的头结点，并且已知两个链表的长度分别为m和n。
 * 试写一算法将这两个链表连接在一起（即令其中一个表的首元结点连在另一个表的最后一个结点之后），假设指针hc指向连接后的链表的头结点，并要求算法以尽可能短的时间完成连接运算。
 * 请分析你的算法和时间复杂度。
 */
#include "../src/LinkList.c"
Status hw_2_15(LinkList ha,LinkList hb,LinkList *hc){
	if(!ha || !hb ) exit(OVERFLOW);
	if(ListLength_L(ha) < ListLength_L(hb)){
		LinkList p = ha;
		while(p -> next) p = p -> next;	//p指向最后一个节点
		p -> next = hb -> next;
		(*hc) = ha;
		return OK;
	}else{
		LinkList p = hb;
		while(p -> next) p = p -> next;	//p指向最后一个节点
		p -> next = ha -> next;
		(*hc) = hb;
		return OK;

	}


}//hw_2_15,时间复杂度m < n?O(m):O(n);

void main(){
	LinkList pa,pb,pc;
	int i,j;
	if(InitList_L(&pa) && InitList_L(&pb)){
		//初始化pa，pb
		for(i = 0;i < 10;i++)	ListInsert_L(pa,ListLength_L(pa)+1,i); 
		for(i = 0;i < 5;i++)	ListInsert_L(pb,ListLength_L(pb)+1,i);

		hw_2_15(pa,pb,&pc);
		Print_L(pa);
		Print_L(pb);
		Print_L(pc);
	}
}

