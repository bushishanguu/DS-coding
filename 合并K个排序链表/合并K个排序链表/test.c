#define _CRT_SECURE_NO_WARNINGS 1
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode* mergeKListsSub(struct ListNode** lists, int listsSize){
	struct ListNode* temp = NULL;
	int val = INT_MAX;
	int pos = -1;
	int i;

	for (i = 0; i < listsSize; i++){
		if (lists[i]){
			if (val > lists[i]->val){
				val = lists[i]->val;
				pos = i;
			}
		}
	}

	if (pos != -1){
		temp = lists[pos];
		//printf("found min %d @ %d\n",lists[pos]->val,pos);
		lists[pos] = lists[pos]->next;
		temp->next = mergeKListsSub(lists, listsSize);
	}

	return temp;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
	return mergeKListsSub(lists, listsSize);
}


