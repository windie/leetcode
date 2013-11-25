/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
	ListNode * merge(ListNode *l1, ListNode* l2) {
		ListNode *p1 = l1, *p2 = l2;
		ListNode *res = NULL, *p = NULL;
		while (p1 && p2) {
			ListNode * p1next = p1->next;
			ListNode * p2next = p2->next;
			if (res == NULL) {
				res = p1;
				res->next = p2;
				p = res->next;
			} else {
				p->next = p1;
				p->next->next = p2;
				p = p->next->next;
			}
			p1 = p1next;
			p2 = p2next;
		}
		if (p1) {
			p->next = p1;
		}
		return res;
	}
	ListNode * reverse(ListNode *head) {
		ListNode *p = head, *res = NULL;
		while (p) {
			ListNode* next = p->next;
			p->next = res;
			res = p;
			p = next;
		}
		return res;
	}
	ListNode * partition(ListNode *first) {
		ListNode *second = NULL;
		ListNode *slow = first, *fast = first;
		ListNode *pre = NULL;
		while (fast != NULL && fast->next != NULL) {
			pre = slow;
			fast = fast->next->next;
			slow = slow->next;
		}
		if (fast == NULL) {
			second = slow;
			pre->next = NULL;
		} else {
			second = slow->next;
			slow->next = NULL;
		}
		return second;
	}
public:
	void reorderList(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return;
		}
		ListNode *second = partition(head);
		second = reverse(second);
		head = merge(head, second);
	}
};
