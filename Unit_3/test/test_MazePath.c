#include "../src/MazePath.c"

int main(int argc,char **args){
	PosType start,end;
	start.row = start.cols = 1;
	end.row = 1;
	end.cols = 3;
	if(!MazePath(start,end)) printf("\n迷宫无解\n");
}
