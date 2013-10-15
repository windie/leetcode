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
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == NULL) {
			return NULL;
		}
		ListNode *res = NULL, *cur = head, *tail = NULL;
		while (cur) {
			if (cur->next) {
				if (cur->val != cur->next->val) {
					if (res == NULL) {
						res = cur;
						tail = cur;
					} else {
						tail->next = cur;
						tail = cur;
					}
					cur = cur->next;
				} else {
					ListNode *p = cur->next;
					while (p && p->val == cur->val) {
						p = p->next;
					}
					cur = p;
				}
			} else {
				if (res == NULL) {
					res = cur;
					tail = cur;
				} else {
					tail->next = cur;
					tail = cur;
				}
				cur = cur->next;
			}
		}
		if(tail){
		    tail->next = NULL;
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
//private:
//	ListNode *getHead(ListNode *head){
//		ListNode* tmp = head;
//		if(tmp==NULL) return NULL;
//		ListNode* nxt = tmp->next;
//		if(nxt==NULL) return tmp;
//		if(tmp->val != nxt->val){
//			return tmp;
//		}else{
//			while(nxt != NULL && tmp->val == nxt->val){
//				nxt = nxt->next;
//			}
//			return nxt;
//		}
//	}
//public:
//    ListNode *deleteDuplicates(ListNode *head) {
//    	ListNode *pre = getHead(head);
//    	if(pre == NULL) return NULL;
//    	ListNode *cur = pre->next;
//    	if(cur == NULL) return pre;
//
//    	while(pre->val == cur->val){
//    		pre = getHead(pre);
//    		if(pre == NULL) return NULL;
//    		cur = pre->next;
//    		if(cur == NULL) return pre;
//    	}
//    	head=pre;
//
//    	while(cur != NULL){
//    		if(cur->next == NULL || cur->val != cur->next->val){
//    			pre = cur;
//    			cur = cur->next;
//    		}else{
//    			ListNode *pos = cur->next;
//    			while(pos!=NULL && cur->val == pos->val){
//    				pos = pos->next;
//    			}
//    			if(pos != NULL){
//					pre->next = pos;
//					cur=pos;
//    			}else{
//    				pre->next = NULL;
//    				cur = NULL;
//    			}
//    		}
//    	}
//    	return head;
//    }
//};
