/**
 * 4.10 编写对串求逆的递推算法
 */

#include "StringType.c"
Status StrReverse(StringType t){
    int i,j;
    int length = StrLength_ST(t);
    for(i = 1;i < length -i;i++){
        t[i] = t[length-i+1] ^t[i];
        t[length-i+1] = t[i] ^ t[length-i+1];
        t[i] = t[i] ^ t[length-i+1];
    }
    return OK;
}

int main(int argc,char **argv){
    StringType str;
    StrAssign_ST(str,"abcdefgh");
    PrintString(str);
    StrReverse(str);
    PrintString(str);
    return 0;
}
