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
    for(i = 0;chars[i] != '\0';i++){
        if((*str) -> size == 0) curor -> data[0] = chars[i];
        if((*str) -> size % NODE_LENGTH == 0){ 
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
    (*str) = (LinkString)malloc(sizeof(linkString));
    if(!(*str)) exit(OVERFLOW);
    (*str) -> head = (LinkNode)malloc(sizeof(linkNode));
    if(!(*str -> head)) exit(OVERFLOW);
    (*str) -> size = 0;
    (*str) -> head -> next = NULL;

    curor = (*str) -> head;
    curor_s = s -> head;
    for(i = 0;i<StrLength(s);i++){
        if((*str) -> size == 0) curor -> data[0] = curor_s -> data[0];
        if((*str) -> size % NODE_LENGTH == 0){ 
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
    while(i<StrLength(str1) && i<StrLength(str2)){
        if(i % NODE_LENGTH == 0){
            curor_str1 = curor_str1 -> next;
            curor_str2 = curor_str2 -> next;
        }
        if(curor_str1 -> data[i] !=curor_str2 -> data[i])   return curor_str1 -> data[i] - curor_str2 -> data[i];
        i++;
    }

    if(i == StrLength(str1) && i == StrLength(str2))    return 0;
    else if(i == StrLength(str2)) return 1;
    else return -1;
}

int StrLength(LinkString str1){
    return str1 -> size;
}

LinkString Concat(LinkString str1,LinkString str2){
    LinkString result;
    int i;
    LinkNode curor;
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
    }
    return result;
}


#endif
