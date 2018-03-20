
#ifndef BANK_SIMULATION_C
#define BANK_SIMULATION_C
#include "Bank_Simulation.h"

void Bank_Simulation(int CloseTime){
	Bank b;		//银行
	CylSqQueue window[4];		//银行的四个窗口
	ElemType human;			//人
	int time = 0,i,j;		//时间，当每次人来的时候更新。如果time > CloseTime那么就不再招待顾客，准备关门了
	
	OpenForDay(&b,&window);
	j = 1;
	while(TRUE){
		human = (ElemType)malloc(sizeof(people));
		CustomerArrived(human,time);
		time = human -> ArrivalTime;		//更新time
		//printf("%d\n",time);
		CustomerDeparture(b,window,time);	//在新的时间点上是否有顾客离开。
		if(time >= CloseTime)	break;
		JoinInQueue(window,human,time);	//将此人加入到队列中排队等待
	//	printf("第%d位顾客的信息：\n\t到达时间：%d\n\t需要处理的时间：%d\n\t离开时间:%d\n",j++,human -> ArrivalTime,human -> Duration,human -> LevelTime);
	}
	//这里当time到点了以后，银行该关门了。所以在处理掉每个窗口的第一个对象就可以了，剩下排队的人不用处理。
	for(i = 0;i<4;i++){
		GetHead_CSQ(window[i],&human);
		(b -> Sum_people)++;
		(b -> Sum_time) += ((human -> LevelTime) - (human -> ArrivalTime));
	}
	printf("顾客平均逗留时间为:%d\n",((float)(b -> Sum_time))/b->Sum_people);
}

void OpenForDay(Bank *b,CylSqQueue (*q)[4]){		//开业，就是初始化
	int i;
	(*b) = (Bank)malloc(sizeof(bank));
	if(!(*b))	exit(OVERFLOW);
	(*b) -> Sum_people = (*b) -> Sum_time = 0;
	for(i = 0;i<4;i++){
		if(!InitCylSqQueue(&(*q)[i]))	exit(OVERFLOW);
	}
}

void CustomerArrived(ElemType human,int time){	//有新顾客到达
	human -> ArrivalTime = rand()%5 + time;	//假设5分钟之内就会来一个新的顾客
	human -> Duration = rand()%30;		//办理业务所需要的时间在30分钟以内
}

void CustomerDeparture(Bank b,CylSqQueue q[4],int time){	//再新的时间节点上刷新窗口的情况
	ElemType temp;
	int i;
	CylSqQueue cq;
	for(i = 0;i<4;i++){
		cq = q[i];
		if(!CylSqQueueEmpty(cq)){
			GetHead_CSQ(cq,&temp);
			if(temp -> LevelTime <= time){
				DeCylSqQueue(cq,&temp);
				b -> Sum_people++;
				b -> Sum_time += (temp -> LevelTime) - (temp -> ArrivalTime);
			}
		}
	}
}

void JoinInQueue(CylSqQueue q[4],ElemType human,int time){	//判断加入哪个窗口
	int i,k;
	CylSqQueue cq;
	cq = q[0];
	k = 0;
	for(i = 1;i<4;i++){		//去哪个窗口应该是由窗口等待人数最少来判定，而不是由等待时间最少来判定。
		cq = q[i];
		k = CylSqQueueLength(cq) > CylSqQueueLength(q[k])?k:i;
		if(CylSqQueueLength(q[k]) == 0){
			human -> LevelTime = (human -> ArrivalTime) + (human -> Duration);
			EnCylSqQueue(q[k],human);	//如果该窗口每人直接来这里
	//		printf("\n顾客加入的是第%d个窗口\n",k);
			return;
		}
	}
	human -> LevelTime = getLevelTime(q[k],human,time);	//得到离开时间
	EnCylSqQueue(q[k],human);		//加入队列
	//printf("\n顾客加入的是第%d个窗口\n",k);
	return;
}

int getLevelTime(CylSqQueue q,ElemType human,int time){	//离开的时间为前一个人的离开时间 + 处理时间
	int sum = CylSqQueueLength(q),i = 1,lt;
	ElemType e;
	if(sum == 0) return human -> ArrivalTime + human -> Duration;
	e = q -> base[(q->tail -1 +MAX_SIZE)%MAX_SIZE];				//这里是前一个，不是GoHead函数
	return e -> LevelTime + human -> Duration;
}

#endif
