## 线性表的抽象数据类型定义  

```
ADT List{  
    数据对象：D= { a<sub>i</sub>| a<sub>i</sub> 属于 ElemSet , i = 1,2 ... n,n => 0}
    数据关系：R1={ &lt;a<sub>i-1</sub>, a<sub>i</sub>&gt| a<sub>i-1</sub>,a<sub>i</sub>属于D, i=2,...,n }
    基本操作：
    	InitList(&L)
	    操作结果：构造一个空的线性表L
	DestroyList(&L)
	    初始条件：线性表L已存在
	    操作结果：销毁线性表L
	ClearList(&L)
	    初始条件：线性表L已存在
	    操作结果：将L重置为空表
	ListEmpty(L)
	    初始条件：线性表L已存在
	    操作结果：若L为空表，则返回TRUE，否则返回FALSE
	ListLength(L)
	    初始条件：线性表L已存在
	    操作结果：返回线性表L中数据元素的个数
	GetElem(L,i,&e)
	    初始条件：线性表已存在，1<=i<=ListLength(L)
	    操作结果：用e返回L中第i个数据元素的值
	LocateElem(L,e,compare())
	    初始条件：线性表L已存在，compare()是数据元素判定函数
	    操作结果：返回L中第一个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0.
	PriorElem(L,cur_e,&pre_e)
	    初始条件：线性表L已存在
	    操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义
	NextElem(L,cur_e,&next_e)
	    初始条件：线性表L已存在
	    操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义
	ListInsert(&L,i,e)
	    初始条件：线性表L已存在，1 <= i <= ListLength(L) + 1
	    操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
	ListDelete(&L,i,&e)
	    初始条件：线性表L已存在且不为空，1<= i <= ListLength(L)
	    操作结果：删除L的第i个数据元素，并用e返回其值，L的长度-1
	ListTraverse(L,visit())
	    初始条件：线性表L已存在
	    操作结果：依次对L的每个数据元素调用visit(),一旦visit()失败，则操作失败。
	    
} ADT List 

```
