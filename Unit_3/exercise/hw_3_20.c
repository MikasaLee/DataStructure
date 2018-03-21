/**
 * 3.20 
 * 	假设以二维数组g(1…m, 1…n)表示一个图像区域，g[i,j]表示该区域中点(i,j)所具颜色，其值为从0到k的整数。
 * 	编写算法置换点(i0,j0)所在区域的颜色。约定和(i0,j0)同色的上、下、左、右的邻接点为同色区域的点。
 */
#ifndef HW_3_20_C
#define HW_3_20_C
#define K 3	//有4中颜色
#define M 6	//二维数组的行数
#define N 5	//二维数组的列数
typedef struct{
	int row;	//行
	int cols;	//列
	int color;	//该区域的颜色。
}cell,*ElemType;

typedef ElemType Area[M][N];

#include "../src/SqStack.c"

Status CreatePicture(Area *area);		//创建一个图像区域
Status ChangeColor(Area *area,int row,int cols,int color);	//将[row,cols]区域的颜色改为color
int main(int argc,char **args){
	return 0;
}



#endif

