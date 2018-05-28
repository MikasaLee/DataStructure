/*************************************************************************
	> File Name: SparseMatrix.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Tue 22 May 2018 08:22:58 PM CST
 ************************************************************************/
/**
 * 行逻辑链接的顺序表的实现
 */
#ifndef RLSPARSEMATRIX_C
#define RLSPARSEMATRIX_C

#include "./RLSparseMatrix.h"

Status CreateRLSMatrix(RLSMatrix *M,int mu,int nu){
	int i;
	(*M) = (RLSMatrix)malloc(sizeof(RLSm));
	(*M) -> rpos = (int *)malloc(sizeof(int)*mu);
	if(!(*M) ||!((*M) -> rpos)){
		printf("申请空间失败！\n");
		exit(OVERFLOW);
	}
	for(i = 0;i<mu;i++)	(*M) -> rpos[i] = 1;	//初始值为1
	(*M) -> mu = mu;
	(*M) -> nu = nu;
	(*M) -> tu = 0;
	return OK;
}

Status DestroyRLSMatrix(RLSMatrix *M){
	int i;
	if(!(*M)) return OK;
	for(i = 0;i<(*M)-> tu;i++){
		free((*M) -> data[i+1]);		//释放所有非零节点
	}
	free((*M) -> rpos);
	free(*M);
	(*M) = NULL;
	return OK;
}

Status SetRLSMatrix(RLSMatrix *M,ElemType **arr,int arr_mu,int arr_nu){
	int i,j;

	if(!CreateRLSMatrix(M,arr_mu,arr_nu)) exit(OVERFLOW);
	if(!arr) return OK;
	for(i = 0;i<arr_mu;i++)
		for(j = 0;j<arr_nu;j++)
			if(arr[i][j] != 0)	SetDataRLSMatrix(*M,i,j,arr[i][j]);
	return OK;
}

Status DelDataRLSMatrix(RLSMatrix M,int i,int j){		//只有此位置上元素为0才删除
	int curor,temp;
	for(curor = M -> rpos[i];(curor <= M -> tu)&&(i == M ->data[curor] -> i);curor++){	//遍历已经存放的非零元
		if(j == M -> data[curor] -> j){
			free(M -> data[curor]);
			for(temp = M -> tu;temp > curor;temp--)	M ->data[temp-1] = M -> data[temp];
			--(M -> tu);
			while((++i) < M -> mu) (M -> rpos[i])--;
		}
	}
	return OK;

}

Status InsDataRLSMatrix(RLSMatrix M,int curor,int i,int j,ElemType e){	//往M -> data[curor]位置上插入e
	int temp;
	if(curor > M -> tu+1) return ERROR;

	for(temp = M -> tu;temp >= curor;temp--)	M ->data[temp+1] = M -> data[temp];
	M -> data[curor] = (Triple)malloc(sizeof(triple));
	//设置新值	
	M -> data[curor] -> i = i;
	M -> data[curor] -> j = j;
	M -> data[curor] -> e = e;
	++(M -> tu);
	
	while((++i) < M -> mu) (M -> rpos[i])++;
	return OK;

}


Status SetDataRLSMatrix(RLSMatrix M,int i,int j,ElemType e){
	int curor,temp;
	if(!M||i<0||i>M ->mu||j<0||j>M->nu) return ERROR;	//越界检查
	if(e == 0){				//这里并不可以简单的就返回了，有可能(i,j)已经存在于data[]中了
		DelDataRLSMatrix(M,i,j);		//只有此位置上元素为0才删除
		return OK;
	}
//	printf("rpos[%d]=%d\n",i,M -> rpos[i]);

	for(curor = M -> rpos[i];(curor <= M -> tu)&&(i == M -> data[curor] -> i);curor++){	//遍历第i行已经存放的非零元
//		printf("rpos[%d]=%d\n",i,M -> rpos[i]);
		if(i == M -> data[curor] -> i){			//行下标已对齐
			if(j == (M -> data[curor] -> j)){		//该位置已经设置过非零元了
				M -> data[curor] -> e = e;		//设置为新值
				return OK;
			}else if(j < (M -> data[curor] -> j)){		//该位置没有设置过非零元
				InsDataRLSMatrix(M,curor,i,j,e);
				return OK;
			}
		}
	}//for			//这里for出来并不表示curor已经到了最后了，而是行数小于等于i的条件不满足，但是后面有可能还有元素，所以还需要后移。
//	printf("rpos[%d]=%d,curor=%d\n",i,M -> rpos[i],curor);
	InsDataRLSMatrix(M,curor,i,j,e);
//	printf("嘤嘤嘤\n");
	return OK;
}

