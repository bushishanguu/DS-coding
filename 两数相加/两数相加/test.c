#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	//��λ��־����ǰ��
	int flag = 0, nodeSum = 0;
	//L1ͷ����ǰָ�롢L2ͷ
	struct ListNode *ret, *now, *high;

	// L1�� || L2�� || ��λ  
	for (ret = l1, now = l1, high = l2; l1 || l2 || flag;) {
		//�����벿��ʹ��L2�ռ䲻�� ����ʹ��L2ͷ�ڵ�Ŀռ�
		if (l1 == NULL && l2 == NULL) {
			now->next = high;
			now = now->next;
		}

		//���ӷ�
		nodeSum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + flag;
		now->val = nodeSum % 10;
		flag = nodeSum / 10;

		//l1��l2ָ�����
		l1 ? l1 = (l1->next ? l1->next : NULL) : NULL;
		l2 ? l2 = (l2->next ? l2->next : NULL) : NULL;

		//���l1���ڣ���������L1�Ŀռ� ���L1�����ˣ�����l2�Ŀռ�
		now->next = (l1 ? l1 : (l2 ? l2 : NULL));
		//now����
		now->next ? now = now->next : NULL;
	}
	return ret;
}
