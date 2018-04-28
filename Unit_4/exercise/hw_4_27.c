/**
 * 4.27 当以教科书4.2.1节中定义的定长顺序结构表示串时，可如下所述改进定位函数的算法：
 *  先将模式串t中的第一个字符和最后一个字符与主串s中相应的字符比较，在两次比较都相等之后，再依次从t的第二个字符逐个比较。这样做可以克服算法Index（算法4.5）在求模式串’akb’（ak表示连续k个字符’a’）在主串’anb’（k≤n）中的定位函数时产生的弊病。试编写上述改进算法，并比较这两种算法在作Index（’anb’,’akb’）运算时所需进行的字符间的比较次数.
 */

/**
 * 步骤
 *  1. 先比较模式串中第一个和最后一个与主串相应的字符
 *  2. 若都想等，那么继续比较模式串中第二个字符
 *  3. 若有一个不想等，那么主串后移一位并且返回1.
 */

#include "../src/mySString.c"

int Index_4_27(SString S,SString T,int pos){
    int i,j,k;
    const int __len_s = StrLength(S);
    const int __len_t = StrLength(T);
    if(__len_s < __len_t) return -1;
    
    for(i = 1;i <= __len_s - __len_t + 1;i++){
        j = 1;
        if((S[i] == T[j]) && (S[i + __len_t - 1] == T[j + __len_t - 1])){
                while(j< __len_t){
                i++;
                j++;
                if(S[i] != T[j]) break;
            }
            i = i -j +1;
            if(j >= __len_t) return i;
        }
    }
    return -1;
}//index.c中的方法二得到的比较(n-k+1)*(k+1)次，而此改进的算法仅需要比较(n-k)*2+(k+1)次

int main(int argc,char **agrv){

    SString str1,str2;
    char *chars1,*chars2;
    chars1 = "abcdefghijklmn";
    chars2 = "cde";
    if(StrAssign(str1,chars1) && StrAssign(str2,chars2))
        printf("%s第一次出现在%s的位置为%d\n",chars2,chars1,Index_4_27(str1,str2,1));
    return 0;
}
