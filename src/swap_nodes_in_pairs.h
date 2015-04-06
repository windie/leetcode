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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *res = NULL, *tail = NULL;
        ListNode *p1 = head, *p2 = NULL, *p3 = NULL;
        while(p1!=NULL){
            p2 = p1->next;
            if(p2 == NULL){
                tail->next = p1;
                break;
            }
            p3 = p2->next;
            p2->next = p1;
            p1->next = p3;
            if(res == NULL){
                res = p2;
                tail = p1;
            }else{
                tail->next = p2;
                tail = p1;
            }
            p1 = p3;
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
//public:
//    ListNode *swapPairs(ListNode *head) {
//    	if(head==NULL){
//    		return NULL;
//    	}
//    	ListNode * cur = head;
//    	ListNode * pre = NULL;
//    	while(cur!=NULL){
//        	ListNode * first= cur;
//        	ListNode * second = NULL;
//        	ListNode * third = NULL;
//        	if(cur->next!=NULL){
//        		second = cur->next;
//        	}else{
//        		break;
//        	}
//        	third = second->next;
//        	second->next = first;
//        	first->next = third;
//        	if(cur==head){
//        		head = second;
//        	}else{
//        		pre->next = second;
//        	}
//        	pre = first;
//        	cur = third;
//    	}
//    	return head;
//    }
//};
