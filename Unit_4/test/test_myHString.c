
#include "../src/myHString.c"

int main(int argc,char **args){
	int i,j;
	HString str1,str2;
	char *chars1,*chars2;
	printf("\n--------------测试InitStr(HString *str)-------------------\n");
	if(InitStr(&str1) && InitStr(&str2)){
		PrintString(str1);
		PrintString(str2);
	}

	printf("\n--------------测试StrAssign(HString *str,char* chars)-------------------\n");
	chars1= "asdfasfasfdsadfasdfasdfsafdasfd";
	chars2="ergcxvqfwq!@#$%^&((*^%%$##@!~$%&:{>:>::>>:<:>er";
	if(StrAssign(&str1,chars1) && StrAssign(&str2,chars2)){
		PrintString(str1);
		PrintString(str2);
	}

	printf("\n--------------测试StrCopy(HString *str,HString s)-------------------\n");
	if(StrCopy(&str1,str2)){
		PrintString(str1);
		PrintString(str2);
	}

	printf("\n--------------测试StrEmpty(HString str)和ClearString(HString str)-------------------\n");
	if(!StrEmpty(str1))	ClearString(str1);
	if(StrEmpty(str1))	PrintString(str1);

	printf("\n--------------测试StrCompare(HString str1,HString str2);-------------------\n");
	chars1="aa";
	chars2="aaa";
	if(StrAssign(&str1,chars1) && StrAssign(&str2,chars2)){
		if(StrCompare(str1,str2) > 0){
			printf("%s > %s\n",chars1,chars2);
		}else if(StrCompare(str1,str2) == 0){
			printf("%s = %s\n",chars1,chars2);
		}else
			printf("%s < %s\n",chars1,chars2);
	}

	printf("\n--------------测试Concat(HString *T,HString S1,HString S2)-------------------\n");
	chars1="b";
	chars2="a";
	if(StrAssign(&str1,chars1) && StrAssign(&str2,chars2)){
		PrintString(str1);
		PrintString(str2);

		Concat(&str1,str2,str1);
		
		PrintString(str1);
		PrintString(str2);
	}

	printf("\n--------------测试SubString(HString *sub,HString S,int pos,int len)-------------------\n");
	chars1="asdfasfdsdfsdfadf";
	chars2="xcvxzcvsdgffdgdfg";
	if(StrAssign(&str1,chars1) && StrAssign(&str2,chars2)){
		PrintString(str1);
		PrintString(str2);

		SubString(&str1,str2,9,10);
		
		PrintString(str1);
		PrintString(str2);
	}

	printf("\n--------------测试Index(HString S,HString T,int pos);------------------\n");
	chars1="asdfasfdsdfsdfadf";
	chars2="ade";
	if(StrAssign(&str1,chars1) && StrAssign(&str2,chars2)){
		PrintString(str1);
		PrintString(str2);
		printf("%s在%s中第一次出现的位置为：%d\n",chars2,chars1,Index(str1,str2,2));
	}

	printf("\n--------------测试Replace(HString S,HString T,HString V)------------------\n");
	if(StrAssign(&str1,chars1) && StrAssign(&str2,chars2)){
		PrintString(str1);
		PrintString(str2);
		Replace(&str2,str2,str1);
		PrintString(str1);
		PrintString(str2);
	}

	printf("\n--------------测试StrInsert(HString S,int pos,HString T)------------------\n");
	PrintString(str1);
	PrintString(str2);
	StrInsert(&str2,2,str1);
	PrintString(str1);
	PrintString(str2);

	printf("\n--------------测试StrDelete(HString *S,int pos,int len);------------------\n");
	PrintString(str2);
	StrDelete(&str2,1,23);
	PrintString(str2);

	printf("\n--------------测试DestroyString(HString *S)------------------\n");
	PrintString(str1);
	PrintString(str2);
	DestroyString(&str1); 
	DestroyString(&str2); 
	PrintString(str1);
	PrintString(str2);

	return 0;
}
