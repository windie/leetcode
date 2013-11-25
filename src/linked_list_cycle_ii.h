#include<iostream>

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *pfast = head, *pslow = head;
		while (pfast != NULL && pfast->next != NULL) {
			pfast = pfast->next->next;
			pslow = pslow->next;
			if (pfast == pslow) {
				break;
			}
		}
		if (pfast == NULL || pfast->next == NULL) {
			return NULL;
		}
		pfast = head;
		while (pfast != pslow) {
			pfast = pfast->next;
			pslow = pslow->next;
		}
		return pfast;
	}
};
