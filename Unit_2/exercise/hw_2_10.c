/**
 * 2.10 指出以下算法的错误和低效（即费时）之处，并将它改写为一个既正确又高效的算法。
 *
 *     Status  DeleteK(SqList &a, int i, int k){
 *     		//本过程从顺序存储结构的线性表a中删除第i个元素起的k个元素
 *     		if(i<1 || k<0 || i+k>a.length)  return INFEASIBLE;              //参数不合法
 *              else{
 *              	for(count=1; count<k; count++){
 *              	//删除一个元素
 *              		for(j=a.length; j>=i+1; j--) a.elem[j-1] = a.elem[j];
 *              		a.length--;
 *              	}
 *              }
 *                     return OK;
 *    }//DeleteK
 */
/**
 * Error 1:第一个for循环会循环k-1次，不是k次
 * Error 2:第二个for循环中，逻辑错误。
 * 低效：时间复杂度为O(n2);
 */
//改进：
#include "../src/SqList.c"

Status DeleteK(SqList *a,int i,int k){
	//本过程从顺序存储结构的线性表a中删除第i个元素起的k个元素
	if(i<1 || k<0 || i+k>(*a).length)  return ERROR;              //参数不合法
	int p;
	for(p = i+k-1;p<(*a).length;p++)	(*a).elem[p-k] = (*a).elem[p];
	(*a).length -=k;
	return OK;
}// O(n)

void main(){
	SqList L;
	int i;
	if(InitList_Sq(&L)){
		for(i = 0;i<10;i++)
			ListInsert_Sq(&L,ListLength_Sq(L)+1,i);
		DeleteK(&L,3,5);
		PrintList_Sq(L);
	}
}
