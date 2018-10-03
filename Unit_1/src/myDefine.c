#ifndef MYDEFINE_H
#define MYDEFINE_H

#include "stdio.h"
#include "stdlib.h"
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#ifndef OVERFLOW 
#define OVERFLOW -2
#endif
typedef int Status;
typedef int Bool;
/**
 * 基本函数(简单的可以直接用类库来表示，复杂的需要动手写)：
 * 求最大值：max(表达式1, ...，表达式n)
 * 求最小值：min(表达式1,...., 表达式n)
 * 求绝对值：abs(表达式)
 * 求不足整数值：floor(表达式)
 * 求进位整数值：ceil(表达式)
 * 判定文件结束：eof(文件变量) 或eof
 * 判定行结束：eoln(文件变量) 或eoln
 */

#endif
