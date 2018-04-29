/**
 * 4.28 假设以结点大小为1（带头结点）的链表结构表示串，则在利用next函数值进行串匹配时，在每个结点中需设三个域：数据域chdata、指针域succ和指针域next。其中chdata域存放一个字符；succ域存放指向同一链表中后继结点的指针；next域在主串中存放指向同一链表中前驱结点的指针；在模式串中，存放指向当该结点的字符与主串中的字符不等时，在模式串中下一个应进行比较的字符结点（即与该字符的next函数值相对应的字符结点）的指针，若该节点字符的next函数值为0，则其next域的值应指向头结点。试按上述定义的结构改写求模式串的next函数值的算法。
 */

#ifndef HW_4_28_C
#define HW_4_28_C

#ifndef NODE_LENGTH
#define NODE_LENGTH 1
#endif
typedef struct linkNode{

    char chdata[NODE_LENGTH];   //数据
    
    struct linkNode *succ;      //指针域succ：存放同一链表中后继节点的指针
    struct linkNode *next;      //指针域next：在主串中存放指向同一链表的前驱结点的指针
                                //            在模式串中存放指向当该节点的字符与主串中的字符不想等时,模式串中下一个应进行比较的字符节点。
}linkNode,*LinkNode;

#include "LinkString.h"

Status StrAssign_4_28(LinkString *str,char *chars);        //临时用这个函数创建串
Status getNext_4_28(LinkString str);                //修改模式串中的next指针
void PrintString_4_28(LinkString str);


Status getNext_4_28(LinkString str){
   int i,j;
   LinkNode curor,next_j;
    
   str -> head -> next = NULL;                  //头接点的next为NULL
   curor = str -> head;
   next_j = NULL;
   while(curor -> succ != NULL){           //节点大小已知为1
        if((next_j == NULL) || ((curor -> chdata[0]) == (next_j -> chdata[0]))){
            curor = curor -> succ;
            next_j = (next_j == NULL? str -> head: next_j -> succ);
            curor -> next = next_j;
        }else{
            next_j = next_j -> next;
        }
   }
   printf("\n");
   return OK;
}


Status StrAssign_4_28(LinkString *str,char *chars){
    int i;
    LinkNode before,curor,after;
    (*str) = (LinkString)malloc(sizeof(linkString));
    if(!(*str)) exit(OVERFLOW);
    (*str) -> head = (LinkNode)malloc(sizeof(linkNode));
    (*str) -> head -> succ = (*str) -> head -> next = NULL;
    (*str) -> size = 0;

    curor = (*str) -> head;
    before = curor -> next;
    after = curor -> succ;

    for(i = 0;chars[i] != '\0';i++){
        if((i != 0 )&&(i%NODE_LENGTH == 0)){
            curor -> succ = (LinkNode)malloc(sizeof(linkNode));
            
            before = curor;
            curor = curor -> succ;
            curor -> succ = after;
            curor -> next = before;
        }
        curor -> chdata[i%NODE_LENGTH] = chars[i];
        ((*str) -> size)++;
    }
    return OK;
}

void PrintString_4_28(LinkString str){
    int i,len;
    LinkNode curor;

    curor = str -> head;
    len = str -> size;
    printf("String Length is :%d\n",len);
    for(i = 0;i < len;i++){
        if((i !=0) && (i%NODE_LENGTH == 0)){
            curor = curor -> succ;
        }
       // printf("\n");
        printf("address:%d\tdata:%s\tsucc:%d\tnext:%d\n",curor,curor -> chdata,curor->succ,curor->next);
    }
    printf("\n");
}

#ifndef MAIN
#define MAIN
int main(int argc,char **argv){
    LinkString T1;
  //  char *s = "abaaabaababaabcaabaabcacabaabcaabaabcac";
    char *t = "abaabcac";

    StrAssign_4_28(&T1,t);       //模式串
    PrintString_4_28(T1);

    getNext_4_28(T1);          
    PrintString_4_28(T1);

    return 0;
}
#endif
#endif
