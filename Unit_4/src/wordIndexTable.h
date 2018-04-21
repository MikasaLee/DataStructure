/**
 * 4.4.2 建立词索引表
 */
#ifndef WORDINDEXTABLE_H
#define WORDINDEXTABLE_H

#ifndef ELEMTYPE
#define ELEMTYPE
typedef int ElemType;			//规定ElemType为int
#endif

#include "../../Unit_2/src/SqList.c"	//提供动态数组
#include "index.c"			//提供字符串

typedef struct{
	int id;			//书号
	HStr
}book,*Book;
typedef struct{


}wordIndexTable,*WIT;

#endif

