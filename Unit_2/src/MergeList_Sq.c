/*
 * 已知线性表La和Lb都是非递减有序排列，
 * 现要求La,Lb合并为一个新表Lc，且Lc中依然是非递减序列
 */
#include "SqList.c"
void MergeList_Sq(SqList a,SqList b,SqList *c){
	int p = ListLength_Sq(a),q = ListLength_Sq(b);
	int i = 1,j = 1;	//i为a的指针索引,j为b的指针索引
	ElemType ea,eb ;	//ea，eb分别为当前a，b表的当前索引的值
	InitList_Sq(c);
	if(ListEmpty_Sq(a)){	//若a表为空，则直接用b来初始化c
		for(i = 1;i<=ListLength_Sq(b);i++){
			GetElem_Sq(b,i,&eb);
			ListInsert_Sq(c,i,eb);	
		}
		return;
	}	
	
	if(ListEmpty_Sq(b)){	//若b表为空，则直接用a来初始化c
		for(i = 1;i<=ListLength_Sq(a);i++){
			GetElem_Sq(a,i,&ea);
			ListInsert_Sq(c,i,ea);	
		}
		return;
	}
	//若ab表都不为空,则依次比较后在按非递减序列加入
	while(i<=ListLength_Sq(a) || j<=ListLength_Sq(b)){
		//先判断已经添加完一个表的情况
		if(i>ListLength_Sq(a) || j >ListLength_Sq(b)){
			while(i<=ListLength_Sq(a)){
				GetElem_Sq(a,i++,&ea);
				ListInsert_Sq(c,ListLength_Sq(*c)+1,ea);
			}
			while(j<=ListLength_Sq(b)){
				GetElem_Sq(b,j++,&eb);
				ListInsert_Sq(c,ListLength_Sq(*c)+1,eb);
			}

			return;
			
		}//if

		//一般情况
		GetElem_Sq(a,i,&ea); GetElem_Sq(b,j,&eb);
		if(ea < eb){
			ListInsert_Sq(c,ListLength_Sq(*c)+1,ea);i++;
		}else{
			ListInsert_Sq(c,ListLength_Sq(*c)+1,eb);j++;
		}

	}//while
	return;
}
