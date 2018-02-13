/** (测试代码在./t_NoHeadLinkList.c文件中)
 * 2.18 试写一算法，在无头结点的动态单链表上实现线性表操作DELETE(L, i)，并和在带头结点的动态单链表上实现相同操作的算法进行比较。
 */
Status hw_2_18(LinkList *L,int i){
	LinkList temp,prior;
	int j;
	if(!(*L) && i < 1 && i > ListLength_L(*L)) exit(OVERFLOW);
	if(i == 1){
		temp = (*L);
		(*L) = (*L) -> next;
		free(temp);
		return OK;
	}
	temp = (*L);
	j = 1;
	while(temp && j<i){
		prior = temp;
		temp = temp -> next;
		j++;
	}
	prior -> next = temp -> next;
	free(temp);
	return OK;
}
