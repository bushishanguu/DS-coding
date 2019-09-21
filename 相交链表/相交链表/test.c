#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL || headB == NULL){
		return NULL;
	}
	struct ListNode* temp_A = headA;
	struct ListNode* temp_B = headB;

	int count = 0;//¼ÆÊý
	while (temp_A != temp_B){
		if (temp_A->next == NULL){
			temp_A = headB;
		}
		else{
			temp_A = temp_A->next;
		}
		if (temp_B->next == NULL){
			if (++count == 2){
				return NULL;
			}
			temp_B = headA;
		}
		else{
			temp_B = temp_B->next;
		}
	}
	return temp_B;
}

