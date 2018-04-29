/**
 * 4.29 试按4.28题定义的结构改写串匹配的改进算法（KMP算法）。
 */

#ifndef MAIN
#define MAIN
#endif
#include "hw_4_28.c"

int Index_hw_4_29(LinkString S,LinkString T,int pos){
    int i,j;
    LinkNode curor_s,curor_t;
    getNext_4_28(T);

    curor_s = S -> head;
    for(i = 1;i<pos;i++) curor_s = curor_s -> succ;
    curor_t = T -> head;
    for(i=0,j=0;i < S -> size;){
        if((curor_t != NULL) && ((curor_s -> chdata[0]) == (curor_t -> chdata[0]))){
            i++;
            j++;
            curor_s = curor_s -> succ;
            curor_t = (curor_t == NULL?T -> head:curor_t -> succ);
            if(curor_t == NULL) return i - j + 1;
        }else{
            j = 0;
            curor_t = curor_t -> next;
        }
    }
    return -1;
}

int main(int argc,char **argv){
        LinkString S,T1;
        char *s = "abaaabaababaabcaabaabcacabaabcaabaabcac";
        char *t = "abaabcac";
        
        StrAssign_4_28(&S,s);       //主串
        StrAssign_4_28(&T1,t);       //模式串
        
        PrintString_4_28(S);
        PrintString_4_28(T1);

        printf("%s在%s中第一次出现的位置为:%d\n",t,s,Index_hw_4_29(S,T1,1));
}
