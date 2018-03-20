/**
 * 银行业务的模拟程序，计算一天中客户在银行中逗留的平均时间
 */

#ifndef BANK_SIMULATION_H
#define BANK_SIMULATION_H

typedef struct{
	int ArrivalTime;	//每个人的到达时间
	int Duration;		//办理事务所需要的时间
	int LevelTime;		//离开时间
}people,*ElemType;		//注：每个人在银行的时间应该是LevelTime - ArrivalTime

typedef struct{
	int Sum_people;		//已经送走的人数
	int Sum_time;		//送走的人花费的总时间。
}bank,*Bank;
#include "CylSqQueue.c"

void Bank_Simulation(int CloseTime);			//银行业务模拟，CloseTime为关门时间
void OpenForDay(Bank *bank,CylSqQueue (*q)[4]);		//银行一天的开业，相当于初始化操作;q[4]表示由4个窗口来处理业务
void CustomerArrived(ElemType human,int time);			//顾客到达时间。
void CustomerDeparture(Bank b,CylSqQueue q[4],int time);	//顾客离开时间
void JoinInQueue(CylSqQueue q[4],ElemType human,int time);	//判断去哪个窗口
int getLevelTime(CylSqQueue q,ElemType human,int time);		//计算human的离开时间。

#endif

