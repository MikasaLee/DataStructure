/**
 * 4.31 假设以定长顺序存储结构表示串，试设计一个算法，求串s和串t的一个最长公共子串，并分析你的时间复杂度。若要求第一个出现的最长公共子串（即它在串s和串t的最左边的位置上出现）和所有的最长公共子串，讨论你的算法能否实现。
 */

#define MAXSTRLEN 200
#include "../src/mySString.c"

int hw_4_31(SString S,SString T,SString *sub){
    int i,j,k,start=-1;
    SString temp_sub;
    int len_s;
    len_s = StrLength(S);
    for(i = 1;i<= len_s;i++){
        for(j = i+1;j<= len_s;j++){
            SubString(temp_sub,S,i,j-i);
            if(Index(T,temp_sub,1) != -1){
                if((StrLength(temp_sub) > StrLength(*sub))){
                    StrCopy(*sub,temp_sub);
                    start = i;
                }
            }
        }
    }
    return start;
}

int main(int argc,char **argv){

    char *s = "abcd*lokis***hyuij**vfgh*lokis****yu*mklng***u****wy*c*vdgry*pklnh";
    char *t = "-vdgry------vfgh-------hyuij----abcd-------pklnh--yu-----lois----uio-u-wy------------mklng-c";
    SString S,T,sub;
    int i;

    StrAssign(S,s);
    StrAssign(T,t);
    printf("---------------------------\n");
    printf("S:\n");
    PrintString(S);
    printf("T:\n");
    PrintString(T);
    printf("---------------------------\n");

    i = hw_4_31(S,T,&sub);
    printf("S中第一次出现的位置:%d\n",i);
    PrintString(sub);
    printf("---------------------------\n");

    return 0;
}
