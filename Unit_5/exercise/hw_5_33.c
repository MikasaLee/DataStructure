/*************************************************************************
	> File Name: hw_5_33.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 29 May 2018 07:27:11 PM CST
 ************************************************************************/

/**
 * 5.33 试编写递归算法，输出广义表中所有原子项及其所在层次。
 */

#include "../src/EGList.c"

void visit(AtomType,int);	//第二个参数表示层数
Status Traverse_hw_5_33(EGList L,int i,void (*visit)(AtomType,int)){
	if(!L) return ERROR;
	if(L -> tag == ATOM) visit(L -> Union.atom,i);
	else{
		Traverse_hw_5_33(L -> Union.hp,i+1,visit);
		Traverse_hw_5_33(L -> tp,i,visit);
	}
	return OK;
}

void visit(AtomType e,int i){	//第二个参数表示层数
	printf("Atom=%c,Num=%d\n",e,i);
}

int main(int argc,char **argv){
	EGList L,g1,g2,g3;
	SString S1,S2,S3;
	char *s1 ="(((a,b,c),d,e),(b,c,d))";
	
	printf("---------测试CreateEGList()---------------\n");
	
	StrAssign(S1,s1);
	if(CreateEGList(&g1,S1)) Traverse_hw_5_33(g1,0,visit);
	printf("\n");

	return 0;
}
