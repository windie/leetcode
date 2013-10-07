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
    	if(head==NULL){
    		return NULL;
    	}
    	ListNode * cur = head;
    	ListNode * pre = NULL;
    	while(cur!=NULL){
        	ListNode * first= cur;
        	ListNode * second = NULL;
        	ListNode * third = NULL;
        	if(cur->next!=NULL){
        		second = cur->next;
        	}else{
        		break;
        	}
        	third = second->next;
        	second->next = first;
        	first->next = third;
        	if(cur==head){
        		head = second;
        	}else{
        		pre->next = second;
        	}
        	pre = first;
        	cur = third;
    	}
    	return head;
    }
};
