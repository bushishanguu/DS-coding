#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *detectCycle(struct ListNode *head) {
	if (head == NULL || head->next == NULL){
		return NULL;
	}
	struct ListNode* slowNode = head;
	struct ListNode* fastNode = head;

	while (fastNode != NULL&&fastNode->next != NULL){
		slowNode = slowNode->next;
		fastNode = fastNode->next->next;
		if (slowNode == fastNode){
			break;
		}
	}
	if (slowNode != fastNode)
	{
		return NULL;
	}
	fastNode = head;
	while (fastNode != slowNode){
		slowNode = slowNode->next;
		fastNode = fastNode->next;
	}
	return slowNode;

}