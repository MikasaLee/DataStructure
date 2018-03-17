/**
 * P50 3.2.4 迷宫求解问题
 * 2018.3.17 OK！测验的几个刁难点都可以到达
 * 	但是本人知道程序还有瑕疵，发现bug请联系本人邮箱 770486267@qq.com 大家共同学习共同进步 
 */

#ifndef MAZEPATH_C
#define MAZEPATH_C

#include "MazePath.h"
#include "stdlib.h"		//提供随机函数
Bool visit_Maze(ElemType e);

Status CreateMap(Map map){		//创建地图，边界都为墙，其他位置随机生成墙
	int i,j,k;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			map[i][j] = (ElemType)malloc(sizeof(cell));
			if(i == 0 || i == N-1 || j == 0 || j == N-1) map[i][j] -> type = 0;
			else map[i][j] -> type = 1;	//其他位置先不生成墙
			map[i][j] -> seat.row = i;
			map[i][j] -> seat.cols = j;
			map[i][j] -> dir = -1;
		}
	}
	//生成10个随机的墙
	for(k = 0;k<34;k++){
		i = rand()%10;
		j = rand()%10;
		map[i][j] -> type = 0;
	}

	return OK;
}
void ShowMap(Map map){
	int i,j;
	for(i = 0;i<N;i++){
		for(j = 0;j<N;j++)
			if(map[i][j] -> type == 0)	printf("■ "); 
			else printf("  ");
			
		printf("\n");
	}
}

ElemType GetNext(SqStack_L S,Map map){
	ElemType next,pre,top;
	Pop_Sq(S,&top);
	top -> dir++;		//栈顶方向改变
	int row = -1,cols,preDir = -1;
	if(!StackEmpty_Sq(S)){
		GetTop_Sq(S,&pre);
		preDir = pre -> dir;
	}
	Push_Sq(S,top);
	if(preDir == ((top -> dir+2)%4)) (top -> dir)++; //不能往回走,跳过这个再次寻找
	
	if(top -> dir == 0){		//方向为东
		row = top -> seat.row;
		cols = top -> seat.cols+1;
	}else if(top -> dir == 1){	//方向为南
		row = top -> seat.row+1;
		cols = top -> seat.cols;
	}else if(top -> dir == 2){	//方向为西
		row = top -> seat.row ;
		cols = top -> seat.cols-1;
	}else if(top -> dir == 3){	//方向为北
		row = top -> seat.row-1;
		cols = top -> seat.cols;
	}else row = -1;		//top->dir => 4

	if(row != -1){
		next = map[row][cols];
		return next;
	}
	Pop_Sq(S,&next);
	return next;		//下一跳就是栈顶元素
}

Status MazePath(PosType start,PosType end){
	Map map;
	SqStack_L S;
	int i,j;
	ElemType e1;
	if(CreateMap(map) && (map[start.row][start.cols] -> type == 1)&&(map[end.row][end.cols] -> type == 1)){		//游戏开始！
		ShowMap(map);
		InitStack_Sq(&S);
		e1 = map[start.row][start.cols];
		Push_Sq(S,e1);		//将起点入栈
		while(e1 -> seat.row != end.row || e1 -> seat.cols != end.cols){			//开始穷举
			e1 = GetNext(S,map);		//有下一跳得到下一跳，没有下一跳弹出当前栈顶元素
			if(StackEmpty_Sq(S)){		//当弹出起点时，说明无解
				return ERROR;
			}
			if(e1 -> type == 1 && e1 -> dir <=3){
				Push_Sq(S,e1);
			}
		}//while
		StackTraverse_Sq(S,visit_Maze);
		printf("\n");
		ShowMap(map);
		return OK;
	}
	return ERROR;
}

Bool visit_Maze(ElemType e){
	printf("[%d][%d] -> ",e->seat.row,e->seat.cols);

}

#endif

