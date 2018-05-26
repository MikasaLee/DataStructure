/*************************************************************************
	> File Name: GList.h
	> Author: RunRui_Li
	> Mail: 770486267@qq.com 
	> Created Time: Fri 25 May 2018 08:09:20 PM CST
 ************************************************************************/

#include "./GList.h"

Status InitGList(GList *L){	//空表定义：L -> tag为表结点，且hp = tp = NULL
	(*L) = NULL;
	if(!((*L) = (GList)malloc(sizeof(GLNode)))) exit(OVERFLOW);
	(*L) -> tag = LIST;
	(*L) -> Union.ptr.hp = (*L) -> Union.ptr.tp = NULL;
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
//		printf("i=%d\n",i);
//			PrintString(hstr);
//			PrintString(str);
	}else{
		StrCopy(hstr,str);
		ClearString(str);
	}
	return OK;
}

//书上的算法5.7
Status CreateGList(GList *L,SString S){
	SString emp,sub,hsub,temp;
	GList p,q;
	if(StrEmpty(S))	return OK;
	if(!StrAssign(emp,"()")) exit(OVERFLOW);
	if(!InitGList(L)) exit(OVERFLOW);
	if(StrCompare(S,emp) != 0){ 
		if(StrLength(S) == 1){		//创建单原子广义表
			(*L) -> tag = ATOM;
			(*L) -> Union.atom = S[1];
		}else{
			(*L) -> tag = LIST;
			p = *L;
			SubString(sub,S,2,StrLength(S)-2);		//脱外层括号
//			PrintString(sub);
//			PrintString(sub);
//			PrintString(hsub);
			
			//重复建n个子表
			do{
				server(sub,hsub);				//分离表头和表尾
				CreateGList(&(p -> Union.ptr.hp),hsub);	//创建表头
				q = p;
				if(!StrEmpty(sub)){				//表尾不空
					if(!InitGList(&p)) exit(OVERFLOW);
					p -> tag = LIST;
					q -> Union.ptr.tp = p;
				}
			}while(!StrEmpty(sub));
			q -> Union.ptr.tp = NULL;
		}//else
	}
	return OK;
}//CreateGList

Status DestroyGList(GList *L){
	GList p,q;
	if(!(*L)) return OK;
	if((*L) -> tag != ATOM){
		p = (*L) -> Union.ptr.hp;
		q = (*L) -> Union.ptr.tp;
		DestroyGList(&p);
		DestroyGList(&q);
	}
	free(*L);
	(*L) = NULL;
	return OK;
}

Status CopyGList(GList L,GList *T){
	GList p,q;
	if(!L) (*T) = NULL;			//表不存在
	else{
		if(!InitGList(T)) exit(OVERFLOW);
		if(L ->tag == ATOM){
			(*T) -> tag = ATOM;
			(*T) -> Union.atom = L -> Union.atom;
		}else{
			(*T) -> tag = LIST;
			p = GetHead(L);
			q = GetTail(L);
			CopyGList(p,&((*T) -> Union.ptr.hp));
			CopyGList(q,&((*T) -> Union.ptr.tp));
		}
	}
	return OK;
}

int GListLength(GList L){
	int i=0;
	GList p,q;
	if(!L) return -1;	//表不存在
	if(GListEmpty(L)) return 0;	//空表
	else{
		if(L -> tag == ATOM) i++;
		else{
			if(!GListEmpty(GetHead(L))) i+=GListLength(GetHead(L));
			if(!GListEmpty(GetTail(L))) i+=GListLength(GetTail(L));
		}
	}
	return i;
}

//广义表的深度定义为广义表中括弧的重数
int GListDepth(GList L){
	int i=0,max=0;
	if(!L) return -1;		//表不存在
	if(GListEmpty(L)) return i+1;
	else{
		if(L -> tag == LIST) {
			i++;
			max = GListDepth(GetHead(L)) > GListDepth(GetTail(L))?GListDepth(GetHead(L)):GListDepth(GetTail(L));	//前面已经判断过L不为空，所以这里Head和Tail不会都为NULL
			i+=max;
		}
	}
	return i;
}

Bool GListEmpty(GList L){
	if(!L) exit(OVERFLOW);
	if((L -> tag == LIST)&& (L -> Union.ptr.hp == NULL) && (L -> Union.ptr.tp == NULL)) 
		return TRUE;
	return FALSE;
}

GList GetHead(GList L){
	if(!L || (L -> tag == ATOM)) return NULL;
	return L -> Union.ptr.hp;
}

GList GetTail(GList L){
	if(!L || (L -> tag == ATOM)) return NULL;
	return L -> Union.ptr.tp;
}

Status InsertFirst_GL(GList *L,GList e){
	GList p;
	
	if(!(*L)|| CopyGList(*L,&p)) return ERROR;

	p -> tag = ATOM;
	p -> Union.ptr.hp = e;
	p -> Union.ptr.tp = *L;
	(*L) = p;
	return OK;
}

Status DeleteFirst_GL(GList *L,GList *e){
	GList p;
	
	if(!(*L)) return ERROR;
	if((*L) -> tag == LIST){
		(*e) = (*L) -> Union.ptr.hp;
		(*L) = (*L) -> Union.ptr.tp;
	}else{
		(*e) = (*L);
		(*L) = NULL;
	}
	return OK;	
}
Status Traverse_GL(GList L,Bool (*visit)(AtomType)){
	if(!L) return ERROR;
	if(L -> tag == ATOM) visit(L -> Union.atom);
	else{
		printf("(");
		Traverse_GL(L -> Union.ptr.hp,visit);
		printf(",");
		Traverse_GL(L -> Union.ptr.tp,visit);
		printf(")");
	}
	return OK;
}
