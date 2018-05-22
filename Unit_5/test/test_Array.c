/*************************************************************************
	> File Name: test_Array.c
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Mon 21 May 2018 09:56:07 PM CST
 ************************************************************************/

#include "../src/Array.c"

int main(int argc,char **argv){
	Array A;
	int DIM = 3;
	int dim1 = 3,dim2=4,dim3=5;
	int i,j,k;
	ElemType num;

	printf("----------以三维数组为例------------\n\n\n");

	printf("\n----------测试InitArray()------------\n");
	if(InitArray(&A,DIM,dim1,dim2,dim3)){
		PrintArray(A);
	}
	
	printf("\n----------测试Assign()------------\n");
	for(i=0;i<dim1;i++){
		for(j = 0;j<dim2;j++)
			for(k = 0;k<dim3;k++)
				if(!Assign(A,num++,i,j,k)) printf("%d插入失败，位置为：%d,%d,%d\n",num-1,i,j,k);
	}
	PrintArray(A);

	printf("\n----------测试Value()------------\n");
	for(i=0;i<dim1;i++){
		for(j = 0;j<dim2;j++){
			for(k = 0;k<dim3;k++)
				if(Value(A,&num,i,j,k)) printf("(%d,%d,%d)=%d ",i,j,k,num);
		printf("\n");
		}
	}

	
	printf("\n----------测试DestroyArray()------------\n");
	if(DestroyArray(&A)){
		PrintArray(A);
	}
	return 0;
}
