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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
    	if(head==NULL){
    		return NULL;
    	}
    	ListNode *cur = head;
    	ListNode *connection1_left = NULL, *connection1_right = NULL;
    	int i=1;
    	while(i<m){
    		connection1_left = cur;
    		cur = cur->next;
    		i++;
    	}
    	if(i==n){
    		return head;
    	}
    	ListNode *pre = cur;
    	connection1_right = cur;
    	cur = cur->next;
    	ListNode *next = NULL;
    	while(i<n){
    		next = cur->next;
    		cur->next = pre;
    		pre = cur;
    		cur = next;
    		i++;
    	}
    	connection1_right->next = next;
    	if(connection1_left==NULL){
    		return pre;
    	}
    	connection1_left->next = pre;
    	return head;
    }
};
