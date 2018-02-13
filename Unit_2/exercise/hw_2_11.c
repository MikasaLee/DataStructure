/**
 * 2.11 设顺序表va中的数据元素递增有序。
 * 试写一算法，将x插入到顺序表的适当位置上，以保持该表的有序性
 */

#include "../src/SqList.c"
Status hw_2_11(SqList *a,ElemType x){
	if(a){
		int i,j = (*a).length;
		for(i=0;i<(*a).length;i++)
			if(x <= (*a).elem[i])	break;
		//判断容量是否足够
		if(a -> length == a -> listsize){
			ElemType *newbase;
			newbase = (ElemType *)realloc(a->elem,(a->listsize+LIST_INCREMENT)*sizeof(SqList));
			if(!newbase)	exit(OVERFLOW);
			a -> elem = newbase;
			a -> listsize += LIST_INCREMENT;
		}
		while(j != i ){
			(*a).elem[j] = (*a).elem[j-1];
			j--;
		}
		(*a).elem[i] = x;
		(*a).length++;
		return OK;
	}
	return ERROR;
}
void main(){
	SqList a;
	int i;
	if(InitList_Sq(&a)){
		for(i = 0 ; i< 5;i++)	ListInsert_Sq(&a,ListLength_Sq(a)+1,i*2);
		hw_2_11(&a,13);
		PrintList_Sq(a);
	}
}
