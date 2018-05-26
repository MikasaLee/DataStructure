#ifndef MYSSTRING_C
#define MYSSTRING_C
#include "mySString.h"

Status StrAssign(SString str,char* chars){
	int i;
	if(chars){
		for(i = 0;chars[i]!='\0' && i<MAXSTRLEN;i++){
			str[i+1]=chars[i];
		}
		str[0] = i;
		return OK;
	}
	str[0] = 0;
	return ERROR;
}

Status StrCopy(SString str,SString s){
	int i;
	if(s[0] == 0){
		str[0] = 0;
		return ERROR;
	}
	for(i = 0;i<=s[0];i++){
		str[i] = s[i];
	}
	return OK;
}

Bool StrEmpty(SString str){
	return str[0] == 0?TRUE:FALSE;
}

int StrCompare(SString str1,SString str2){
	int i=1;
	while(i <= str1[0] && i<= str2[0]){
		if(str1[i] != str2[i])	return str1[i] - str2[i];
		i++;
	}
	return str1[0] - str2[0];   //2018.4.26 Update: return str1[i] - str2[i]   change by return str1[0] - str2[0]; 
}

int StrLength(SString str){
	return str[0];
}

Status ClearString(SString str){
	str[0] = 0;
	return OK;
}

Status Concat(SString T,SString S1,SString S2){				//2018.5.26：Concat和SubString操作应该建立一个临时字符串，而不能直接对T/sub进行操作，如果S2/S与T/sub指向的是同一个字符串的话，那么直接操作T/sub就会出错
	int i;
	SString temp;
	for(i=0;i<=S1[0];i++)	temp[i] = S1[i];
	for(i=1;i<=S2[0]&&(temp[0]+i <= MAXSTRLEN);i++)	temp[i+temp[0]] = S2[i];
	temp[0] = temp[0] + i -1;
	StrCopy(T,temp);	
	return OK;
}

Status SubString(SString sub,SString S,int pos,int len){
	int i;
	int n =S[0];
	SString temp;
	if(pos < 1 || pos > S[0] || len < 0){
		sub[0] = 0;	
		return ERROR;
	}
	temp[0] = 0;
	for(i=0;i<len&&(pos+i<=n);i++){
		temp[i+1] = S[i+pos];
		temp[0]++;
	}
	StrCopy(sub,temp);	
	return OK;
}

int Index(SString S,SString T,int pos){
	int i,j;
	SString temp;
	if(pos > MAXSTRLEN) return -1;
	i = pos;
	while(i+T[0]-1 <= S[0]){
		SubString(temp,S,i,T[0]);
		if(StrCompare(temp,T) == 0)	return i;
		i++;
	}
	return -1;
}

Status Replace(SString S,SString T,SString V){
	int i,j;
	SString temp,begin,end;
	i = 1;
	while((i+T[0]-1) <= S[0]){
		SubString(temp,S,i,T[0]);
		if((j=StrCompare(temp,T)) == 0){
			SubString(begin,S,1,i-1);       //[1,i)
			SubString(end,S,i+T[0],S[0]-i-T[0]+1);   //[i+T[0],S[0]+1)
			Concat(S,begin,V);
			Concat(S,S,end);
		}
		i++;
	}
	return OK;
}
Status StrInsert(SString S,int pos,SString T){
	SString begin,end;
	if(pos < 1||pos > S[0]+1) return ERROR;
	SubString(begin,S,1,pos);		//[1,1+pos)
	SubString(end,S,pos+1,S[0]);	//[pos+1,S[0]-pos)
	Concat(S,begin,T);
	Concat(S,S,end);
	return OK;
}

Status StrDelete(SString S,int pos,int len){
	SString begin,end;
	if(pos < 1||pos+len > S[0]+1 || len < 0) return ERROR;
	SubString(begin,S,1,pos-1);
	SubString(end,S,pos+len,S[0]);
	Concat(S,begin,end);
	return OK;
}

Status DestroyString(SString S){
	if(S[0] == 0) return OK;
	S[0] = 0;
	return OK;
}
void PrintString(SString S){
	int i;
	i = 1;
	printf("字符串的长度为：%d\n",StrLength(S));
	while(i <= S[0]){
		printf("%c",S[i]);
		i++;
	}
	printf("\n");
}
#endif
