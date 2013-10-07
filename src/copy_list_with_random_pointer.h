/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
	void copy(RandomListNode *head) {
		RandomListNode *p = head;
		RandomListNode *tail = NULL;
		while (p) {
			RandomListNode *next = p->next;
			RandomListNode *tmp = new RandomListNode(p->label);
			p->next = tmp;
			if (tail != NULL) {
				tail->next = p;
			}
			tail = tmp;
			p = next;
		}
	}
	void random(RandomListNode *head) {
		RandomListNode *p = head;
		while (p) {
			if (p->random) {
				p->next->random = p->random->next;
			}
			p = p->next->next;
		}
	}
	RandomListNode *seperate(RandomListNode *head) {
		if (head == NULL) {
			return NULL;
		}
		RandomListNode *res = head->next;
		RandomListNode *p = head, *q = head->next;
		while (p && q) {
			p->next = p->next->next;
			p = p->next;
			if (q->next) {
				q->next = q->next->next;
			}
			q = q->next;
		}
		return res;
	}
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL) {
			return NULL;
		}
		copy(head);
		random(head);
		return seperate(head);
	}
};
