/**
 * 2.12(String字符串的比较大小)	设A=(a1,...,an)和B=(b1,...,bn)均为顺序表，
 * A'和B'分别为A和B中除去最大共同前缀后的子表（例如，A=(x,y,y,z,x,z)，B=(x,y,y,z,y,x,x,z)，则两者中最大的共同前缀为(x,y,y,z)，
 * 在两表中除去最大共同前缀后的子表分别为A'=(x,z)和B'=(y,x,x,z)）。
 * 若A'=B'=空表，则A=B；
 * 若A'=空表，而B'≠空表，或者两者均不为空表，且A'的首元小于B'的首元，则A<B；
 * 否则A>B。试写一个比较A，B大小的算法（请注意：在算法中，不要破坏原表A和B，并且，也不一定先求得A'和B'才进行比较）。
 */

#include "../src/SqList.c"
int hw_2_12(SqList a,SqList b){
	int i,j;
	i = j = 0;
	while(i != a.length-1 && i != b.length-1){
		if(a.elem[i] > b.elem[i])
			return 1;
		else if(a.elem[i] < b.elem[i])
			return -1;	
		i++;
	}
	if(a.length == b.length) return 0;
	return i == a.length-1?-1:1;
}
void main(){
	SqList a,b;
	int i;
	if(InitList_Sq(&a)&& InitList_Sq(&b)){
		for(i = 0 ; i< 4;i++)	ListInsert_Sq(&a,ListLength_Sq(a)+1,i*3);
		for(i = 0 ; i< 5;i++)	ListInsert_Sq(&b,ListLength_Sq(b)+1,i*3);
		switch(hw_2_12(a,b)){
			case -1:
				printf("a < b\n");
				break;
			case 1:
				printf("a > b\n");
				break;
			default:
				printf("a == b\n");
				break;
		}
	}
}
