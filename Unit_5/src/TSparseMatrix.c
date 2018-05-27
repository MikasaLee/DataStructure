/*************************************************************************
	> File Name: SparseMatrix.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 22 May 2018 08:22:58 PM CST
 ************************************************************************/
/**
 * 三元组顺序表的实现
 */
#ifndef TSPARSEMATRIX_C
#define TSPARSEMATRIX_C

#include "./TSparseMatrix.h"

Status CreateTSMatrix(TSMatrix *M,int mu,int nu){
	(*M) = (TSMatrix)malloc(sizeof(tsm));
	if(!(*M)){
		printf("申请空间失败！\n");
		exit(OVERFLOW);
	}
	(*M) -> mu = mu;
	(*M) -> nu = nu;
	(*M) -> tu = 0;
	return OK;
}

Status DestroyTSMatrix(TSMatrix *M){
	int i;
	if(!(*M)) return OK;
	for(i = 0;i<(*M)-> tu;i++){
		free((*M) -> data[i+1]);		//释放所有非零节点
	}
	free(*M);
	(*M) = NULL;
	return OK;
}

Status SetTSMatrix(TSMatrix *M,ElemType **arr,int arr_mu,int arr_nu){
	int i,j;

	if(!CreateTSMatrix(M,arr_mu,arr_nu)) exit(OVERFLOW);
	for(i = 0;i<arr_mu;i++)
		for(j = 0;j<arr_nu;j++)
			if(arr[i][j] != 0)	SetDataTSMatrix(*M,i,j,arr[i][j]);
	return OK;
}

Status DelDataTSMatrix(TSMatrix M,int i,int j){
	int curor,temp;
	for(curor = 1;(curor <= M -> tu) &&(i >= M -> data[curor] -> i);curor++){	//遍历已经存放的非零元
		if((i == M -> data[curor] -> i) && (j == M -> data[curor] -> j)){
			free(M -> data[curor]);
			for(temp = M -> tu;temp > curor;temp--)	M ->data[temp-1] = M -> data[temp];
			--(M -> tu);
		}
	}
	return OK;

}

Status InsDataTSMatrix(TSMatrix M,int curor,int i,int j,ElemType e){	//往M -> data[curor]位置上插入e
	int temp;
	if(curor > M -> tu+1) return ERROR;

	for(temp = M -> tu;temp >= curor;temp--)	M ->data[temp+1] = M -> data[temp];
	M -> data[curor] = (Triple)malloc(sizeof(triple));
	//设置新值	
	M -> data[curor] -> i = i;
	M -> data[curor] -> j = j;
	M -> data[curor] -> e = e;
	++(M -> tu);
	return OK;

}


Status SetDataTSMatrix(TSMatrix M,int i,int j,ElemType e){
	int curor,temp;
	if(!M||i<0||i>M ->mu||j<0||j>M->nu) return ERROR;	//越界检查
	if(e == 0){				//这里并不可以简单的就返回了，有可能(i,j)已经存在于data[]中了
		DelDataTSMatrix(M,i,j);		//只有此位置上元素为0才删除
		return OK;
	}

	for(curor = 1;(curor <= M -> tu) &&(i >= M -> data[curor] -> i);curor++){	//遍历已经存放的非零元
		if(i == M -> data[curor] -> i){			//行下标已对齐
			if(j == (M -> data[curor] -> j)){		//该位置已经设置过非零元了
				M -> data[curor] -> e = e;		//设置为新值
				return OK;
			}else if(j < (M -> data[curor] -> j)){		//该位置没有设置过非零元
				InsDataTSMatrix(M,curor,i,j,e);
				return OK;
			}
		}else if(i < M ->data[curor] -> i){		//该行没有非零元
			InsDataTSMatrix(M,curor,i,j,e);
			return OK;
		}
	}//for			//这里for出来并不表示curor已经到了最后了，而是行数小于等于i的条件不满足，但是后面有可能还有元素，所以还需要后移。

	InsDataTSMatrix(M,curor,i,j,e);
	return OK;
}

Status GetDataTSMatrix(TSMatrix M,int i,int j,ElemType *e){
	int curor,temp;
	if(!M||i<0||i>M->mu||j<0||j>M->nu) return ERROR;	//越界检查
	for(curor = 1;(curor <= M -> tu)&&(i>= (M -> data[curor] -> i));++curor){	
		if(i == (M -> data[curor] -> i)){
			if(j == (M -> data[curor] -> j)){
				(*e) = M -> data[curor] -> e;
				return OK;
			}
		}
	}//for
	(*e) = 0;
	return OK;
}

