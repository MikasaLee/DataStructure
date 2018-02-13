/**(测试代码在./t_NoHeadLinkList.c文件中)
 *
 * 2.17 试写一算法，在无头结点的动态单链表上实现线性表操作INSERT(L, i, b)，并和在带头结点的动态单链表上实现相同操作的算法进行比较。
 */

Status hw_2_17(LinkList *L,int i,ElemType b){	//没有头结点的话不好判断L到底是空节点还是空指针，所以改一下规定：当i>ListLength_L(*L)时,b插在L表的最后
	LinkList p,prior,temp;
	int j;
	if(i < 0) exit(OVERFLOW);
	if(!(*L) || i == 1){	//L表为空或者i为1
		p = (LinkList)malloc(sizeof(LNode));
		if(p){
			p -> data = b;
			p -> next = (*L);
			(*L) = p;
			return OK;
		}
		printf("\n申请空间失败\n");
		return ERROR;
	}
	j = 1;p = (*L);
	while(p && j < i){
		prior = p;
		p = p -> next;
		j++;
	}
	p = prior;	//这样p才指向第i-1个节点（如果有的话）
	temp = (LinkList)malloc(sizeof(LNode));
	temp -> data = b;
	temp -> next = p -> next;
	p -> next = temp;
	return OK;
}
/**
 * 分析：虽然两种链表的插入操作的时间复杂度是一样的(O(i))。
 * 	 但是可以非常容易的看出带头结点的情况下需要考虑的东西要比不带头结点的少很多！！！，而且代码看起来也更加通俗易懂。
 * 	 所以记得写任何链表(包括循环链表)最好都加头结点
 */
