/**
 * 4.22 假设以块链结构表示串。试编写将串s插入到串t中某个字符之后的算法（若串t中不存在此字符，则将串s联接在串t的末尾）。
 */

#include "LinkString.c"

Status hw_4_22(LinkString *t,LinkString s,char ch){
    LinkString begin,end;
    LinkNode curor;
    int i;
    curor = (*t) -> head;
    for(i = 0;i<StrLength(*t);i++){
        if((i != 0) && (i %NODE_LENGTH == 0)) curor = curor -> next;
        if((curor -> data[i%NODE_LENGTH]) == ch) break;
    }
    //i值为插入的位置
    if(i == StrLength(*t)){
            (*t) = Concat(*t,s);
            return OK;
    }else{
        begin = SubString(*t,1,i+1);   //[1,i+2)
        end = SubString(*t,i+2,StrLength(*t) - i-1);    //[i+2,StrLength(t)+1)
        (*t) = Concat(begin,s);
        (*t) = Concat(*t,end);
        return OK;
    }
}

int main(int argc,char **argv){

    printf("\n------------测试hw_4_22函数---------------\n");
    char *chars1,*chars2;
    LinkString str1,str2;

    chars1 = "abcdefghijklmnopqrstuvwxyz";
    chars2 = "ABCDEFGHIJKLMNOPQRSTUVWXTZ";

    if(StrAssign(&str1,chars1) && StrAssign(&str2,chars2)){
        hw_4_22(&str1,str2,'A');
        PrintString(str1);
    }else{
        printf("Function StrAssign:return ERROR!\n");
    }

    return 0;
}

