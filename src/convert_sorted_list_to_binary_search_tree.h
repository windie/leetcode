/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode *rec(ListNode *head, ListNode *&tail, int begin, int end){
        if(begin == end){
            tail = head;
            return NULL;
        }
        int mid = begin + (end-begin)/2;
        TreeNode *left = rec(head, tail, begin, mid);
        TreeNode *midnode = new TreeNode(tail->val);
        TreeNode *right = rec(tail->next, tail, mid+1, end);
        midnode->left = left;
        midnode->right = right;
        return midnode;
    }
    int len(ListNode *head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode * tail = NULL;
        return rec(head, tail, 0, len(head));
    }
};

//#include<iostream>
//using namespace std;
///**
// * Definition for singly-linked list.
// * struct ListNode {
// *     int val;
// *     ListNode *next;
// *     ListNode(int x) : val(x), next(NULL) {}
// * };
// */
///**
// * Definition for binary tree
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
//class Solution {
//public:
//    TreeNode *sortedListToBST(ListNode *head) {
//    	if(head == NULL){
//    		return NULL;
//    	}
//    	ListNode *pslow = head, *pfast = head;
//    	ListNode *pre = NULL;
//    	while(pfast != NULL && pfast->next != NULL){
//    		pre = pslow;
//    		pslow = pslow->next;
//    		pfast = pfast->next->next;
//    	}
//    	TreeNode *pRoot = new TreeNode(pslow->val);
//    	if(pre==NULL){
//    		pRoot->left = NULL;
//    	}else{
//    		pre->next = NULL;
//    		pRoot->left = sortedListToBST(head);
//    	}
//    	pRoot->right = sortedListToBST(pslow->next);
//    	return pRoot;
//    }
//};
