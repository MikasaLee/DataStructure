/**
 * P50 3.2.4 迷宫求解的头文件定义
 */

#ifndef MAZEPATH_H
#define MAZEPATH_H

typedef struct PosType{
	int row;		//横坐标
	int cols;		//纵坐标
}PosType;

typedef struct cell{	//迷宫的通道块
	int type;		//通道块的类型，0表示墙，1表示路
	PosType seat;		//通道块在迷宫中的“坐标位置”
	int dir;		//方向,表示当前通道块的下一步，0123分别表示东南西北,-1表示还没有访问过；并且当此方向与前一个方向相反时，跳过这次穷举。
}cell,*ElemType;
/**
 * 有解的判断标准是达到end节点
 * 无解的判断标准是当start的dir为4并且弹出start节点，那么也就是说栈为null。
 */
#include "SqStack.c"
#define N 10	//地图的大小	
typedef ElemType Map[N][N];

Status CreateMap(Map map);	//创建一个地图
void ShowMap(Map map);		//地图的显示
ElemType GetNext(SqStack_L S,Map map);	//设置通道块的方向。
Status MazePath(PosType start,PosType end);	//迷宫求解，start为起始位置，end为终点

#endif
