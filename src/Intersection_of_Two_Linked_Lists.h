/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int len(ListNode * head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* moveforward(ListNode *head, int steps){
        ListNode *p = head;
        for(int i = 0; i< steps && p != NULL; i++){
            p = p->next;
        }
        return p;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = len(headA);
        int lb = len(headB);
        ListNode *pa = headA, *pb = headB;
        if(la > lb){
            pa = moveforward(headA, la-lb);
        }else{
            pb = moveforward(headB, lb-la);
        }
        if(pa == NULL || pb == NULL){
            return NULL;
        }
        while(pa != NULL && pb != NULL && pa != pb){
            pa = pa->next;
            pb = pb->next;
        }
        if(pa == NULL || pb == NULL){
            return NULL;
        }else{
            return pa;
        }
    }
};