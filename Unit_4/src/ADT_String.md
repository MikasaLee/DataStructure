## 字符串的抽象数据类型定义

```
ADT String{
    数据对象：D={ a<sub>i</sub>| a<sub>i</sub> 属于 CharacterSet , i = 1,2 ... n,n >= 0}
    数据关系：R1={ &lt;a<sub>i-1</sub>, a<sub>i</sub>&gt| a<sub>i-1</sub>,a<sub>i</sub>属于D, i=2,...,n }
    基本操作：
    	StrAssign(&T,chars)
	    初始条件：chars是字符串常量
	    操作结果：生成一个其值等于chars的串T
	StrCopy(&T,S)
	    初始条件：串S存在
	    操作结果：由串S复制得串T
	StrEmpty(S)
	    初始条件：串S存在
	    操作结果：若S为空串，则返回TRUE，否则返回FALSE
	StrCompare(S,T)
	    初始条件：串S和T存在
	    操作结果：若S>T,则返回值>0;若S=T,则返回值=0,若S<T,则返回值<0
	StrLength(S)
	    初始条件：串S存在
	    操作结果：返回S的元素个数，称为串的长度
	clearString(&S)
	    初始条件：串S存在
	    操作结果：将S清为空串
	Concat(&T,S1,S2)
	    初始条件：串S1和串S2存在
	    操作结果：用T返回S1和S2连接而成的新串
	SubString(&Sub,S,pos,len)
	    初始条件：串S存在，1<=pos<=StrLength(S) 且 0<=len<=StrLength(S)-pos+1
	    操作结果：用Sub返回串S的[pos,pos+length)的子串
	Index(S,T,pos)
	    初始条件：串S和T存在，T是非空串，1<=pos<=StrLength(S)
	    操作结果：若主串S中存在和串T相同的子串，则返回它在主串S中第pos个字符后第一次出现的位置，否则返回-1
	Replace(&S,T,V)
	    初始条件：串S，T和V存在，T是非空串
	    操作结果：用V替换主串S中出现的所有与T相等的不重叠的子串
	StrInsert(&S,pos,T)
	    初始条件：串S和T存在，1<=pos<=StrLength(S)+1
	    操作结果：在串S的第pos个字符之前插入串T
	StrDelete(&S,pos,len)
	    初始条件：串S存在，1<=pos<=StrLength(S) - len + 1
	    操作结果：从串S中删除第pos个字符起长度为len的子串
	DestroyString(&S)
	    初始条件：串S存在
	    操作结果：串S被销毁
}
```
