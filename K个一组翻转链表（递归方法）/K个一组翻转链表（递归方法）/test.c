#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* reverseKGroup(struct ListNode* head, int k){
	int i;
	//�ж�ʣ�µĽڵ������Ƿ��㹻
	struct ListNode *tmp = head->next;
	for (i = 0; i<k - 2; i++) {
		tmp = tmp->next;
		if (tmp == NULL) {
			return head;
		}
	}

	//��תK���ڵ�
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
	//K+1��Ϊ�µ�ͷ�ڵ㣬�ݹ鴦��
	head->next = reverseKGroup(now, k);
	return prev;
}

