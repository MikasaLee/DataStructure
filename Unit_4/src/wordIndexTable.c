#ifndef WORDINDEXTABLE_C
#define WORDINDEXTABLE_C

#include "wordIndexTable.h"

Status InitIdxList(IdxListType *idxList){
    (*idxList) = (IdxListType)malloc(sizeof(wordIndexTable));
    if(!(*idxList)){
        printf("idxList malloc error!\n");
        exit(0);
    }
    (*idxList) -> keyword = (IdxTermType *)malloc(sizeof(idxTermType)*MaxKeyNum);
    if(!((*idxList) -> keyword)){
        printf("keyword malloc error!\n");
        exit(0);
    }
    
    (*idxList) -> size = 0;
    (*idxList) -> capacity = MaxKeyNum;
    return OK;
}

Status GetLine(FILE *f){
    if(fgets(buf,MaxLineLen-1,f) != NULL){
    //      printf("%s\n",buf);     // 测试代码OK!
            return OK;
    }
    printf("GetLine read a line in file error!\n");
    return ERROR;
}

Status ExtractKeyWord(ElemType *id){
    int i=0;
    FILE *f;
    char strid[4],test;
    HString hstr;

    f = tmpfile();                      //建立临时文件
    fprintf(f,"%s",buf);                //把字符串写入临时文件
    fseek(f,0,0);                       //把文件指针移到开始位置

    fscanf(f,"%s",strid);
    sscanf(strid,"%d",&(wdlist -> id));

    for(i = 0;i<MaxLineLen;){
        if(fscanf(f,"%s",wdlist -> item[i]) == EOF) break;      //这里一个小技巧，和下面没有过滤的比对，废除了feof的使用改为用fscanf来判断是否到文件结束；虽然fscanf返回EOF的条件不一定是文件结束,但是目前是真的没办法了。。。实为无奈之举
    //  printf("47:%s\n",wdlist -> item[i]);        //测试代码
        StrAssign(&hstr,wdlist -> item[i]);
        if(Index_KMP(wdIgnorelist,hstr,1) == -1){
            i++;
        }
    }
/**
    for(i = 0;i<MaxLineLen && !feof(f);i++){
        fscanf(f,"%s",wdlist -> item[i]);
    //  printf("57:%s\n",wdlist -> item[i]);    //测试代码
    }
**/
    wdlist -> size = i;
    (*id) = wdlist -> id;
    return OK;
}

/**先实现InsIdxList需要的操作**/
Status GetWord(int i,HString *wd){
    if(i > wdlist -> size){
        printf("参数%d超出范围!\n",i);
        return ERROR;
    }
    StrAssign(wd,wdlist ->item[i]);
    return OK;
}

int Locate(IdxListType idxList,HString wd,Bool *b){
    int i,compare;
    for(i = 0; i < idxList -> size;i++){
        if((compare=StrCompare(idxList -> keyword[i] -> key,wd)) >= 0 ){
            if(compare == 0){
                (*b) = TRUE;
                return i;
            }
            (*b) = FALSE;
            return i;
        }
    }
    (*b) = FALSE;
    return i;
}

Status InsertNewKey(IdxListType idxlist,int position,HString wd){
    IdxTermType idx;
    int i;
    if(position < 0 || position > idxlist -> size +1 || idxlist -> size +1 >MaxBookNum)  return ERROR;
    idx = (IdxTermType)malloc(sizeof(idxTermType));
    if(idx){
        StrCopy(&(idx -> key),wd);
        InitList_L(&(idx -> listBook));

        for(i = idxlist -> size;i>=position;i--){
            idxlist -> keyword[i+1] = idxlist -> keyword[i];
        }
        idxlist -> keyword[position] = idx;
        idxlist -> size++;
        return OK;
    }
    return ERROR;
}

Status InsertBook(IdxListType idxlist,int position,ElemType id){
    int i;
    if(position < 0 || position > idxlist -> size +1 || idxlist -> size +1 >MaxBookNum)  return ERROR;
    if(ListInsert_L(idxlist -> keyword[position] -> listBook,ListLength_L(idxlist -> keyword[position] -> listBook)+1,id)) return OK;
    return ERROR;
}


Status InsIdxList(IdxListType idxList,ElemType id){
    int i,position;
    HString str;

    Bool isExist;
    if(id != wdlist -> id){
        printf("id error!\n");
        return ERROR;
    }
    for(i = 0;i<wdlist -> size;i++){
        GetWord(i,&str);
        position=Locate(idxList,str,&isExist);
        if(isExist == FALSE)    InsertNewKey(idxList,position,str);
        InsertBook(idxList,position,id);
    }
    return OK;
}

Status PutText(FILE *f,IdxListType idxList){
    int i,j,k;
    IdxTermType idx;
    ElemType next;
    for(i = 0;i<idxList -> size;i++){
        fprintf(f,"关键字：%s ,书号：",idxList -> keyword[i] -> key ->Base);
        k = ListLength_L(idxList -> keyword[i] -> listBook);
        GetElem_L(idxList -> keyword[i] -> listBook,1,&next);
        for(j = 0;j<k;j++,NextElem_L(idxList -> keyword[i] -> listBook,next,&next)){
            fprintf(f,"%d ",next);
        }
        fprintf(f,"\n");
    }
    return OK;
}
#endif
