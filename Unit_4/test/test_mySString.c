
#include "../src/mySString.c"

int main(int argc,char **args){
	int i,j;
	char *chars1="abcdefghijklmnopqrstuvwxyz",*chars2,*chars3;
	SString str1,str2,str3;
	printf("\n---------测试StrAssign(SString str,char* chars)函数------------\n");
	StrAssign(str1,chars1);
	PrintString(str1);

	printf("\n---------测试StrCopy(SString str,SString s)函数------------\n");
	StrAssign(str1,"abcde");
	StrCopy(str2,str1);
	PrintString(str1);

	printf("\n---------测试StrEmpty(SString str)和ClearString(SString str)函数------------\n");
	ClearString(str1);
	if(!StrEmpty(str1))	PrintString(str1);
	else printf("str1为空\n");
	PrintString(str1);

	printf("\n---------测试StrCompare(SString str1,SString str2)函数------------\n");
	chars1 = "a";
	StrAssign(str1,chars1);
	chars2 = "a";
	StrAssign(str2,chars2);
	/**
	switch(StrCompare(str1,str2)){
		case 1 : printf("%s > %s\n",chars1,chars2);
			 break;
		case -1 : printf("%s < %s\n",chars1,chars2);
			 break;
		case 0 : printf("%s == %s\n",chars1,chars2);
	}
	**/
	if(StrCompare(str1,str2) > 0){
		printf("%s > %s\n",chars1,chars2);
	}else if(StrCompare(str1,str2) == 0){
		printf("%s = %s\n",chars1,chars2);
	}else printf("%s < %s\n",chars1,chars2);

	printf("\n---------测试Concat(SString T,SString S1,SString S2)函数------------\n");
	chars1 = "abcde";
	StrAssign(str1,chars1);
	chars2 = "ABCDE";
	StrAssign(str2,chars2);
	PrintString(str1);
	PrintString(str2);
	Concat(str1,str1,str2);
	PrintString(str1);
	PrintString(str2);

	printf("\n---------测试SubString(SString sub,SString S,int pos,int len)函数------------\n");
	PrintString(str1);
	PrintString(str2);
	SubString(str2,str1,1,10);
	PrintString(str1);
	PrintString(str2);
	
	printf("\n---------测试Index(SString S,SString T,int pos)函数------------\n");
	PrintString(str1);
	printf("str2在str1中出现的位置：%d\n",Index(str1,str2,2));
	
	printf("\n---------测试Replace(SString S,SString T,SString V)函数------------\n");
	chars1 = "dsfasdfasfdasdfsa ";
	StrAssign(str1,chars1);
	chars2 = "a";
	StrAssign(str2,chars2);
	chars3 = "A";
	StrAssign(str3,chars3);

	PrintString(str1);
	printf("\n\n");
	Replace(str1,str2,str3);
	PrintString(str1);
	
	printf("\n---------测试StrInsert(SString S,int pos,SString T);函数------------\n");
	chars1 = "dsfasdfasfdasdfsa ";
	StrAssign(str1,chars1);
	chars2 = "c";
	StrAssign(str2,chars2);
	PrintString(str1);
	printf("\n\n");
	StrInsert(str2,2,str1);
	PrintString(str2);

	printf("\n---------测试StrDelete(SString S,int pos,int len);函数------------\n");
	chars1 = "dsfasdfasfdasdfsa ";
	StrAssign(str1,chars1);
	chars2 = "c";
	StrAssign(str2,chars2);
	PrintString(str1);
	printf("\n\n");
	StrDelete(str1,3,3);
	PrintString(str1);

	printf("\n---------测试DestroyString(SString S)函数------------\n");
	DestroyString(str1);
	DestroyString(str2);
	PrintString(str1);
	PrintString(str2);

	return 0;
}
