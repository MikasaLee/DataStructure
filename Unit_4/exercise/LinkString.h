/**
 * 假设以结点大小为n（且附设头结点）的链表结构表示串。试编写实现下列六种串的基本操作StrAssign，StrCopy，StrCompare，StrLength，Concat和SubString的函数。
 */

#ifndef LINKSTRING_H
#define LINKSTRING_H

#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"

#define NODE_LENGTH 1       //每个节点存放的字符的长度

#ifndef HW_4_28_C           //习题4.28需要重写linkNode类型
#define HW_4_28_C
typedef struct linkNode{

    char data[NODE_LENGTH];
    struct linkNode * next;
    
}linkNode,*LinkNode;
#endif

typedef struct linkString{
    
    LinkNode head;      //指向头节点
    int size;           //字符串的长度
}linkString,*LinkString;

Status StrAssign(LinkString *str,char *chars);      //生成一个值为chars的串T
Status StrCopy(LinkString *str,LinkString s);       //由串s拷贝出一个str
int StrCompare(LinkString str1,LinkString str2); //比较str1和str2的大小，大于返回正数等于返回0小于返回负数
int StrLength(LinkString str1);                  //得到str的长度
LinkString Concat(LinkString str1,LinkString str2); //得到str1+str2 失败返回NULL
LinkString SubString(LinkString str1,int pos,int len);  //返回str[pos,pos+len) 

#endif
