/**(测试代码在./t_NoHeadLinkList.c文件中)
 *
 *
 * 2.16❸已知指针la和lb分别指向两个无头结点单链表中的首元结点。下列算法是从表la中删除自第i个元素起共len个元素后(按代码中的意思这个句话的理解是范围为[i,len),而不是我们一般认为的[i,i+len),但是答案中给的范围是后者)，将它们插入到表lb中的第j个元素之前。试问此算法是否正确？如有错，则请改正之。
 * Status DeleteAndInsertSub(LinkedList la,LinkedList lb,int i,int j,int len){
 *	if(i < 0 || j < 0 || len < 0) exit(OVERFLOW);
 *	p = la;k =1;
 *	while(k < i) {p = p -> next;k++;}
 *	q = p ;				//这边如果再加上一句 k = 1 那么操作的范围就是[i,i+len)
 *	while(k <=len) { q = q -> next; k++;}
 *	s = lb; k =1;
 *	while(k < j){s = s->next;k++;}
 *	s -> next = p; q -> next = s -> next;
 *	return OK;
 * }//DeleteAndInsertSub
 */

/**
 * 有三个很明显的错误：
 * 	1. 题中说的是无头节点的单链表，所以应该考虑首元结点的特殊情况
 * 	2. 删除插入操作明显是错的（写的毫无道理）
 * 	3. 考虑各种条件是否有效不周全(
 * 		A:la,lb是否为空指针,
 * 		B:0<i<=i+len<=ListLength_L(la),
 * 		C:0<j<=ListLength_L(lb),
 * 		D:len为0.
 * 		)
 */
//改进(实际需要，所以代码可能有不同，但是思路满足题意)：
Status DeleteAndInsertSub(LinkList *la,LinkList *lb,int i,int j,int len){
	if(!(*la) || !(*lb) || i<0 || j<0 || len<0 || i+len > ListLength_L(*la) || j > ListLength_L(*lb)) exit(OVERFLOW);	//f分析三中ABC的情况
	if(len == 0) return OK;		//分析三中的D情况

	LinkList p,q,prior,s,temp;
	int k;	
	p = (*la);k = 1;
	while(k < i) {prior = p;p = p -> next;k++;}	
	if(i != 1){
		q = p = prior;	//当i为1时，prior为NULL，所以如果没有这个条件的话那就GG了
		k = 1;
		while(q && k<=len){q = q -> next;k++;}
	}else{
		q = (*la);
		k = 1;
		while(q && k<len){q = q -> next;k++;}
	}
	
	s = (*lb); k =1;
	while(k < j){ prior = s;s = s->next;k++;} 	
	s = prior;
	/**到这，p指向的是la的第i-1个节点，p -> next就是要删除的第一个节点
	 *	q指向的是la的第i+len-1个节点，该节点是要删除的最后一个节点
	 *	也就是说，要想执行完删除操作后la表还链起来，需要 p -> next = q -> next这句话。
	 *
	 *	s指向的是lb的第j-1个节点，s -> next就是要插入的起始位置，也就是需要执行 q -> next = s -> next;s -> next = p -> next(还没有更改时候的 p -> next);
	 *	所以连起来，删除插入操作就是：
	 *	temp = p -> next;
	 *	p -> next = q -> next;
	 *	q -> next = s -> next;
	 *	s -> next = temp;
	 *
	 *	并且需要满足 i-1 > 0 和 j-1 > 0这两个条件；也就是会产生四种情况
	 */
	if(i == 1 && j == 1){
		temp = (*la);
		(*la) = q -> next;		//la删除操作完成

		q -> next = (*lb);
		(*lb) = temp;		//lb添加操作完成
	}else if (i == 1 && j !=1){
		temp = (*la);
		(*la) = q -> next;	
	
		q -> next = s -> next;
		s -> next = temp;
	}else if (i != 1 && j == 1){
		temp = p -> next;
		p -> next = q -> next;

		q -> next = (*lb);
		(*lb) = temp;
	}else{
	 	temp = p -> next;
	 	p -> next = q -> next;
	 	q -> next = s -> next;
	 	s -> next = temp;
	}
	return OK;
}
