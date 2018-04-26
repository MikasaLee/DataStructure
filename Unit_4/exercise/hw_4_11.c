/**
 * 4.11 编写算法，求得所有包含在串s中而不包含在串t中的字符（s中重复的字符只选一个）构成的新串r，以及r中每个字符在s中第一次出现的位置。
 */

#include "StringType.c"

typedef struct{
    StringType data;
    int a[MAXSTRLEN+1];
}HW_4_11;               //注意这不是指针


HW_4_11 hw_4_11(StringType s,StringType t){
    HW_4_11 r;
    r.a[0] = r.data[0] = 0;

    int i = 1,j = 1;
    int length_s = StrLength_ST(s),length_t=StrLength_ST(t);
    StringType *ch;

    while(i <= length_s){
        ch = SubString_ST(s,i,1);
        printf("截取的第%d个字符为",i);
        PrintString(*ch);
        if((j = Index(t,*ch,1)) == -1 && Index(r.data,*ch,1) == -1 ){
            StrInsert(r.data,StrLength_ST(r.data)+1,*ch);
            r.a[StrLength_ST(r.data)] = i;
        }
        i++;
    }
    return r;
}

#ifndef HW_4_19_C   //习题4.19会用到此文件
#define HW_4_19_C
int main(int argc,char **argv){

    StringType s,t;
    HW_4_11 r;
    int i;

    StrAssign_ST(s,"aswfiomoqwf");
    StrAssign_ST(t,"abcde");
    
    r = hw_4_11(s,t);
    for(i = 1;i<=StrLength_ST(r.data);i++){
        printf("第%d个字符为:%c,第一次出现的位置为%d\n",i,r.data[i],r.a[i]);
    }
    return 0;
}

#endif