Status GetDataRLSMatrix(RLSMatrix M,int i,int j,ElemType *e){
	int curor,temp;
	if(!M||i<0||i>M->mu||j<0||j>M->nu) return ERROR;	//越界检查
	for(curor = M -> rpos[i];(curor <= M -> tu)&&(i == M -> data[curor] -> i);curor++){
		if(j == (M -> data[curor] -> j)){
			(*e) = M -> data[curor] -> e;
			return OK;
		}
	}//for
	(*e) = 0;
	return OK;
}

void PrintRLSMatrix(RLSMatrix M){
	int curor;
	if(!M){
		printf("该稀疏矩阵不存在!\n");
		return;
	}
	printf("稀疏矩阵的行数，列数：%d,%d\n",M -> mu,M -> nu);
	printf("稀疏矩阵的非零元个数：%d\n",M -> tu);
	printf("-------------------------------\n");
	for(curor = 1;curor <= M -> tu;curor++) 
		printf("[%d,%d] = %d\n",M->data[curor]->i,M->data[curor]->j,M->data[curor]->e);
	printf("-------------------------------\n");
	return;
}

Status CopyRLSMatrix(RLSMatrix M,RLSMatrix *T){
	int curor;
	if(!M) return ERROR;
	if(!CreateRLSMatrix(T,M -> mu,M -> nu)) exit(OVERFLOW);
	for(curor = 0;curor < M -> tu;curor++) 
		if(!SetDataRLSMatrix(*T,M -> data[curor+1]->i,M -> data[curor+1] -> j,M -> data[curor+1]->e))
			return ERROR;
	return OK;
}


Status AddRLSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix *Q){
	int curor;
	ElemType temp_N,temp_Q;
	if(M -> mu != N -> mu || M -> nu != N -> nu){
		(*Q) = NULL;
		return ERROR;
	}
	
	if(CopyRLSMatrix(M,Q)){
		for(curor = 0; (curor < N -> tu)&&(N -> data[curor+1]);curor++){
			GetDataRLSMatrix(N,N -> data[curor+1] -> i,N -> data[curor+1]->j,&temp_N);
			GetDataRLSMatrix(*Q,N -> data[curor+1] -> i,N -> data[curor+1]->j,&temp_Q);
			SetDataRLSMatrix(*Q,N -> data[curor+1] -> i,N -> data[curor+1]->j,temp_Q+temp_N);
		}
		return OK;
	}
	exit(OVERFLOW);
}

Status SubRLSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix *Q){
	int curor;
	ElemType temp_N,temp_Q;
	if(M -> mu != N -> mu || M -> nu != N -> nu){
		(*Q) = NULL;
		return ERROR;
	}
//	printf("aaa\n");
	if(CopyRLSMatrix(M,Q)){
		for(curor = 0;curor < N -> tu ;curor++){
			GetDataRLSMatrix(N,N -> data[curor+1] -> i,N -> data[curor+1]->j,&temp_N);
			GetDataRLSMatrix(*Q,N -> data[curor+1] -> i,N -> data[curor+1]->j,&temp_Q);
			SetDataRLSMatrix(*Q,N -> data[curor+1] -> i,N -> data[curor+1]->j,temp_Q-temp_N);
		}
		return OK;
	}
	exit(OVERFLOW);
}

Status MultRLSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix *Q){
	int i,j,row,cols;
	ElemType temp_N,temp_M,temp_Q;
	if(M -> nu != N -> mu){
		(*Q) = NULL;
		return ERROR;
	}
	
	if(CreateRLSMatrix(Q,M -> mu,N -> nu)){
		for(row = 0;row<(*Q) -> mu;row++){
			for(cols = 0;cols <(*Q) -> nu;cols++){
				//求(*Q)[row][cols]的值
				GetDataRLSMatrix(*Q,row,cols,&temp_Q);
				for(i = 0;i < M ->nu;i++){
					GetDataRLSMatrix(M,row,i,&temp_M);
					if(temp_M == 0) continue;
					GetDataRLSMatrix(N,i,cols,&temp_N);
					if(temp_N == 0) continue;
					temp_Q += (temp_M * temp_N);
				}
				SetDataRLSMatrix(*Q,row,cols,temp_Q);
			}
		}
	}
	return OK;
}


Status TransposeRLSMatrix(RLSMatrix M,RLSMatrix *T){
	int curor;
	if(CreateRLSMatrix(T,M -> nu,M -> mu)){
		for(curor = 0;curor<M -> tu;curor++){
			SetDataRLSMatrix(*T,M->data[curor+1]->j,M -> data[curor+1]->i,M -> data[curor+1]->e);
		}
		return OK;
	}
	exit(OVERFLOW);
}


#endif
