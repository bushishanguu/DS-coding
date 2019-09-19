#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* removeElements(struct ListNode* head, int val){
	if (head == NULL)
		return head;
	struct ListNode* p = head, *q = head->next;

	while (q != NULL)
	{
		if (q->val == val)
		{
			p->next = q->next;
			q = q->next;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}


	if (head->val == val)
	{
		head = head->next;
	}
	return head;
}

