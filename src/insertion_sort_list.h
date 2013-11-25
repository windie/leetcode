/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if (head == NULL) {
			return NULL;
		}
		ListNode *cur = head->next;
		head->next = NULL;
		while (cur) {
			ListNode * p = head;
			ListNode * pre = NULL;
			while (p && p->val < cur->val) {
				pre = p;
				p = p->next;
			}
			ListNode * next = cur->next;
			if (pre == NULL) {
				cur->next = head;
				head = cur;
			} else {
			    cur->next = p;
			    pre->next = cur;
			}
			cur = next;
		}
		return head;
	}
};
