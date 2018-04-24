#include "stdio.h"
#include "../src/wordIndexTable.c"

int main(int argc,char **args){
    printf("书库文件为booklist.txt,输出的文件为answer.txt\n");
    StrAssign(&wdIgnorelist," a an the of A An The Of and And To to ");
    IdxListType idxList;
    FILE *fin,*fout;
    ElemType id;
    if((fin=fopen("booklist.txt","r")) == NULL){
        printf("fopen error!\n");
        exit(OVERFLOW);
    }
    if(InitIdxList(&idxList)){
        while(GetLine(fin)){
            wdlist = (book *)malloc(sizeof(book));    
            ExtractKeyWord(&id);
            InsIdxList(idxList,id);

            free(wdlist);
            wdlist = NULL;
        }
        if((fout = fopen("answer.txt","w")) == NULL){
            printf("fopen error!\n");
            exit(OVERFLOW);
        }
        PutText(fout,idxList);
    }

    return 0;
}
