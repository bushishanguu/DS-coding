#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	//进位标志、当前和
	int flag = 0, nodeSum = 0;
	//L1头、当前指针、L2头
	struct ListNode *ret, *now, *high;

	// L1有 || L2有 || 进位  
	for (ret = l1, now = l1, high = l2; l1 || l2 || flag;) {
		//如果后半部分使用L2空间不足 继续使用L2头节点的空间
		if (l1 == NULL && l2 == NULL) {
			now->next = high;
			now = now->next;
		}

		//做加法
		nodeSum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + flag;
		now->val = nodeSum % 10;
		flag = nodeSum / 10;

		//l1、l2指针后移
		l1 ? l1 = (l1->next ? l1->next : NULL) : NULL;
		l2 ? l2 = (l2->next ? l2->next : NULL) : NULL;

		//如果l1存在，继续沿用L1的空间 如果L1结束了，沿用l2的空间
		now->next = (l1 ? l1 : (l2 ? l2 : NULL));
		//now后移
		now->next ? now = now->next : NULL;
	}
	return ret;
}
