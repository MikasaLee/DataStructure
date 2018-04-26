/**
 * 4.19 在串的定长顺序存储结构上直接实现4.11题要求的算法。 
 */

#ifndef HW_4_19_C
#define HW_4_19_C
#include "hw_4_11.c"

typedef HW_4_11 HW_4_19;

HW_4_19 hw_4_19(SString s,SString t){
    return hw_4_11(s,t);
}
int main(int argc,char **argv){

    SString s,t;
    HW_4_19 r;
    int i;

    StrAssign(s,"aswfiomoqwf");
    StrAssign(t,"abcde");
    
    r = hw_4_19(s,t);
    for(i = 1;i<=StrLength(r.data);i++){
        printf("第%d个字符为:%c,第一次出现的位置为%d\n",i,r.data[i],r.a[i]);
    }
    return 0;
}

#endif
