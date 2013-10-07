#include<iostream>
#include<algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

bool comp(ListNode *n1, ListNode *n2){
	return n1->val > n2->val;
}
class Solution {

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	vector<ListNode *> newlists;
    	for(int i=0; i<lists.size(); i++){
    		if(!lists[i]==NULL){
    			newlists.push_back(lists[i]);
    		}
    	}

    	ListNode *head = NULL;
    	ListNode *cur = NULL;
    	make_heap(newlists.begin(), newlists.end(), comp);
    	while(newlists.size() > 0){
    		if(head == NULL){
    			head = newlists[0];
    		}
    		if(cur == NULL){
    			cur = newlists[0];
    		}else{
    			cur->next = newlists[0];
    			cur = cur->next;
    		}
    		pop_heap(newlists.begin(), newlists.end(), comp);
    		int last = newlists.size()-1;
    		if(newlists[last]->next != NULL){
    			newlists[last] = newlists[last]->next;
    			push_heap(newlists.begin(), newlists.end(), comp);
    		}else{
    			newlists.pop_back();
    		}
    	}
    	if(cur == NULL){
    		return NULL;
    	}else{
    		cur->next = NULL;
    	}
    	return head;
    }
};
