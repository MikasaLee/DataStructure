#include "stdio.h"
#include "../src/CreateList_L.c"
void main(){
	LinkList L;
	CreateList_L(&L,5);
	Print_L(L);

}
