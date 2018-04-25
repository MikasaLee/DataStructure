/**
 * 4.12 编写一个实现串的置换操作Replace(&S, T, V)的算法
 */

//见../mySString.c文件中的Status Replace(SString S,SString T,SString V)函数
#include "StringType.c"
Status Replace_ST(StringType S,StringType T,StringType V){
    return Replace(S,T,V);
}

int main(int argc,char **argv){
    printf("\n---------测试Replace_ST(StringType S,StringType T,StringType V)函数------------\n");
    StringType str1,str2,str3;
    char *chars1,*chars2,*chars3;
    chars1 = "dsfasdfasfdasdfsa ";
    StrAssign(str1,chars1);
    chars2 = "a";
    StrAssign(str2,chars2);
    chars3 = "A";
    StrAssign(str3,chars3);
    
    PrintString(str1);
    printf("\n\n");
    Replace_ST(str1,str2,str3);
    PrintString(str1);

    
    return 0;
}
