/**
 * 线性链表的并操作
 * La与Lb是非递减排序，归并La和Lb -> Lc 并且废弃La和Lb的头结点(La的头结点改为Lc接手且La为NULL，Lb的free掉)
 */
#include "./LinkList.c"
void MergeList_L(LinkList *La,LinkList *Lb,LinkList *Lc){		//需要将原来的La，Lb改动（废除他们的头结点，并且将实参的La,Lb为NULL，所以这里应该传入'引用'，即LinkList *La(而不是LinkList La)）
	LinkList pa,pb,pc;
	if(ListEmpty_L(*La)){		//这是特殊情况，free()的是La
		(*Lc) = (*Lb);
		(*Lc) -> data = ListLength_L(*Lc); 
		free(*La);
		(*Lb) = NULL;
		(*La) = NULL;
		return;
	}
	if(ListEmpty_L(*Lb)){
		(*Lc) = (*La);
		(*Lc) -> data = ListLength_L(*Lc); 
		free(*Lb);
		(*La) = NULL;
		(*Lb) = NULL;
		return;
	}
	pa = (*La) -> next;
	pb = (*Lb) -> next;
	(*Lc) = pc = (*La);
	while(pa && pb){
		if(pa -> data < pb -> data){
			pc -> next = pa;
			pa = pa -> next;
			pc = pc -> next;
		}else{
			pc -> next = pb;
			pb = pb -> next;
			pc = pc -> next;
		}
	}
	pc -> next = pa?pa:pb;	//将最后剩余的也加入Lc中
	(*Lc) -> data = ListLength_L(*Lc); 
	free(*Lb);
	(*Lb) = NULL;
	//free(*La);		
	//一个奇怪的现象，free(*La)之后，表示La的头结点就被释放掉了，但是测试函数中Print_L(c)还能遍历出c的所有节点。
	/**
	 * 回答：
	 * free()函数只是告诉系统这块内存我不用了，系统会在内存登记表里将这块内存标记为可用.
	 * 系统不一定会马上去动这块内存中的内容，所以用c去读头结点的时候也有可能读到
	 *
	 * 但这种行为是非常危险的！！！
	 */
	
	(*La) = NULL;
	return;

}
