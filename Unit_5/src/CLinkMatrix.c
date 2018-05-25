/*************************************************************************
	> File Name: CLinkMatrix.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Thu 24 May 2018 08:32:33 PM CST
 ************************************************************************/

#include "./CLinkMatrix.h"

Status CreateCLMatrix(CLMatrix *M,int mu,int nu){
	(*M) = (CLMatrix)malloc(sizeof(cLMatrix));
	if(!(*M)) exit(OVERFLOW);
	(*M) -> rhead = (CLink *)malloc(sizeof(CLink)*mu);
	(*M) -> chead = (CLink *)malloc(sizeof(CLink)*nu);
	if(!(*M)-> rhead || !(*M) -> chead) exit(OVERFLOW);
	(*M) -> mu = mu;
	(*M) -> nu = nu;
	(*M) -> tu = 0;

	return OK;

}

Status DestroyCLMatrix(CLMatrix *M){
	int i,j;
	CLink temp,p;
	if(!(*M)) return OK;
	for(i = 0;i<(*M)->mu;i++){
		p = (*M) -> rhead[i];
		while(!p){
			temp = p;
			p = p -> right;
			free(temp);
		}
	}

	free((*M)-> rhead);
	free((*M)-> chead);
	free(*M);
	(*M) = NULL;
	return OK;
}
Status SetCLMatrix(CLMatrix *M,ElemType **arr,int arr_mu,int arr_nu){
	int i,j;
	ElemType e;
	if(!CreateCLMatrix(M,arr_mu,arr_nu) || !arr) exit(OVERFLOW);
	for(i = 0;i<arr_mu;i++){
		for(j = 0;j<arr_nu;j++){
			e = arr[i][j];
			if(e == 0) continue;
			if(!SetDataCLMatrix(*M,i,j,e)) return ERROR;
		}
	}
	return OK;
}

Status SetRowData(CLMatrix M,CLink Node){
	CLink right,prior;
	int i,j;
	ElemType e;
	if(!M || !Node) return ERROR;
	i = Node -> i;
	j = Node -> j;
	e = Node -> e;

	//第i行设置j
	if(M -> rhead[i] == NULL){
		M -> rhead[i] = Node;
		Node -> right = NULL;
		(M ->tu)++;
		return OK;
	}
	for(right = M -> rhead[i],prior = NULL;right;prior = right,right = right -> right){
		if(right -> j == j){		//已经存在，更改e
			right -> e = e;
			return OK;
		}else if(right -> j > j){	
			if(prior == NULL){		//Node设为该行的头结点	
				Node -> right = right;
				M -> rhead[i] = Node;
				(M -> tu)++;
				return OK;
			}
			break;
		}
	}//for
	//prior指向最后一个节点,将Node插入prior后面
	Node -> right = prior -> right;
	prior -> right = Node;
	(M -> tu)++;
	return OK;
}

Status SetColsData(CLMatrix M,CLink Node){
	CLink down,prior;
	int i,j;
	ElemType e;
	if(!M || !Node) return ERROR;
	i = Node -> i;
	j = Node -> j;
	e = Node -> e;

	//第j列设置i
	if(M -> chead[j] == NULL){
		M -> chead[j] = Node;
		Node -> down = NULL;
		return OK;
	}
	for(down = M -> chead[j],prior = NULL;down;prior = down,down = down -> down){
		if(down -> i == i){		//已经存在，更改e
			down -> e = e;
			return OK;
		}else if(down -> i > i){
			if(prior == NULL){		//Node设为该列的头结点	
				Node -> down = down;
				M -> chead[j] = Node;
				return OK;
			}
			break;
		}
	}//for
	//Node插入prior后面
	Node -> down = prior -> down;
	prior -> down = Node;
	return OK;
}
Status DelRowData(CLMatrix M,int i,int j){
	CLink right,prior;
	if(!M) return ERROR;
	if(M -> rhead[i] == NULL) return OK;
	for(right=M -> rhead[i],prior=NULL;right;prior = right,right = right -> right){
		if(right -> j == j){
			if(prior == NULL){
				M -> rhead[i] = right -> right;
				return OK;
			}
			prior -> right = right -> right;
			return OK;
		}else if(right -> j > j) return OK;
	}
	return OK;
}

Status DelColsData(CLMatrix M,int i,int j){
	CLink down,prior;
	if(!M) return ERROR;
	if(M -> chead[j] == NULL) return OK;
	for(down=M -> chead[j],prior=NULL;down;prior = down,down = down -> down){
		if(down -> i == i){
			if(prior == NULL){
				M -> chead[j] -> down = down -> down;
				free(down);
				(M -> tu)--;
				return OK;
			}
			prior -> down = down -> down;
			free(down);
			(M -> tu)--;
			return OK;
		}else if(down -> i > i) return OK;
	}
	return OK;
}


