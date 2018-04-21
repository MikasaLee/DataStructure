/**
 * 堆分配存储表示
 * 	如果以后需要字符串，强烈建议用此方法实现的字符串
 */
#ifndef MYHSTRING_H
#define MYHSTRING_H

#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"

#define HSTRING_INIT_CAPACITY 10	//默认初始化容量大小
#define HSTRING_INCREASE 5
typedef struct{
	char *Base;
	int size;
	int capacity;
}hString,*HString;
/**创建字符串的三种方式*/
Status InitStr(HString *str);
Status StrAssign(HString *str,char* chars);	//生成一个值为chars的串T。
Status StrCopy(HString *str,HString s);		//由串s复制得串str

Bool StrEmpty(HString str);			//str是否为空
int StrCompare(HString str1,HString str2);	//比较str1和str2的大小，大于返回正数等于返回0小于返回负数
int StrLength(HString str);			//得到str的长度
Status ClearString(HString str);		//将s清为空串
Status Concat(HString *T,HString S1,HString S2);	//用T返回由S1和S2连接而成的新子串
Status SubString(HString *sub,HString S,int pos,int len);	//用sub返回串S的[pos,pos+len)的子串
int Index(HString S,HString T,int pos);		//若主串S中存在和串T值相同的子串，则返回它在主串S中第pos个字符之后第一次出现的位置，否则返回-1
Status Replace(HString *S,HString T,HString V);	//用V替换主串S中出现的所有与T相等的不重叠的子串
Status StrInsert(HString *S,int pos,HString T);	//在串S的第pos个字符之前插入串T
Status StrDelete(HString *S,int pos,int len);	//从串S中删除第pos个字符起长度为len的子串
Status DestroyString(HString *S);		//销毁串S
void PrintString(HString S);			
#endif
