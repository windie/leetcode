class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        ListNode *cur = head, *next = head->next;
        while(next){
            if(cur->val == next->val){
                next = next->next;
            }else{
                cur->next = next;
                cur = next;
                next = next->next;
            }
        }
        cur->next = NULL;
        return head;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    ListNode *deleteDuplicates(ListNode *head) {
//    	if(head==NULL) return NULL;
//    	ListNode *tmp = head;
//    	while(tmp->next != NULL){
//    		if(tmp->next->val == tmp->val){
//    			tmp->next = tmp->next->next;
//    		}else{
//    			tmp = tmp->next;
//    		}
//    	}
//    	return head;
//    }
//};
