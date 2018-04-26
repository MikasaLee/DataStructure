/**
 * 4.13 编写算法，从串s中删除所有和串t相同的子串。
 */

#include "StringType.c"

Status StrDelete_SL(StringType s,int pos,int len){
    return StrDelete(s,pos,len);
}

Status hw_4_13(StringType s,StringType t){
    int i,j;
    StringType begin,end,temp;
    if(StrLength_ST(s) < StrLength_ST(t)) return OK;
    while(TRUE){
        i = Index(s,t,1);
        if(i == -1) break;
        StrDelete_SL(s,i,StrLength_ST(t));
    }
    return OK;
}

int main(int argc,char **argv){

    char *chars1="abcdefghijklmnopqrstuvwxyz";
    char *chars2 = "ghijk";
    StringType str1,str2;
    StrAssign_ST(str1,chars1);
    StrAssign_ST(str2,chars2);
    
    printf("before delete:\n");
    PrintString(str1);

    hw_4_13(str1,str2);
    printf("after delete:\n");
    PrintString(str1);
    return 0;
}
