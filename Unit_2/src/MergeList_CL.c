/**
 * 循环链表的并操作
 * CLa和CLb是非递减序列，归并CLa和CLb -> CLc,且CLc依然是非递减序列
 * 并且废弃CLa和CLb的头结点（并且废弃CLa和CLb的头结点，CLa的头结点由CLc接手且CLa为NULL，CLb的free掉）
 */
#include "./CircularLinkList.c"
void MergeList_CL(CLinkList *CLa,CLinkList *CLb,CLinkList *CLc){
	CLinkList pa,pb,pc;
	if(ListEmpty_CL(*CLa)){
		(*CLc) = (*CLb); 
		free(*CLa);
		(*CLb) = NULL;
		(*CLa) = NULL;
		return;
	}
	if(ListEmpty_CL(*CLb)){
		(*CLc) = (*CLa); 
		free(*CLb);
		(*CLb) = NULL;
		(*CLa) = NULL;
		return;
	}
	pa = (*CLa) -> next;
	pb = (*CLb) -> next;
	pc = (*CLc) = (*CLa);
	while(pa != (*CLa) && pb != (*CLb)){
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
	if(pa == (*CLa)){		//CLa剩余和CLb剩余的情况不同:最后一个节点的next是否需要修改
		pc -> next = pb;
		while(pb ->next != (*CLb)){
			pb = pb -> next;
		}
		pb -> next = (*CLa);
	}
	else pc -> next = pa;
	free(*CLb);
	(*CLb) = NULL;
	(*CLa) = NULL;
	return;
}
