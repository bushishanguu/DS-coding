/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	//��С�Ľڵ���뵽�µ������У�ֱ��ĳ������Ϊ��Ϊֹ
	//��Ϊ�յ�����Ľڵ�ֱ�ӱ���ʣ��ڵ㣬���뵽��������
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	struct ListNode* head = NULL;
	int index = 1;
	struct ListNode* beforeNode = NULL;
	while (l1 != NULL&&l2 != NULL)
	{
		if (l1->val <= l2->val)
		{
			if (index == 1)
			{
				head = l1;
				index++;
			}
			if (beforeNode != NULL)
			{
				beforeNode->next = l1;
			}
			beforeNode = l1;
			l1 = l1->next;
		}
		else
		{
			if (index == 1)
			{
				head = l2;
				index++;
			}
			if (beforeNode != NULL)
			{
				beforeNode->next = l2;
			}
			beforeNode = l2;
			l2 = l2->next;
		}
	}
	if (l1 != NULL)
	{
		beforeNode->next = l1;
	}
	if (l2 != NULL)
	{
		beforeNode->next = l2;
	}
	return head;

}

