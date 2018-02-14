/**
 *  在2.34至2.36题中，“异或指针双向链表”类型XorLinkedList和指针异或函数XorP定义为：
 */
#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"
typedef struct XorNode{
	char data;
	struct XorNode *LRPtr;
}XorNode, *XorPointer;

typedef struct{	//无头结点的异或指针双向链表
	XorPointer Left, Right;	//分别指向链表的左端和右端
}XorLinkedList;
XorPointer XorP(XorPointer p, XorPointer q); //指针异或函数XorP返回指针p和q的异或(XOR)值
