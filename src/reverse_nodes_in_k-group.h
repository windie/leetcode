/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int len(ListNode *head){
        int len = 0;
        ListNode *p = head;
        while(p){
            len++;
            p = p->next;
        }
        return len;
    }
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL || k == 1){
            return head;
        }
        int seg = len(head)/k;
        if(seg == 0){
            return head;
        }
        ListNode *p = head;
        ListNode *res = NULL, *tail = NULL;
        for(int i = 0; i<seg; i++){
            ListNode * segres = NULL, *segtail = NULL;
            for(int j = 0; j<k && p != NULL; j++){
                ListNode *next = p->next;
                if(segres == NULL){
                    segres = p;
                    segtail = p;
                }else{
                    p->next=segres;
                    segres = p;
                }
                p = next;
            }
            if(res == NULL){
                res = segres;
                tail = segtail;
            }else{
                tail->next = segres;
                tail = segtail;
            }
        }
        if(tail){
            tail->next = p;
        }
        return res;
    }
};

///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
//class Solution {
//	void reverse(ListNode **head, ListNode **end) {
//		ListNode *cur = *head, *next = NULL;
//		while (cur != NULL) {
//			next = cur->next;
//			if (cur == *head) {
//				cur->next = NULL;
//				*end = cur;
//			} else {
//				cur->next = *head;
//			}
//			*head = cur;
//			cur = next;
//		}
//	}
//	ListNode *reverseRecursive(ListNode *head, int k, ListNode **res) {
//		if (head == NULL || k == 1) {
//			if (*res == NULL) {
//				*res = head;
//			}
//			return head;
//		}
//		ListNode *subhead = head, *subtail = NULL, *cur = head, *next = NULL;
//		int cnt = 1;
//		// 1. find start and end
//		while (cur != NULL && cnt < k) {
//			cur = cur->next;
//			cnt++;
//		}
//		// 2. if start and end are legal: reverse them
//		if (cur != NULL && cnt == k) {
//			next = cur->next;
//			cur->next = NULL;
//			reverse(&subhead, &subtail);
//			if (*res == NULL) {
//				*res = subhead;
//			}
//			if (subtail != NULL) {
//				subtail->next = reverseRecursive(next, k, res);
//			}
//			return subhead;
//		}
//		// 3. if start and end are illegal: return the current list
//		if (*res == NULL) {
//			*res = head;
//		}
//		return head;
//	}
//
//public:
//	ListNode *reverseKGroup(ListNode *head, int k) {
//		ListNode *res = NULL;
//		reverseRecursive(head, k, &res);
//		return res;
//	}
//};
