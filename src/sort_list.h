/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void rec(ListNode *& begin, ListNode *& end){
        if(begin == NULL){
            end = NULL;
            return;
        }
        if(begin == end){
            end->next = NULL;
            return;
        }
        ListNode * p = begin->next, *pre = p;
        ListNode *b1 = NULL, *e1 = NULL, *b2 = NULL, *e2 = NULL;
        while(p && pre != end){
            if(p->val > begin->val){
                if(b2==NULL){
                    b2 = p;
                    e2 = p;
                }else{
                    e2->next = p;
                    e2 = p;
                }
            }else{
                if(b1==NULL){
                    b1 = p;
                    e1 = p;
                }else{
                    e1->next = p;
                    e1 = p;
                }
            }
            pre = p;
            p = p->next;
        }
        if(e1){
            e1->next = NULL;
        }
        if(e2){
            e2->next = NULL;
        }
        rec(b1, e1);
        rec(b2, e2);
        if(e1){
            e1->next = begin;
            begin = b1;
        }
        begin->next = b2;
        if(e2){
            end = e2;
        }else{
            end = begin;
        }
        end->next = NULL;
    }
public:
    ListNode *sortList(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        ListNode * p = head, *tail = head, *begin = head;
        while(p){
            tail = p;
            p = p->next;
        }
        rec(begin, tail);
        return begin;
    }
};

///**
//* Definition for singly-linked list.
//* struct ListNode {
//*     int val;
//*     ListNode *next;
//*     ListNode(int x) : val(x), next(NULL) {}
//* };
//*/
//class Solution {
//	ListNode *merge(ListNode* l1, ListNode*l2) {
//	    if(l1==NULL){
//	        return l2;
//	    }else if(l2==NULL){
//	        return l1;
//	    }
//		ListNode*p1 = l1, *p2 = l2;
//		ListNode dummy(0);
//		ListNode *tail = &dummy;
//		while (p1 && p2) {
//			if (p1->val < p2->val) {
//				tail->next = p1;
//				p1 = p1->next;
//			} else {
//				tail->next = p2;
//				p2 = p2->next;
//			}
//			tail = tail->next;
//		}
//		if (p1) {
//			tail->next = p1;
//		} else if (p2) {
//			tail->next = p2;
//		}
//		return dummy.next;
//	}
//	ListNode *sortList(ListNode *head, int begin, int end, ListNode*&tail) {
//		if (begin == end) {
//			tail = head;
//			return NULL;
//		}
//		if (end - begin == 1) {
//			tail = head->next;
//			head->next = NULL;
//			return head;
//		}
//		int mid = begin + (end - begin) / 2;
//		ListNode * first = sortList(head, begin, mid, tail);
//		ListNode * second = sortList(tail, mid, end, tail);
//		return merge(first, second);
//	}
//	int length(ListNode *head) {
//		int n=0;
//		while(head){
//			n++;
//			head= head->next;
//		}
//		return n;
//	}
//public:
//	ListNode *sortList(ListNode *head) {
//		ListNode *tail;
//		return sortList(head, 0, length(head), tail);
//	}
//};
