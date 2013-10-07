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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) {
			return l2;
		} else if (l2 == NULL) {
			return l1;
		}
		ListNode * i1 = l1, *i2 = l2;
		ListNode *pre = NULL, *head = NULL;
		while (i1 != NULL && i2 != NULL) {
			if (i1->val <= i2->val) {
				if(head==NULL){
					head = i1;
				}
				pre = i1;
				i1 = i1->next;
			} else {
				if(head==NULL){
					head = i2;
				}
				if(pre!=NULL){
					pre->next = i2;
				}
				pre = i2;
				ListNode *tmp = i2->next;
				i2->next = i1;
				i2 = tmp;
			}
		}
		if(i2 != NULL){
			pre->next = i2;
		}
		return head;
	}
};
