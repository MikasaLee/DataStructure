/**
 * 实现循环链表A并B的操作
 */
#include "./CircularLinkList.c"
void Union_CL(CLinkList *CLa,CLinkList *CLb){
	//将CLb表并入CLa表，同时废除CLb表
	CLinkList p,q;
	if(ListEmpty_CL(*CLb)){
		free(*CLb);
		(*CLb) = NULL;
		return;
	}
	if(ListEmpty_CL(*CLa)){
		free(*CLa);
		(*CLa) = (*CLb);
		(*CLb) = NULL;
		return;
	}
	p = (*CLa);
	q = (*CLb) -> next;
	
	while(q != (*CLb)){
		if(!LocateElem_CL(p,q->data,equals))	ListInsert_CL(p,ListLength_CL(p)+1,q->data);
		q = q-> next;
	}
	DestroyList_CL(CLb);
	return;
}
