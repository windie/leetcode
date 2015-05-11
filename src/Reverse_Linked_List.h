/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* rec(ListNode * head, ListNode * cur){
        if(head == NULL){
            return cur;
        }else{
            ListNode * tmp = new ListNode(head->val);
            tmp->next = cur;
            return rec(head->next, tmp);
        }
    }
public:
    ListNode* reverseList(ListNode* head) {
        return rec(head, NULL);
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* res = NULL;
        ListNode* p = head;
        while(p){
            ListNode *next = p->next;
            if(res == NULL){
                res = p;
                res->next = NULL;
            }else{
                p->next = res;
                res = p;
            }
            p = next;
        }
        return res;
    }
};