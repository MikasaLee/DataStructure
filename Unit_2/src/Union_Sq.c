/*
 * 实现A并B的操作
 */
#include "SqList.c"
Bool equal(ElemType a,ElemType b){	//判断a与b是否相等，若相等返回TRUE,不相等返回FALSE;
	return a == b?TRUE:FALSE;
}

void Union_Sq(SqList *a,SqList b){
	//将b表并入a表
	int i,p =ListLength_Sq(*a);
	for(i=0;i<ListLength_Sq(b);i++){	
		if(!LocateElem_Sq(*a,b.elem[i],equal)){		//a中不存在b->elem[i]元素
			ListInsert_Sq(a,ListLength_Sq(*a)+1,b.elem[i]);	//将b的该元素插入到a表最后,注意第二个参数表示的是序列，不是下标
		}
	}
}
