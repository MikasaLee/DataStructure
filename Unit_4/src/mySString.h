/**
 * 定长顺序存储实现字符串
 * 	规定一个串的长度范围，超过预定义长度的串值被舍去
 * 	其中下标0规定了其串的长度，0表示空串。
 *
 * 定长顺序存储实现的字符串有很多弊端，一般不会用此方法来实现字符串。
 */
/**
 * c语言中：函数参数为一个数组，实际传递的是该数组的指针
 */
#ifndef MYSSTRING_H
#define MYSSTRING_H

#include "stdio.h"
#include "stdlib.h"
#include "../../Unit_1/src/myDefine.c"
#ifndef MAXSTRLEN
#define MAXSTRLEN 25
#endif
typedef unsigned char SString[MAXSTRLEN+1];	//下标为0用来存放串的长度

Status StrAssign(SString str,char* chars);	//生成一个值为chars的串T。
Status StrCopy(SString str,SString s);		//由串s复制得串str
Bool StrEmpty(SString str);			//str是否为空
int StrCompare(SString str1,SString str2);	//比较str1和str2的大小，大于返回正数等于返回0小于返回负数
int StrLength(SString str);			//得到str的长度
Status ClearString(SString str);		//将s清为空串
Status Concat(SString T,SString S1,SString S2);	//用T返回由S1和S2连接而成的新子串
Status SubString(SString sub,SString S,int pos,int len);	//用sub返回串S的[pos,pos+len)的子串
int Index(SString S,SString T,int pos);		//若主串S中存在和串T值相同的子串，则返回它在主串S中第pos个字符之后第一次出现的位置，否则返回-1
Status Replace(SString S,SString T,SString V);	//用V替换主串S中出现的所有与T相等的不重叠的子串
Status StrInsert(SString S,int pos,SString T);	//在串S的第pos个字符之前插入串T
Status StrDelete(SString S,int pos,int len);	//从串S中删除第pos个字符起长度为len的子串
Status DestroyString(SString S);		//销毁串S
void PrintString(SString S);
#endif