Status SetDataCLMatrix(CLMatrix M,int i,int j,ElemType e){
	CLink Node;
	if(!M) return ERROR;

	if(e == 0){
		DelRowData(M,i,j);			//由行来决定tu是否--
		DelColsData(M,i,j);			//释放资源
		return OK;
	}
	Node = (CLink)malloc(sizeof(CLNode));
	if(!Node) exit(OVERFLOW);
	Node -> i = i;
	Node -> j = j;
	Node -> e = e;
	Node -> right = Node -> down = NULL;

	if(SetRowData(M,Node) &&		//由行来决定tu是否++
		SetColsData(M,Node))
		return OK;
	return ERROR;
}


Status GetDataCLMatrix(CLMatrix M,int i,int j,ElemType *e){
	CLink curor;
	if(!M) 	return ERROR;
	for(curor = M -> rhead[i];curor;curor = curor -> right){
		if(curor -> j == j){
			(*e) = curor -> e;
			return OK;
		}else if(curor -> j >j) break;
	}
	(*e) = 0;
	return OK;
}

void PrintCLMatrix(CLMatrix M){
	int curor;
	CLink ptr;
	if(!M){
		printf("该稀疏矩阵不存在!\n");
		return;
	}
	printf("稀疏矩阵的行数，列数：%d,%d\n",M -> mu,M -> nu);
	printf("稀疏矩阵的非零元个数：%d\n",M -> tu);
	printf("-------------------------------\n");
	for(curor = 0;curor < M -> mu;curor++){
		for(ptr = M -> rhead[curor];ptr;ptr = ptr -> right)
			printf("[%d,%d] = %d\n",ptr->i,ptr->j,ptr->e);
	}
	printf("-------------------------------\n");
	return;
}

Status CopyCLMatrix(CLMatrix M,CLMatrix *T){
	CLink right;
	int i;
	if(!M || !CreateCLMatrix(T,M -> mu,M -> nu)) return ERROR;
	for(i = 0;i<M ->mu;i++){
		for(right = M -> rhead[i];right;right = right -> right)
			if(!SetDataCLMatrix(*T,right -> i,right -> j,right -> e)) return ERROR;
	}
	return OK;
}
Status AddCLMatrix(CLMatrix M,CLMatrix N,CLMatrix *Q){
	int curor;
	CLink right;
	ElemType temp_M,temp_N;
	if(!M || !N || (M -> mu != N -> mu) || (M -> nu != N -> nu)) return ERROR;
	if(!CopyCLMatrix(M,Q)) return ERROR;
	for(curor = 0;curor < N -> mu;curor++){
		for(right = N -> rhead[curor];right;right = right -> right){
			if( !GetDataCLMatrix(N,right -> i,right ->j,&temp_N) ||
				!GetDataCLMatrix(M,right -> i,right ->j,&temp_M) ||
				!SetDataCLMatrix(*Q,right -> i,right ->j,temp_M+temp_N))
				return ERROR;
		}
	}
	return OK;
}


Status SubCLMatrix(CLMatrix M,CLMatrix N,CLMatrix *Q){
	int curor;
	CLink right;
	ElemType temp_M,temp_N;
	if(!M || !N || (M -> mu != N -> mu) || (M -> nu != N -> nu)) return ERROR;
	if(!CopyCLMatrix(M,Q)) return ERROR;
	for(curor = 0;curor < N -> mu;curor++){
		for(right = N -> rhead[curor];right;right = right -> right){
			if( !GetDataCLMatrix(N,right -> i,right ->j,&temp_N) ||
				!GetDataCLMatrix(M,right -> i,right ->j,&temp_M) ||
				!SetDataCLMatrix(*Q,right -> i,right ->j,temp_M-temp_N))
				return ERROR;
		}
	}
	return OK;
}

Status MultCLMatrix(CLMatrix M,CLMatrix N,CLMatrix *Q){
	int row,cols,i;
	CLink right;
	ElemType temp_Q,temp_N,temp_M;
	if(!M || !N || (M -> nu != N -> mu)) return ERROR;
	if(!CreateCLMatrix(Q,M -> mu,N -> nu)) return ERROR;
	for(row = 0;row<(*Q) -> mu;row++){
		for(cols = 0;cols <(*Q) -> nu;cols++){
			//求Q[row][cols]
			temp_Q = 0;
			for(i = 0;i<M -> nu;i++){
				GetDataCLMatrix(M,row,i,&temp_M);
				if(temp_M == 0) continue;
				GetDataCLMatrix(N,i,cols,&temp_N);
				if(temp_N == 0) continue;
				temp_Q +=(temp_M * temp_N);
			}
			if(!SetDataCLMatrix(*Q,row,cols,temp_Q)) return ERROR;
		}
	}
	return OK;
}

Status TransposeCLMatrix(CLMatrix M,CLMatrix *T){
	int i;
	CLink right;
	ElemType temp;
	if(!CreateCLMatrix(T,M -> nu,M -> mu)) exit(OVERFLOW);
	for(i = 0;i<M -> mu;i++){
		for(right = M -> rhead[i];right;right = right -> right){
			GetDataCLMatrix(M,i,right -> j,&temp);
			SetDataCLMatrix(*T,right -> j,i,temp);
		}
	}
	return OK;
}

