/*************************************************************************
	> File Name: hw_5_38.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 30 May 2018 05:21:42 PM CST
 ************************************************************************/

/**
 * 5.38❹试编写算法，依次从左至右输出广义表中第l层的原子项。
 *
 *         例如：广义表(a, (b, (c)), (d))中的a为第一层的原子项；b和d为第二层的原子项；c为第三层的原子项。
 */

#ifndef MAIN
#define MAIN
#include "../src/EGList.c"		//导入广义表
void visit(AtomType e,int i);
Status Traverse_hw_5_38(EGList L,int i,int l){		//输出第l层
	EGList p;
	if(!L) return ERROR;
	if(L-> tag == ATOM){
		if(i == l) visit(L -> Union.atom,i);
	}
	else Traverse_hw_5_38(L -> Union.hp,i+1,l);
	Traverse_hw_5_38(L -> tp,i,l);
	
	return OK;
}

void visit(AtomType e,int i){	//第二个参数表示层数
	printf("Atom=%c,Num=%d\n",e,i);
}

int main(int argc,char **argv){
	EGList L,g1,g2,g3;
	SString S1,S2,S3;
	char *s1 ="(((a,b,c),d,e),i,(f,g,h))";
	
	printf("---------测试CreateEGList()---------------\n");
	
	StrAssign(S1,s1);
	if(CreateEGList(&g1,S1)) Traverse_hw_5_38(g1,0,2);
	printf("\n");
}
#endif
