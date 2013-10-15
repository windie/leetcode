#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void reverse(ListNode * head, ListNode *tail){
        ListNode* cur = head, *pre = NULL, *restail = NULL;
        while(cur != tail){
            if(pre==NULL){
                pre = cur;
                restail = cur;
                cur = cur->next;
            }else{
                ListNode *next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
        }
        cur->next = pre;
        head = cur;
        tail = restail;
        tail->next = NULL;
    }
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head == NULL || m==n){
            return head;
        }
        int n1 = m-1, n2 = m, n3=n, n4 = n+1;
        ListNode *r1 = NULL, *r2 =NULL, *r3 = NULL, *r4 = NULL;
        ListNode *p = head;
        int i = 1;
        while(p){
            if(i==n1){
                r1 = p;
            }else if(i==n2){
                r2=p;
            }else if(i==n3){
                r3= p;
            }else if(i == n4){
                r4 = p;
                break;
            }
            p = p->next;
            i++;
        }
        reverse(r2, r3);
        if(r1 == NULL && r4 == NULL){
            return r2;
        }else if(r1 == NULL){
            r3->next = r4;
            return r2;
        }else if(r4 == NULL){
            r1->next = r2;
            return head;
        }else{
            r1->next = r2;
            r3->next = r4;
            return head;
        }
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
//    ListNode *reverseBetween(ListNode *head, int m, int n) {
//    	if(head==NULL){
//    		return NULL;
//    	}
//    	ListNode *cur = head;
//    	ListNode *connection1_left = NULL, *connection1_right = NULL;
//    	int i=1;
//    	while(i<m){
//    		connection1_left = cur;
//    		cur = cur->next;
//    		i++;
//    	}
//    	if(i==n){
//    		return head;
//    	}
//    	ListNode *pre = cur;
//    	connection1_right = cur;
//    	cur = cur->next;
//    	ListNode *next = NULL;
//    	while(i<n){
//    		next = cur->next;
//    		cur->next = pre;
//    		pre = cur;
//    		cur = next;
//    		i++;
//    	}
//    	connection1_right->next = next;
//    	if(connection1_left==NULL){
//    		return pre;
//    	}
//    	connection1_left->next = pre;
//    	return head;
//    }
//};
