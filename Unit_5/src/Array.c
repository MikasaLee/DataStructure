/*************************************************************************
	> File Name: Array.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 21 May 2018 07:55:08 PM CST
 ************************************************************************/
/**
 * 数组的顺序存储实现
 */
#ifndef ARRAY_C
#define ARRAY_C
#include "./Array.h"


Status InitArray(Array *A,int dim, ...){
	va_list ptr;
	int i,temp,sum;
	if(dim < 1 || dim > MAX_ARRAY_DIM) return ERROR;
	
	(*A) = (Array)malloc(sizeof(array));
	if(!(*A)) exit(OVERFLOW);
	(*A) -> dim = dim;		
	(*A) -> bounds = (int *)malloc(sizeof(int)*dim);
	if(!((*A) -> bounds)) exit(OVERFLOW);
	(*A) -> constants = (int *)malloc(sizeof(int)*dim);
	if(!((*A) -> constants)) exit(OVERFLOW);

	va_start(ptr,dim);	//从dim后面开始读取参数
	for(i = 0,temp = 0;i< dim;i++){
		temp = va_arg(ptr,int);
		if(temp < 0 ) return OVERFLOW;
		(*A) -> bounds[i] = temp;
	}
	va_end(ptr);		//结束读取

	for(i = dim-1,sum = 1;i>=0;i--){
		(*A) -> constants[i] = sum;
		sum *=	(*A) -> bounds[i];
	}

	(*A) -> base = (ElemType *)malloc(sizeof(ElemType)*sum);
	if(!((*A) -> base)) exit(OVERFLOW);
	
	return OK;
}

Status DestroyArray(Array *A){
	if(!(*A)) return OK;
	
	free((*A) -> base);
	free((*A) -> bounds);
	free((*A) -> constants);
	(*A) = NULL;
	return OK;
}


Status Value(Array A,ElemType *e,...){	//注意所有向量都是基于下标值的，所以请注意算法,实在想不通就动笔画一画
	va_list ap;					//array pointer
	int curor,temp = 0,i;
	if(!A) return ERROR;
	va_start(ap,e);
	if(Locate(A,ap,&curor)){
		va_end(ap);
		(*e) = A -> base[curor];
		return OK;
	}
	va_end(ap);
	return ERROR;
}

Status Assign(Array A,ElemType e,...){  
	va_list ap;
	int curor = 0,temp = 0,i;
	if(!A) return ERROR;
	va_start(ap,e);
	if(Locate(A,ap,&curor)){
		va_end(ap);
		A -> base[curor] = e;
		return OK;
	}
	va_end(ap);
	return ERROR;
}

Status Locate(Array A,va_list ap,int *off){
	int i,temp,curor;
	
	if(!A || !ap) exit(OVERFLOW);
	for(i = 0,curor = 0;i<A ->dim;i++){
		temp = va_arg(ap,int);
		if(temp < 0 || temp > A -> bounds[i] - 1){
			(*off) = -1;
			return ERROR;
		}
		curor += temp*(A -> constants[i]);
	}
	(*off) = curor;
	return OK;
}

void PrintArray(Array A){
	int i,j,sum;
	ElemType data;
	if(!A){
		printf("数组不存在!\n");
		return ;
	}
	printf("数组的基址:%d\n数组的维数:%d\n",A -> base,A -> dim);
	printf("数组的维界地址:");
	for(i = 0;i< A -> dim;i++){
		printf("[%d]",A -> bounds[i]);
	}
	printf("\n");
	printf("数组的映像函数常量基址:{ ");
	for(i = 0;i< A -> dim;i++){
		printf("%d ",A -> constants[i]);
	}
	printf("}\n");

	sum = A -> constants[0] * A -> bounds[0];
	printf("数组元素的内容:");
	for(i = 0;i<sum;i++){
		printf("%d ",A -> base[i]);
	}
	printf("\n");
	return;
}
#endif
