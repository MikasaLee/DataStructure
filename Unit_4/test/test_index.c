
#include "../src/index.c"

int main(int argc,char **args){
	char* chars1="aceacceaaaaaacccceeeeeacceaccdacceacdacceacccaccefaccc";
	char* chars2="acceaccc";
	HString str1,str2;
	printf("\n--------------测试Index(HString S,HString T,int pos);------------------\n");
	if(StrAssign(&str1,chars1) && StrAssign(&str2,chars2)){
		PrintString(str1);
		PrintString(str2);
		printf("%s在%s中第一次出现的位置为：%d\n",chars2,chars1,Index(str1,str2,1));
	}
	DestroyString(&str1); 
	DestroyString(&str2); 

	return 0;
}
