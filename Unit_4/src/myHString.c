#ifndef MYHSTRING_C
#define MYHSTRING_C

#include "myHString.h"

Status ensureCapacity(HString str,int capacity){	//私有方法，不再头文件中声明
	int newCapa;
	if(!str) exit(OVERFLOW);
	if(str -> capacity < capacity){
		newCapa = str -> capacity + HSTRING_INCREASE > capacity? str -> capacity + HSTRING_INCREASE: capacity;
		str -> Base = (char *)realloc(str -> Base,newCapa);
		if(!(str->Base)) return ERROR;
		str -> capacity = newCapa;
	}
	return OK;
}


Status InitStr(HString *str){
	(*str) = (hString *)malloc(sizeof(hString));
	if((*str)){
		(*str) -> Base = (char *)malloc(sizeof(char)*HSTRING_INIT_CAPACITY);
		if(!((*str) -> Base))	return ERROR;
		(*str) -> size = 0;
		(*str) -> capacity = HSTRING_INIT_CAPACITY;
		return OK;
	}
	return ERROR;
}

Status StrAssign(HString *str,char *chars){	//注意溢出问题
	int i = 0,length;
	if(InitStr(str)){
		for(length=0;chars[length]!='\0';length++);
		ensureCapacity(*str,length);
		while(chars[i]!='\0'){
			(*str) -> Base[i] = chars[i];
			((*str) -> size)++;
			i++;
		}
		return OK;
	}
	return ERROR;
}

Status StrCopy(HString *str1,HString str2){
	int i = 0;
	if(InitStr(str1)){
		ensureCapacity(*str1,str2 -> size);
		for(;i< (str2 -> size);i++) (*str1) -> Base[i] = str2 -> Base[i];
		(*str1) -> size = str2 -> size;
		return OK;
	}
	return ERROR;
}

Bool StrEmpty(HString str1){
	if(!str1) exit(OVERFLOW);
	return str1 -> size == 0?TRUE:FALSE;
}

int StrCompare(HString str1,HString str2){
	int i,j;
	if(!str1 || !str2) exit(OVERFLOW);
	i = 0;
	while(i<(str1 -> size)&& i<(str2 -> size)){
		if(str1 -> Base[i] != str2 -> Base[i])	return str1 -> Base[i] - str2 -> Base[i];
		i++;
	}
	return str1 -> size - str2 -> size;
}

int StrLength(HString str){
	if(!str) exit(OVERFLOW);
	return str -> size;
}

Status ClearString(HString str){
	if(!str) exit(OVERFLOW);
	str -> size = 0;
	return OK;
}

Status Concat(HString *T,HString S1,HString S2){	//注意考虑溢出的情况
	int i,j;
	if(!S1||!S2)	exit(OVERFLOW);
	if(InitStr(T)){
		if(!ensureCapacity(*T,S1 -> size + S2 -> size)) return ERROR;
		j = i = 0;
		while(i < S1->size){
			(*T) -> Base[i] = S1 -> Base[i];
			i++;
		}
		while(j < S2->size){
			(*T) -> Base[i] = S2 -> Base[j];
			j++;
			i++;
		}
		(*T) -> size = i;
		return OK;
	}
	return ERROR;
}

Status SubString(HString *sub,HString S,int pos,int len){ //范围为[pos,pos+len),长度为len
	int i;
	if(!S)	exit(OVERFLOW);
	if(pos < 1 || pos > (S -> size)+1 || len < 0){
		(*sub) = NULL;
		return ERROR;
	}
	/**
	 * len + pos > S -> size ? len = S -> size - pos : ; 		??不对
	 * 三目运算符： 表达式1？表达式2：表达式3
	 * 	表达式为赋值语句右边(言外之意就是表达式不能有等于号)
	 */
	len = len > S -> size + 1 - pos ? S->size + 1 - pos : len;

	if(InitStr(sub)){
		ensureCapacity(*sub,len);
		for(i = 0;i<len;i++){
			(*sub) -> Base[i] = S -> Base[i+pos-1];
		}
		(*sub) -> size = len;
		return OK;
	}
	return ERROR;
}
#ifndef INDEX_C
#define INDEX_C
int Index(HString S,HString T,int pos){
	int i;
	HString temp;
	if(!S||!T) exit(OVERFLOW);
	if(pos+(T -> size) > S -> size + 1) return -1;
	for(i = pos; i+T->size <= S -> size + 1;i++){
		SubString(&temp,S,i,T->size);
		if(StrCompare(temp,T) == 0) return i;
	}
	//记得释放掉申请的临时内存
	DestroyString(&temp);
	return -1;
}
#endif
Status Replace(HString *S,HString T,HString V){
	int i = 0;
	HString begin,end;
	if(!(*S)||!T||!V) exit(OVERFLOW);
	if(T -> size > (*S) -> size) return ERROR;
	while(TRUE){
		i = Index(*S,T,i+1);
		if(i == -1) break;
		SubString(&begin,*S,1,i-1);	//[1,i)
		SubString(&end,*S,i+T->size,StrLength(*S)-i-T->size+1);	//[i+T->size,StrLength(S)+1)
		Concat(S,begin,V);
		Concat(S,*S,end);
		//PrintString(*S);
	}
	//记得释放掉申请的临时内存
	DestroyString(&begin);
	DestroyString(&end);
	return OK;
}

Status StrInsert(HString *S,int pos,HString T){
	int i;
	HString begin,end;
	if(!S||!T)	exit(OVERFLOW);
	if(pos < 1) return ERROR;
	if(pos > (*S) -> size+1) pos = (*S) -> size+1;
	
	SubString(&begin,*S,1,pos-1);	//[1,pos)
	SubString(&end,*S,pos,StrLength(*S)-pos+1);	//[pos,StrLength(S)+1)
	Concat(S,begin,T);
	Concat(S,*S,end);

	//记得释放掉申请的临时内存
	DestroyString(&begin);
	DestroyString(&end);
	return OK;
}

Status StrDelete(HString *S,int pos,int len){
	int i,j;
	HString temp,begin,end;
	if(!S)	exit(OVERFLOW);
	if(pos < 1 || len < 0 || pos > (*S) -> size) return ERROR;
	
	// 同上？len > S -> size - pos ? len = S -> size - pos :;
	len = len > (*S)->size - pos ? (*S) -> size - pos:len;
	
	SubString(&begin,*S,1,pos-1);	//[1,pos)
	SubString(&end,*S,pos+len,StrLength(*S)-pos-len+1);	//[pos+len,StrLength(S)+1)
	Concat(S,begin,end);

	//记得释放掉申请的临时内存
	DestroyString(&begin);
	DestroyString(&end);
	return OK;
}

Status DestroyString(HString *S){
	if(!(*S)) return OK;
	free((*S) -> Base);
	free(*S);
	(*S) = NULL;
	return OK;
}
void PrintString(HString S){
	int i=0;
	if(!S){
		printf("\n字符串不存在!\n");
		return;
	}
	printf("字符串的长度为：%d，字符串的容量为:%d\n",S->size,S->capacity);
	while(i < S -> size){
		printf("%c",S->Base[i]);
		i++;
	}
	printf("\n");
}
#endif
