#include "StringType.h"

void StrAssign_ST(StringType t,StringType s){
    StrAssign(t,s);
}

int StrCompare_ST(StringType s,StringType t){
    return StrCompare(s,t);
}

int StrLength_ST(StringType s){
    return StrLength(s);
}

StringType* Concat_ST(StringType s,StringType t){
    StringType *temp = (StringType *)malloc(sizeof(StringType));
    Concat(*temp,s,t);
    return temp;
}

StringType* SubString_ST(StringType s,int start,int len){
    StringType *temp = (StringType *)malloc(sizeof(StringType));
    SubString(*temp,s,start,len);
    return temp;
}
