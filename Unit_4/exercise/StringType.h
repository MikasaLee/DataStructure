/**
 * 4.10~4.14题 中需要采用StringType类型
 */

#ifndef STRINGTYPE_H
#define STRINGTYPE_H

#include "../src/mySString.c"
typedef SString StringType;

void StrAssign_ST(StringType t,StringType s);   //将s的值赋给t，s的实际参数可以是串变量或者串常量
int StrCompare_ST(StringType s,StringType t);      //比较s和t，若s > t则返回值>0,若s = t则返回值 = 0;若s < t则返回值<0
int StrLength_ST(StringType s);                    //返回s中的元素个数，即该串的长度
StringType* Concat_ST(StringType s,StringType t);   //返回由s和t连接的新串
StringType* SubString_ST(StringType s,int start,int len);   //当1 <= start <=StrLength(s)且 0 <= len <= StrLength(s) - start + 1 时，返回s中第start和字符起长度为len的字串，否则返回空串
#endif
