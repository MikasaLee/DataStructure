/**
 * 4.4.2 建立词索引表
 */
#ifndef WORDINDEXTABLE_H
#define WORDINDEXTABLE_H

#ifndef ELEMTYPE
#define ELEMTYPE
typedef int ElemType;			//规定ElemType为int
#endif

#include "../../Unit_2/src/LinkList.c"	//提供动态数组
#include "index.c"			//提供字符串
#define MaxBookNum          1000    //假设只对1000本书建立索引表
#define MaxKeyNum           500	    //索引表的最大容量,Keyword的数组大小
#define MaxLineLen          100     //书目串的最大长度,(50还不行 测试代码中书号34的书名>50)
#define MaxWordNum          10      //词表的最大容量,就是书名分割后的最大数组长度
typedef struct{
	char item[MaxWordNum][MaxLineLen];  //书名的关键字的字符串数组
	int size;		            //item的长度
	int id;			            //书号
}book,*Book;			            //书类型

typedef struct{			
	HString key;		//关键字
	LinkList listBook;	//对应的书号,由于插入操作众多，并且每一个key对应的书的个数也参差不起，有可能相差众多，因此使用链式存储比顺序存储更好
}idxTermType,*IdxTermType;	//索引项类型

typedef struct{
	IdxTermType *keyword;	//存放所有的关键字KeyWord
	int size;		//keyword的长度
	int capacity;		//容量大小
}wordIndexTable,*IdxListType;	//词索引表

char buf[MaxLineLen];
Book wdlist = NULL;
HString wdIgnorelist = NULL;

//基本操作：
Status InitIdxList(IdxListType *idxList);		//初始化操作，置索引表idxList为空表。/**?且在idxList -> keyword[0]设一空串?**/
Status GetLine(FILE *f);				//从文件f中读入一个书目信息到缓冲区buf中
Status ExtractKeyWord(ElemType *id);		        //从buf中提取书名关键字到词表wdlist中，书号存入id;
Status InsIdxList(IdxListType idxList,ElemType id);	//将书号为id的书名关键字按词典顺序插入索引表idxList中
Status PutText(FILE *f,IdxListType idxList);	        //将生成的索引表idxList输出到文件g中。

/*InsIdxList()函数实现需要以下操作*/
Status GetWord(int i,HString *wd);                        //用wd返回词表wdlist中第i个关键字
int Locate(IdxListType idxlist,HString wd,Bool *b);     //在索引表idxlist中查询是否存在与wd相等的关键词。若存在，返回其在索引表中的位置，且b为TRUE，否则返回插入位置，且b为FALSE
Status InsertNewKey(IdxListType idxlist,int i,HString wd);   //在索引表idxlist的第i项上插入新关键字wd，并初始化书号索引链表为空表
Status InsertBook(IdxListType idxlist,int i,ElemType id);   //在索引表idxlist的第i项中插入书号为id的索引

#endif

