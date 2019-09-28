#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* reverseKGroup(struct ListNode* head, int k){
	if (head == NULL || head->next == NULL) {
		return head;
	}
	//����һ����ʱͷ�ڵ㣬��������ͷ�ڵ���Ҫ���ִ���
	struct ListNode *point = (struct ListNode *)malloc(sizeof(struct ListNode));
	struct ListNode *tmphead = head;
	point->next = head;
	head = point;


	//��ȡ����ڵ�����
	int cnt = 0;
	while (tmphead != NULL) {
		cnt++;
		tmphead = tmphead->next;
	}

	int i;
	struct ListNode *prev, *now, *tmp;
	while (point != NULL) {
		//�ж�ʣ�µĽڵ������Ƿ��㹻
		if (cnt < k) {
			break;
		}

		//ָ��K���ڵ���ת
		tmphead = NULL;
		prev = point->next;
		now = point->next->next;
		for (i = 0; i<k; i++) {
			prev->next = tmphead;
			tmphead = prev;
			prev = now;

			if (now != NULL) {
				now = now->next;
			}
		}
		//������prevָ��ָ���K+1���ڵ��NULL

		//�����²��ֽڵ㣺ԭ��1���ڵ㣬�ֵ�K���ڵ㣬ָ���K+1���ڵ��NULL
		point->next->next = prev;

		//�ݴ��K���ڵ㣨β�ڵ㣩
		tmp = point->next;

		//�����ϲ��ֽڵ㣬��һ�β���ʱheadָ���Ӧ��ʱ�ڵ�ĺ�̽ڵ�Ϊ�����ͷ�ڵ�
		point->next = tmphead;

		//pointָ��ָ���K���ڵ㣬��Ϊ��һ��K���ڵ����ʱǰ�̽ڵ�
		point = tmp;

		//���¼�����õ�ʣ��ڵ�����
		cnt = cnt - k;
	}
	//�ͷ���ʱ�ڵ�
	tmp = head;
	head = head->next;
	free(tmp);
	return head;
}

