class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next == NULL){
            return NULL;
        }
        ListNode *slow = head, *fast = head->next->next;
        while(slow != NULL && fast != NULL){
            if(slow == fast){
                break;
            }
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL){
                break;
            }
            fast = fast->next;
        }
        if(fast == NULL || fast->next == NULL){
            return NULL;
        }
        slow = head;
        while(slow != fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};

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
