/**
 * 4.21 假设以结点大小为1（且附设头结点）的链表结构表示串。试编写实现下列六种串的基本操作StrAssign，StrCopy，StrCompare，StrLength，Concat和SubString的函数。
 */

//6个函数的实现都在LinkString.c文件中，此文件就相当于一个测试文件
#include "LinkString.c"

int main(int argc,char **argv){
    
    LinkString str1,str2;
    char *chars1,*chars2;

    printf("\n----------------测试StrAssign()函数---------------------------\n");
    chars1 = "abcdefghijklmnopqrstuvwxyz";
    if(StrAssign(&str1,chars1)){
       PrintString(str1); 
    }else{
        printf("Function of StrAssign : return ERROR!\n");
    }


    printf("\n----------------测试StrCopy()函数---------------------------\n");
    if(StrCopy(&str2,str1)){
       PrintString(str2); 
    }else{
        printf("Function of StrCopy : return ERROR!\n");
    }

    printf("\n----------------测试StrCompare()函数---------------------------\n");
    chars1="aaab";
    chars2=NULL;

    if(StrAssign(&str1,chars1) && StrAssign(&str2,chars2)){
        if(StrCompare(str1,str2) > 0) printf("%s > %s\n",chars1,chars2);
        else if(StrCompare(str1,str2) == 0) printf("%s = %s\n",chars1,chars2);
        else printf("%s < %s\n",chars1,chars2);
    }else{
        printf("Function of StrAssign : return ERROR!\n");
    }

    printf("\n----------------测试Concat()函数---------------------------\n");
    chars2="abcdefghijklmnopqrstuvwxyz";
    chars1=NULL;
    //chars1 = "aaac";
    //chars2 = "AAACB";
    if(StrAssign(&str1,chars1) && StrAssign(&str2,chars2)){
            if((str1 = Concat(str1,str2)) != NULL) PrintString(str1);
            else printf("Function of Concat : return NULL\n");
    }else{
        printf("Function of StrAssign : return ERROR!\n");
    }

    printf("\n----------------测试SubString()函数---------------------------\n");
    chars1 = "abcdefghijklmnopqrstuvwxyz";
    if(StrAssign(&str1,chars1)){
            if((str2 = SubString(str1,3,6)) != NULL) PrintString(str2);
            else printf("Function of SubString : return NULL\n");
    }else{
        printf("Function of StrAssign : return ERROR!\n");
    }
    return 0;
}
