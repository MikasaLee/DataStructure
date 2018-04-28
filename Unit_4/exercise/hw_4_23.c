/**
 * 4.23 假设以块链结构作串的存储结构。试编写判别给定串是否具有对称性的算法，并要求算法的时间复杂度为O(StrLength(S))。
 */
//借助栈来实现，将前一半入栈，然后每次弹出一个与后面相对应的比较
#include "LinkString.c"
#include "../../Unit_3/src/SqStack.c"

Bool hw_4_23(LinkString str){
    int i;
    SqStack_L s;
    LinkNode curor;
    char ch;

    if(!InitStack_Sq(&s))   exit(OVERFLOW);
    curor = str -> head;
    for(i = 0;i<StrLength(str)/2;i++){
        if((i != 0) && (i%NODE_LENGTH == 0)) curor = curor -> next;
        Push_Sq(s,curor -> data[i%NODE_LENGTH]);
    }
    if((StrLength(str)%2) == 1){    //这里需要判断一下StrLength(str)的奇偶性
        if((i != 0) && (i%NODE_LENGTH == 0)) curor = curor -> next;
        i++;
    }
    for(;i<StrLength(str);i++){
        Pop_Sq(s,&ch);
        if((i != 0) && (i%NODE_LENGTH == 0)) curor = curor -> next;
        if(ch != (curor -> data[i%NODE_LENGTH])) return FALSE;
    }
    return TRUE;
}


int main(int argc,char **argv){

    char *chars1;
    LinkString str;
    chars1="abcdefgfedcba";
    if(StrAssign(&str,chars1)){
        if(hw_4_23(str))printf("%s有对称性\n",chars1);
        else printf("%s没有对称性\n",chars1);
    }else{
        printf("Function StrAssign: return ERROR!\n");
    }
    
    return 0;
}
