/**
 * 3.20 
 * 	假设以二维数组g(1…m, 1…n)表示一个图像区域，g[i,j]表示该区域中点(i,j)所具颜色，其值为从0到k的整数。
 * 	编写算法置换点(i0,j0)所在区域的颜色。约定和(i0,j0)同色的上、下、左、右的邻接点为同色区域的点。
 */
#ifndef HW_3_20_C
#define HW_3_20_C
#define K 3	//有3种颜色
#define M 10	//二维数组的行数
#define N 8	//二维数组的列数
typedef struct{
	int row;	//行
	int cols;	//列
	int color;	//该区域的颜色。
	int dir;	//同MazePath.h中的cell.dir类似，0123分别表示东南西北，-1表示还没有访问过；并且当此方向与前一个方向相反时，跳过这次穷举
}cell,*ElemType;

typedef ElemType Area[M][N];

#include "../src/SqStack.c"

Status CreatePicture(Area *area);		//创建一个图像区域
Status ChangeColor(Area area,int row,int cols,int color);	//将[row,cols]区域的颜色改为color
void Show(Area area);	//显示图像区域
ElemType GetNext(Area area,SqStack_L S);	//得到下一个位置
int main(int argc,char **args){
	Area area;
	int i,j;
	if(CreatePicture(&area)){
		ChangeColor(area,7,5,0);
	}
	return 0;
}
Status CreatePicture(Area *area){
	int i,j;
	i = j = 0;
	for(i =0;i<M;i++){
		for(j = 0;j<N;j++){
			(*area)[i][j] = (ElemType)malloc(sizeof(cell));
			if(!(*area)[i][j])	exit(OVERFLOW);
			(*area)[i][j] -> row = i;
			(*area)[i][j] -> cols = j;
			(*area)[i][j] -> color = rand()%K;
			(*area)[i][j] -> dir = -1;
		}
	}
	return OK;
}
Status ChangeColor(Area area,int row,int cols,int color){	//将[row,cols]区域的颜色改为color
	ElemType start,temp;
	SqStack_L S;
	int srcColor,desColor;
	if(!area)	exit(OVERFLOW);
	start = area[row][cols];
	if(start && InitStack_Sq(&S)){
		srcColor = start -> color;
		if(srcColor == color){	//如果颜色一样的话就不需要再修改了
			printf("\n不用修改，颜色一样\n");
			Show(area);
			return OK;
		}
		
		desColor = color;
		printf("更改颜色前的区域：\n");
		Show(area);
		Push_Sq(S,start);
		while(!StackEmpty_Sq(S)){
			temp = GetNext(area,S);
			if(temp -> color == srcColor && temp -> dir < 4)	Push_Sq(S,temp);	//颜色相等才能入栈
			if(temp -> dir >= 4)	temp -> color = desColor;
		//	printf("\n嘤嘤嘤\n");
		}//while
		printf("更改颜色后的区域：\n");
		Show(area);
	}
}
void Show(Area area){
	int i,j;
	for(i = 0;i<M;i++){
		for(j = 0;j<N;j++)
			printf("%d ",area[i][j] -> color);
		printf("\n");
	}
}
ElemType GetNext(Area area,SqStack_L S){
	ElemType temp,top,next,pre;
	int i,j,dir,preDir = -1,row,cols;
	if(StackEmpty_Sq(S))	exit(OVERFLOW);
	Pop_Sq(S,&top);
	if(!StackEmpty_Sq(S)){
		GetTop_Sq(S,&pre);
		preDir = pre -> dir;
	}

	(top -> dir)++;
	Push_Sq(S,top);

	if(preDir == (top -> dir +2)%4)	(top -> dir)++;		//不能往回走
	switch(top -> dir){
		case 0:	row = top -> row;		//往东走；
			cols = top -> cols +1;
			break;
		case 1:	row = top -> row + 1;		//往南走；
			cols = top -> cols;
			break;
		case 2:	row = top -> row;		//往西走；
			cols = top -> cols - 1;
			break;
		case 3:	row = top -> row - 1;		//往北走；
			cols = top -> cols;
			break;
	}
	if(top -> dir == 4 || row < 0 || row > M-1 || cols < 0 || cols > N-1){		//此位置都已经遍历了，可以返回并更改其颜色。/越界了
		Pop_Sq(S,&top);
		return top;
	}
	return area[row][cols];
}
#endif
