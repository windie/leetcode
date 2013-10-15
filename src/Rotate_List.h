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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* p = head, *tail = NULL;
        int len = 0;
        while(p){
            len ++;
            tail = p;
            p = p->next;
        }
        k = k%len;
        if(k==0){
            return head;
        }
        int step = len - k, i = 1;
        p = head;
        while(i<step){
            p = p->next;
            i++;
        }
        ListNode * res = p->next;
        tail->next = head;
        p->next = NULL;
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
//	int length_of_list(ListNode *head){
//		if(head == NULL) {
//			return 0;
//		}
//		int len = 1;
//		ListNode *tmp = head;
//		while(tmp->next != NULL){
//			len++;
//			tmp = tmp->next;
//		}
//		return len;
//	}
//public:
//    ListNode *rotateRight(ListNode *head, int k) {
//    	int len = length_of_list(head);
//    	if(len < 2){
//    		return head;
//    	}
//    	k %= len;
//    	int l = len - k;
//    	if(k==0 || l==0){
//    		return head;
//    	}
//
//    	ListNode *tmp = head;
//    	for(int i=1; i<l; i++){
//    		tmp = tmp->next;
//    	}
//    	ListNode *begin = tmp->next;
//    	ListNode *end = begin;
//    	tmp->next = NULL;
//    	while(end->next != NULL){
//    		end = end->next;
//    	}
//    	end->next = head;
//    	return begin;
//    }
//};
