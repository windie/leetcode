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
    ListNode *partition(ListNode *head, int x) {
        ListNode * lesshead = NULL, *lessnext = NULL;
        ListNode * largerhead = NULL, *largernext = NULL;
        ListNode *p = head;
        while(p!=NULL){
            if(p->val <x){
                if(lesshead == NULL){
                    lesshead = p;
                    lessnext = p;
                }else{
                    lessnext->next = p;
                    lessnext = p;
                }
            }else{
                if(largerhead == NULL){
                    largerhead = p;
                    largernext = p;
                }else{
                    largernext->next = p;
                    largernext = p;
                }
            }
            p = p->next;
        }
        if(largerhead != NULL){
            largernext->next = NULL;
        }
        if(lesshead != NULL){
            lessnext->next = largerhead;
            return lesshead;
        }else{
            return largerhead;
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
//    ListNode *partition(ListNode *head, int x) {
//    	if(head==NULL){
//    		return NULL;
//    	}
//    	ListNode *pnode = head;
//    	ListNode *pless = NULL, *plarger = NULL;
//    	ListNode *plesspos = NULL, *plargerpos = NULL;
//    	while(pnode != NULL){
//    		if(pnode->val < x){
//    			if(pless==NULL){
//    				pless = pnode;
//    				plesspos = pless;
//    			}else{
//    				plesspos->next = pnode;
//    				plesspos = plesspos->next;
//    			}
//    		}else{
//    			if(plarger==NULL){
//    				plarger = pnode;
//    				plargerpos = plarger;
//    			}else{
//    				plargerpos->next = pnode;
//    				plargerpos = plargerpos->next;
//    			}
//    		}
//    		pnode = pnode->next;
//    	}
//    	if(plesspos == NULL){
//    		return plarger;
//    	}else{
//    		if(plargerpos != NULL){
//        		plargerpos->next = NULL;
//    		}
//    		plesspos->next = plarger;
//    		return pless;
//    	}
//    }
//};
