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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(n == 0){
            return head;
        }
        ListNode *fast = head, *slow = head;
        int i = 0;
        for(i = 0; i<=n && fast != NULL; i++){
            fast = fast->next;
        }
        if(fast == NULL && i<n+1){
            return head->next;
        }
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(slow->next != NULL){
            slow->next = slow->next->next;
        }else{
            slow->next = NULL;
        }
        return head;
    }
};

//class Solution {
//public:
//    ListNode *removeNthFromEnd(ListNode *head, int n) {
//        if(head == NULL){
//            return NULL;
//        }
//        ListNode *fast = head;
//        for(int i = 0; i<n; i++){
//            if(fast){
//                fast = fast->next;
//            }
//        }
//        if(fast == NULL){
//            return head->next;
//        }
//        ListNode *slow=head;
//        while(fast && fast->next){
//            slow = slow->next;
//            fast = fast->next;
//        }
//        if(slow->next){
//            slow->next = slow->next->next;
//        }else{
//            slow->next = NULL;
//        }
//        return head;
//    }
//};

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
//    ListNode *removeNthFromEnd(ListNode *head, int n) {
//    	if(head == NULL){
//    		return NULL;
//    	}
//    	ListNode *pre = NULL, *first = head, *second = head;
//    	int i=1;
//    	while(i<n){
//    		second = second->next;
//    		i++;
//    	}
//    	while(second->next != NULL){
//    		pre = first;
//    		first = first->next;
//    		second = second->next;
//    	}
//    	if(pre == NULL){
//    		head = head->next;
//    	}else{
//    		pre->next = first->next;
//    	}
//    	return head;
//    }
//};
