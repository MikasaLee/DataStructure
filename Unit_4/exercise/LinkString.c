/**
 * 4.21 假设以结点大小为1（且附设头结点）的链表结构表示串。试编写实现下列六种串的基本操作StrAssign，StrCopy，StrCompare，StrLength，Concat和SubString的函数。
 * //注：头文件定义在LinkString.h中
 */

#ifndef LINKSTRING_C
#define LINKSTRING_C

#include "LinkString.h"

Status StrAssign(LinkString *str,char *chars){
    int i,j;
    char ch;
    LinkNode curor;
    (*str) = (LinkString)malloc(sizeof(linkString));
    if(!(*str)) exit(OVERFLOW);
    (*str) -> size = 0;
    (*str) -> head = (LinkNode)malloc(sizeof(linkNode));
    if(!((*str) -> head)) exit(OVERFLOW);
    (*str) -> head -> next = NULL;

    curor = (*str) -> head;
    if(chars == NULL)   return OK;
    for(i = 0;chars[i] != '\0';i++){
        if((i != 0) &&(*str) -> size % NODE_LENGTH == 0){ 
            if((curor -> next = (LinkNode)malloc(sizeof(linkNode))) == NULL) exit(OVERFLOW);
            curor = curor -> next;
            curor -> next = NULL;
        }
        curor -> data[((*str) -> size)%NODE_LENGTH]=chars[i];
        ((*str) -> size)++;
    }

    return OK;
}

Status StrCopy(LinkString *str,LinkString s){
    int i;
    LinkNode curor,curor_s;
    /** StrAssign支持第二个参数的值为NULL
    (*str) = (LinkString)malloc(sizeof(linkString));
    if(!(*str)) exit(OVERFLOW);
    (*str) -> head = (LinkNode)malloc(sizeof(linkNode));
    if(!((*str) -> head)) exit(OVERFLOW);
    (*str) -> size = 0;
    (*str) -> head -> next = NULL;
    **/
    StrAssign(str,NULL);

    curor = (*str) -> head;
    curor_s = s -> head;
    for(i = 0;i<StrLength(s);i++){
        if((i != 0) &&(*str) -> size % NODE_LENGTH == 0){ 
            if((curor -> next = (LinkNode)malloc(sizeof(linkNode))) == NULL) exit(OVERFLOW);
            curor = curor -> next;
            curor -> next = NULL;
            curor_s = curor_s -> next;
        }
        curor -> data[((*str) -> size)%NODE_LENGTH]=curor_s -> data[(s -> size)%NODE_LENGTH];
        ((*str) -> size)++;
    }
    return OK;
}

int StrCompare(LinkString str1,LinkString str2){
    int i = 0;
    LinkNode curor_str1,curor_str2;
    if(str1 == NULL || str2 == NULL)    return StrLength(str1) - StrLength(str2);   //StrLength(string) return -1 if String is NULL;
    curor_str1 = str1 -> head;
    curor_str2 = str2 -> head;

    while(i<StrLength(str1) && i<StrLength(str2)){
        if((i != 0) &&((i % NODE_LENGTH) == 0)){
            curor_str1 = curor_str1 -> next;
            curor_str2 = curor_str2 -> next;
        }
        if((curor_str1 -> data[i%NODE_LENGTH]) != (curor_str2 -> data[i%NODE_LENGTH]))   return (curor_str1 -> data[i%NODE_LENGTH]) - (curor_str2 -> data[i%NODE_LENGTH]);
        i++;
    }

    /**
    if((i == StrLength(str1)) && (i == StrLength(str2)))    return 0;
    else if(i == StrLength(str2)) return 1;
    else return -1;
    **/
    return StrLength(str1) - StrLength(str2);
}

int StrLength(LinkString str1){
    if(str1 == NULL) return -1;
    return str1 -> size;
}

LinkString Concat(LinkString str1,LinkString str2){
    LinkString result;
    int i;
    LinkNode curor,curor_str2;

    if(!StrCopy(&result,str1))   return NULL;
    curor = result -> head;
    curor_str2 = str2 -> head;
    while(curor -> next!=NULL) curor = curor -> next;       //将游标移到最后一个节点。
    for(i = 0;i<StrLength(str2);i++){
        if(StrLength(str1) % NODE_LENGTH == 0){
            curor -> next = (LinkNode)malloc(sizeof(linkNode));
            if(!(curor -> next)) exit(OVERFLOW);
            curor = curor -> next;
            curor -> next = NULL;
        }
        if((i != 0) && ((i% NODE_LENGTH) == 0)){
            curor_str2 = curor_str2 -> next;
        }
        curor -> data[StrLength(result)%NODE_LENGTH] = curor_str2 ->data[i%NODE_LENGTH];
        (result -> size)++;
    }
    return result;
}

LinkString SubString(LinkString s,int pos,int len){     //return s[pos,pos+len),pos 从1开始
    LinkString result;
    int i,j;
    LinkNode curor_s,curor_result;

    if(!StrAssign(&result,NULL) || pos < 1 || pos+len > StrLength(s)+1) return NULL;
    
    pos = pos -1;       //偷个小懒。。。原来的pos是从0开始的
    curor_s = s -> head;
    for(i = 0;i<(pos/NODE_LENGTH);i++)    curor_s = curor_s -> next;
    curor_result = result -> head;
    for(j=0,i=(pos%NODE_LENGTH);j<len;j++,i++){
        if((j != 0) && StrLength(result) % NODE_LENGTH == 0){
            curor_result -> next = (LinkNode)malloc(sizeof(linkNode));
            if(!(curor_result -> next)) exit(OVERFLOW);
            curor_result = curor_result -> next;
            curor_result -> next = NULL;
        }
        if((i != 0) && (i%NODE_LENGTH == 0)) curor_s = curor_s -> next;
        curor_result -> data[j%NODE_LENGTH] = curor_s -> data[i % NODE_LENGTH];
        (result -> size)++;
    }
    return result;
}

void PrintString(LinkString str){
    int i,len;
    LinkNode curor;

    curor = str -> head;
    len = StrLength(str);
    printf("String Length is :%d\n",len);
    for(i = 0;i<len;i++){
        if((i !=0) && (i%NODE_LENGTH == 0)){
            curor = curor -> next;
        }
       // printf("\n");
        printf("%c",curor -> data[i%NODE_LENGTH]);
    }
    printf("\n");
}
#endif
