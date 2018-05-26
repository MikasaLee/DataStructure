/*************************************************************************
	> File Name: EGList.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Sat 26 May 2018 05:28:47 PM CST
 ************************************************************************/
#include "./EGList.h"

Status InitEGList(EGList *L){
	if(!((*L) = malloc(sizeof(EGLNode)))) exit(OVERFLOW);
	(*L) -> tag = LIST;
	(*L) -> Union.hp = (*L) -> tp = NULL;
	return OK;
}

//书上的算法5.8,server(SString str,SString hstr):
/**
 * 从字符串str中取出第一个","之前的子串赋给hstr.
 * 并使str称为删去子串hstr和","之后的剩余串，
 * 若str中没有字符","，则操作后的hstr为操作前的str，而操作后的str为null
 */
Status server(SString str,SString hstr){
	//将非空串str分割成两部分:hsub为第一个","之前的子串，"str"为之后的子串
	SString ch;
	int n = StrLength(str),i = 0 ,k = 0;
	do{
		++i;
		SubString(ch,str,i,1);
		if(ch[1] == '(') ++k;
		else if(ch[1] == ')') --k;
	}while(i<n && ((ch[1] != ',')||k!=0));
	if(i < n){
		SubString(hstr,str,1,i-1);
		SubString(str,str,i+1,n-i);
	}else{
		StrCopy(hstr,str);
		ClearString(str);
	}
	return OK;
}

//书上的算法5.7
Status CreateEGList(EGList *L,SString S){
	SString emp,sub,hsub;
	EGList p,q;
	if(!StrAssign(emp,"()") || !InitEGList(L)) exit(OVERFLOW);
	if(StrCompare(S,emp) !=0){
		if(StrLength(S) == 1){
			(*L) -> tag = ATOM;
			(*L) -> Union.atom = S[1];
			(*L) -> tp = NULL;
		}else{
			(*L) -> tag = LIST; 
			p = *L;
			SubString(sub,S,2,StrLength(S)-2);		//脱掉最外层的括号
			do{			//重复建n个子表
				server(sub,hsub);	//分离表头和表尾
				CreateEGList(&(p -> Union.hp),hsub);	//建立表头
				q = p;
				if(!StrEmpty(sub)){	//表尾不为空
					if(!InitEGList(&p)) exit(OVERFLOW);
					p -> tag = LIST;
					q -> tp = p;
				}//if
			}while(!StrEmpty(sub));
			q -> tp = NULL;
		}//else
	}//esle
	return OK;
}


Status DestroyEGList(EGList *L){
	EGList p,q;
	if(!(*L)) return OK;
	if((*L) -> tag != ATOM){
		p = (*L) -> Union.hp;
		q = (*L) -> tp;
		DestroyEGList(&p);
		DestroyEGList(&q);
	}
	free(*L);
	(*L) = NULL;
	return OK;

}
Status CopyEGList(EGList L,EGList *T){
	EGList p,q;
	if(!L) (*T) = NULL;			//表不存在
	else{
		if(!InitEGList(T)) exit(OVERFLOW);
		if(L ->tag == ATOM){
			(*T) -> tag = ATOM;
			(*T) -> Union.atom = L -> Union.atom;
		}else{
			(*T) -> tag = LIST;
			p = EGetHead(L);
			q = EGetTail(L);
			CopyEGList(p,&((*T) -> Union.hp));
			CopyEGList(q,&((*T) -> tp));
		}
	}
	return OK;

}

int EGListLength(EGList L){
	int i=0;
	EGList p,q;
	if(!L) return -1;	//表不存在
	if(EGListEmpty(L)) return 0;	//空表
	else{
		if(L -> tag == ATOM) i++;
		else{
			if(!EGListEmpty(EGetHead(L))) i+=EGListLength(EGetHead(L));
			if(!EGListEmpty(EGetTail(L))) i+=EGListLength(EGetTail(L));
		}
	}
	return i;
}

//广义表的深度定义为广义表中括弧的重数
int EGListDepth(EGList L){
	int i=0,max=0,temp;
	if(!L) return -1;		//表不存在
	if(EGListEmpty(L)) return i+1;
	else{
		if(L -> tag == LIST){
			i++;
			while(L){
				temp = EGListDepth(L -> Union.hp);
				max = max < temp?temp:max;
				L = L -> tp;
			}
			i+=max;
		}
	}
	return i;
}

Bool EGListEmpty(EGList L){
	if(!L ||((L -> tag == LIST)&& (L -> Union.hp == NULL) && (L -> tp == NULL)))
		return TRUE;
	return FALSE;
}

EGList EGetHead(EGList L){
	if(!L || (L -> tag == ATOM)) return NULL;
	return L -> Union.hp;
}

EGList EGetTail(EGList L){
	return L -> tp;
}

Status InsertFirst_EGL(EGList *L,EGList e){
	EGList p;
	
	if(!(*L)|| !CopyEGList(*L,&p)) return ERROR;

	p -> tag = LIST;
	p -> Union.hp = e;
	p -> tp = (*L);
	(*L) = p;
	return OK;
}

Status DeleteFirst_EGL(EGList *L,EGList *e){
	EGList p;
	
	if(!(*L)) return ERROR;
	if((*L) -> tag == LIST){
		(*e) = (*L) -> Union.hp;
		(*L) = (*L) -> tp;
	}else{
		(*e) = (*L);
		(*L) = NULL;
	}
	return OK;	
}
Status Traverse_EGL(EGList L,Bool (*visit)(AtomType)){
	if(!L) return ERROR;
	if(L -> tag == ATOM) visit(L -> Union.atom);
	else{
		printf("(");
		while(L){
			Traverse_EGL(L -> Union.hp,visit);
			if(L -> tp)printf(",");
			L = L -> tp;
		}
		printf(")");
	}
	return OK;
}

