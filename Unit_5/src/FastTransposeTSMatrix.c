/*************************************************************************
	> File Name: FastTransposeTSMatrix.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Wed 23 May 2018 09:42:21 PM CST
 ************************************************************************/

#include "./TSparseMatrix.c"

/**
 * 利用缓存来求转置矩阵(设矩阵A要转置成矩阵B):
 *		按照A.data中三元组的次序进行转置，并将转置后的三元组置于B.data中的恰当位置。如果能预先确定矩阵B中每一列(即矩阵A的每一行)的第一个非零元在b.data中应有的位置，那么在对a.data中的三元组依次做转置时，便可直接放到b.data中恰当的位置(注1)，为了确定这些位置，在转置前，**应先求得M的每一列中非零元的个数，进而求得每一列的第一个非零元在b.data中的位置。 **
 * 
 *
 * --------------------------------------------------------
 * 
 * 注1：这里的原理是因为矩阵A.data中已经是有序的（先按行号从小到大，每行在按照列号从小到大排序）
 * ，所以转置后，可以保证B.data中是**先按列号从小到大，每一列中再按行号从小到大**。如果我们继续用行优先的准则来看B.data，会发现B.data每行都是有序的(比如(3,1)一定在(3,5)的上面，但是中间可能夹杂着(2,4),(4,4)等等。。),所以我们是根据这个特点来实现快速转置的。
 *
 */

Status FastTransposeTSMatrix(TSMatrix M,TSMatrix *T){
	if(!M)	return ERROR;
	if(!CreateTSMatrix(T,M->nu,M -> mu)) exit(OVERFLOW);
	
	int *cpot,curor,row,cols;
	GetHelp(M,&cpot);
	
	for(curor =1 ;curor<=M -> tu;curor++){
		row = M -> data[curor] -> j;		//row表示T的行
		cols = M -> data[curor] -> i;		//cols表示T的列
		(*T) -> data[cpot[row]] = (triple *)malloc(sizeof(triple));
		(*T) -> data[cpot[row]] -> i = row;
		(*T) -> data[cpot[row]] -> j = cols;
		(*T) -> data[cpot[row]] -> e = M -> data[curor] -> e;
		(cpot[row])++;
		((*T) -> tu)++;
	}
	return OK;
}

Status GetHelp(TSMatrix M,int **cpot){		//统计M中每一列的第一个数，放入cpot中
	int *num,curor;
	(*cpot) = malloc(sizeof(int)*(M -> nu));
	num = malloc(sizeof(int)*(M -> nu));
	if(!num || !(*cpot)) exit(OVERFLOW);

	for(curor = 1;curor <= M -> tu;curor++)
		num[M -> data[curor] -> j]++;
	for(curor = 1,(*cpot)[0]=1;curor<M -> nu;curor++)
		(*cpot)[curor] = (*cpot)[curor-1]+num[curor-1];
	free(num);
	return OK;
}
