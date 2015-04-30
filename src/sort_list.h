/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode * res = NULL, *tail = NULL;
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }
        ListNode *p1 = head1, *p2 = head2;
        while(p1 && p2){
            if(p1->val < p2->val){
                if(res == NULL){
                    res = p1;
                    tail = p1;
                }else{
                    tail->next = p1;
                    tail = tail->next;
                }
                p1 = p1->next;
            }else{
                if(res == NULL){
                    res = p2;
                    tail = p2;
                }else{
                    tail->next = p2;
                    tail = tail->next;
                }
                p2 = p2->next;
            }
        }
        if(tail == NULL){
            return NULL;
        }
        if(p1){
            tail->next = p1;
        }else if(p2){
            tail->next = p2;
        }else{
            tail->next = NULL;
        }
        return res;
    }
    ListNode* sort(ListNode* head, int len, ListNode *&tail){
        if(len <=0){
            return NULL;
        }
        if(len == 1){
            tail = head->next;
            head->next = NULL;
            return head;
        }
        ListNode *left = sort(head, len/2, tail);
        ListNode *right = sort(tail, len - len/2, tail);
        return merge(left, right);
    }
    int len(ListNode *head){
        ListNode *p = head;
        int res = 0;
        while(p){
            res++;
            p = p->next;
        }
        return res;
    }
public:
    ListNode* sortList(ListNode* head) {
        int lenth = len(head);
        ListNode *tail = NULL;
        return sort(head, lenth, tail);
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