void PrintTSMatrix(TSMatrix M){
	int curor;
	if(!M){
		printf("该稀疏矩阵不存在!\n");
		return;
	}
	printf("稀疏矩阵的行数，列数：%d,%d\n",M -> mu,M -> nu);
	printf("稀疏矩阵的非零元个数：%d\n",M -> tu);
	printf("-------------------------------\n");
	for(curor = 1;curor < M -> tu+1;curor++) printf("[%d,%d] = %d\n",M->data[curor]->i,M->data[curor]->j,M->data[curor]->e);
	printf("-------------------------------\n");
	return;
}

Status CopyTSMatrix(TSMatrix M,TSMatrix *T){
	int curor;
	if(!M) return ERROR;
	if(!CreateTSMatrix(T,M -> mu,M -> nu)) exit(OVERFLOW);
	for(curor = 0;curor < M -> tu;curor++) 
		if(!SetDataTSMatrix(*T,M -> data[curor+1]->i,M -> data[curor+1] -> j,M -> data[curor+1]->e))
			return ERROR;
	return OK;
}


Status AddTSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q){	/**2018.5.27：不要直接对Q进行操作，如果Q是M/N **/
	int curor;
	ElemType temp_N,temp_Q;
	TSMatrix temp;
	if(M -> mu != N -> mu || M -> nu != N -> nu){
		(*Q) = NULL;
		return ERROR;
	}
	
	if(CopyTSMatrix(M,&temp)){
		for(curor = 0; (curor < N -> tu)&&(N -> data[curor+1]);curor++){
			GetDataTSMatrix(N,N -> data[curor+1] -> i,N -> data[curor+1]->j,&temp_N);
			GetDataTSMatrix(temp,N -> data[curor+1] -> i,N -> data[curor+1]->j,&temp_Q);
			SetDataTSMatrix(temp,N -> data[curor+1] -> i,N -> data[curor+1]->j,temp_Q+temp_N);
		}
		(*Q) = temp;
		return OK;
	}
	exit(OVERFLOW);
}

Status SubTSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q){
	int curor;
	ElemType temp_N,temp_Q;
	TSMatrix temp;
	if(M -> mu != N -> mu || M -> nu != N -> nu){
		(*Q) = NULL;
		return ERROR;
	}
	
	if(CopyTSMatrix(M,&temp)){
		for(curor = 0;curor < N -> tu ;curor++){
			GetDataTSMatrix(N,N -> data[curor+1] -> i,N -> data[curor+1]->j,&temp_N);
			GetDataTSMatrix(temp,N -> data[curor+1] -> i,N -> data[curor+1]->j,&temp_Q);
			SetDataTSMatrix(temp,N -> data[curor+1] -> i,N -> data[curor+1]->j,temp_Q-temp_N);
		}
		(*Q) = temp;
		return OK;
	}
	exit(OVERFLOW);
}

Status MultTSMatrix(TSMatrix M,TSMatrix N,TSMatrix *Q){
	int i,j,row,cols;
	ElemType temp_N,temp_M,temp_Q;
	if(M -> nu != N -> mu){
		(*Q) = NULL;
		return ERROR;
	}
	
	if(CreateTSMatrix(Q,M -> mu,N -> nu)){
		for(row = 0;row<(*Q) -> mu;row++){
			for(cols = 0;cols <(*Q) -> nu;cols++){
				//求(*Q)[row][cols]的值
				GetDataTSMatrix(*Q,row,cols,&temp_Q);
				for(i = 0;i < M ->nu;i++){
					GetDataTSMatrix(M,row,i,&temp_M);
					if(temp_M == 0) continue;
					GetDataTSMatrix(N,i,cols,&temp_N);
					if(temp_N == 0) continue;
					temp_Q += (temp_M * temp_N);
				}
				SetDataTSMatrix(*Q,row,cols,temp_Q);
			}
		}
	}
	return OK;
}


Status TransposeTSMatrix(TSMatrix M,TSMatrix *T){
	int curor;
	if(CreateTSMatrix(T,M -> nu,M -> mu)){
		for(curor = 0;curor<M -> tu;curor++){
			SetDataTSMatrix(*T,M->data[curor+1]->j,M -> data[curor+1]->i,M -> data[curor+1]->e);
		}
		return OK;
	}
	exit(OVERFLOW);
}


#endif
