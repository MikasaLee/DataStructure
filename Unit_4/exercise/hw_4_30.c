/**
 * 4.30 假设以定长顺序存储结构表示串，试设计一个算法，求串s中出现的第一个最长重复子串及其（第一次出现的）位置，并分析你的算法的时间复杂度。
 */

/**
 * 这里的最长重复子串有三层含义
 *  第一：此子串在所有重复子串中是首个出现的
 *  第二：子串间可以重叠，比如求取abcabca的结果为abca
 *  第三：子串内可以重复，如求取aaaa的结果为aaa。
 */

#define MAXSTRLEN 50
#include "../src/mySString.c"
//笨办法：从先找出第一个字符的最大子串，然后再找第二个字符的最大子串。。。。。

int hw_4_30(SString S,SString sub){

    int i,j,k;
    int start,end,begin,temp_len = -1,temp_start;

    for(i=1;i<=StrLength(S);i++){
        for(j = i;j<=StrLength(S);j++){
            start = end = j;
            for(begin = j, k = j+1;k<=StrLength(S);k++){
                if(S[begin] == S[k]){
                    begin++;
                    end++;
                }else{
                    if(temp_len < end - start){
                        temp_len = end -start;
                        temp_start = start;
                    }
                    end = begin = j;
                }
            }
        }
    }
    printf("temp_start:%d,temp_len:%d\n",temp_start,temp_len);
    start = temp_start;
    for(i = 1;i<=temp_len;i++,start++){
        sub[i] = S[start];
    }
    sub[0] = temp_len;
    return temp_start;
}//时间复杂度为O(StrLength(S)^3)

int main(int argc,char **argv){

    char *s= "abcdeabcabcbcdefbcdefefghefgh";
    SString sub,S;
    int pos;

    StrAssign(S,s);
    PrintString(S);
    
    pos=hw_4_30(S,sub);
    
    printf("%s的最大子串的位置为:%d,子串为：\n",s,pos);
    PrintString(sub);

    return 0;
}
