#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* reverseKGroup(struct ListNode* head, int k){
	int i;
	//判断剩下的节点数量是否足够
	struct ListNode *tmp = head->next;
	for (i = 0; i<k - 2; i++) {
		tmp = tmp->next;
		if (tmp == NULL) {
			return head;
		}
	}

	//翻转K个节点
	struct ListNode *prev = NULL;
	struct ListNode *now = head;
	struct ListNode *next = head->next;
	for (i = 0; i<k; i++) {
		now->next = prev;
		prev = now;
		now = next;

		if (next != NULL) {
			next = next->next;
		}
	}
	//K+1作为新的头节点，递归处理
	head->next = reverseKGroup(now, k);
	return prev;
}

