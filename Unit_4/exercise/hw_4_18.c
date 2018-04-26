/**
 * 4.18 编写算法，求串s所含不同字符的总数和每种字符的个数。 
 */

#include "../src/mySString.c"

typedef struct{
    
    SString data;
    int a[MAXSTRLEN+1];

}HW_4_18;

HW_4_18 hw_4_18(SString s){
    SString temp;
    int i=1,len=StrLength(s),j;
    HW_4_18 r;
    r.data[0] = r.a[0] = 0;

    while(i<=len){
        SubString(temp,s,i,1);
        if((j = Index(r.data,temp,1)) == -1){
                StrInsert(r.data,StrLength(r.data)+1,temp);
                r.a[StrLength(r.data)] = 1;
        }else r.a[j]++;
        i++;
    }
    return r;
}

int main(int argc,char **argv){
    SString s;
    HW_4_18 r;
    int i;
    
    StrAssign(s,"aswfiomoqwf");
    r = hw_4_18(s);
    for(i = 1;i<=StrLength(r.data);i++){
            printf("第%d个字符为:%c,出现了%d次\n",i,r.data[i],r.a[i]);
    }

    return 0;
}
