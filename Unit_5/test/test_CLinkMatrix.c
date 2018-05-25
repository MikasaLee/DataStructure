#include "../src/CLinkMatrix.c"

int main(int argc,char **argv){
	CLMatrix M,T,N;
	int row = 5,cols=5,i;

	ElemType temp;
	ElemType **arr = (ElemType **)malloc(sizeof(ElemType *)*row);
	for(i = 0;i<row;i++){
		arr[i] = (ElemType *)malloc(sizeof(ElemType)*cols);
	}
	arr[0][1] = 1;
	arr[0][3] = 5;
	arr[1][2] = -3;
	arr[1][4] = 2;
	arr[2][0] = 2;
	arr[2][1] = 3;
	arr[2][2] = 4;
	arr[3][3] = 2;
	arr[4][0] = 3;
	arr[4][1] = -1;

	
	ElemType **arr1 = (ElemType **)malloc(sizeof(ElemType *)*row);
	for(i = 0;i<row;i++){
		arr1[i] = (ElemType *)malloc(sizeof(ElemType)*cols);
	}
	arr1[0][0] = -3;
	arr1[0][2] = 2;
	arr1[1][3] = -1;
	arr1[2][1] = 4;
	arr1[3][0] = 6;
	arr1[3][4] = 5;
	arr1[4][0] = 3;
	arr1[4][3] = 2;

	printf("-------------测试SetCLMatrix(),其中包含了CreateCLMatrix(),SetDataCLMatrix()的测试-------\n");
	if(SetCLMatrix(&M,arr,row,cols) && SetCLMatrix(&N,arr1,row,cols)){
		PrintCLMatrix(M);
		PrintCLMatrix(N);
	}
	printf("-----测试GetCLMatrix()--------\n");
	GetDataCLMatrix(M,4,1,&temp);
	printf("[4][1]=%d\n",temp);

	printf("-----测试CopyCLMatrix()--------\n");
	CopyCLMatrix(M,&T);
	PrintCLMatrix(T);
	GetDataCLMatrix(T,4,0,&temp);
	printf("[4][0]=%d\n",temp);
	
	printf("-----测试AddCLMatrix()--------\n");
	PrintCLMatrix(M);
	PrintCLMatrix(N);
	if(AddCLMatrix(M,N,&T))
		PrintCLMatrix(T);
	printf("-----测试SubCLMatrix()--------\n");
	PrintCLMatrix(M);
	PrintCLMatrix(N);
	if(SubCLMatrix(M,N,&T))
		PrintCLMatrix(T);
	printf("-----测试MultCLMatrix()--------\n");
	PrintCLMatrix(M);
	PrintCLMatrix(N);
	if(MultCLMatrix(M,N,&T))
		PrintCLMatrix(T);
	
	printf("-----测试TransposeCLMatrix()--------\n");
	PrintCLMatrix(M);
	PrintCLMatrix(N);
	if(TransposeCLMatrix(M,&T))
		PrintCLMatrix(T);
	
	
	return 0;
}
