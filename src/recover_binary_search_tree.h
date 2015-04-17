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
//    void recoverTree(TreeNode *root) {
//        TreeNode * res1 = NULL, *res2 = NULL;
//        TreeNode * p = root, *parent = NULL, *pre = NULL;
//        while(p){
//            if(p->left == NULL){
//                if(parent && parent->val > p->val){
//                    if(res1 == NULL){
//                        res1 = parent;
//                    }
//                    res2 = p;
//                }
//                parent = p;
//                p = p->right;
//            }else{
//                // Threaded binary tree
//                pre = p->left;
//                while(pre->right != NULL && pre->right != p){
//                    pre = pre->right;
//                }
//                if(pre->right==NULL){
//                    pre->right = p;
//                    p = p->left;
//                }else{
//                    pre->right = NULL;
//                    if(parent && parent->val > p->val){
//                        if(res1 == NULL){
//                            res1 = parent;
//                        }
//                        res2 = p;
//                    }
//                    parent = p;
//                    p = p->right;
//                }
//            }
//        }
//        if(res1&&res2){
//            int tmp = res1->val;
//            res1->val = res2->val;
//            res2->val = tmp;
//        }
//    }
//};

#include<iostream>
using namespace std;

class Solution {
	void inorder(TreeNode *root, vector<TreeNode*>& nl, vector<int> &res){
		if(root == NULL){
			return;
		}
		inorder(root->left, nl, res);
		nl.push_back(root);
		res.push_back(root->val);
		inorder(root->right, nl, res);
	}
public:
    void recoverTree(TreeNode *root) {
    	vector<int> rs;
    	vector<TreeNode*> nl;
    	inorder(root, nl, rs);
    	sort(rs.begin(), rs.end());
    	for(int i=0; i<rs.size(); i++){
    		nl[i]->val = rs[i];
    	}
    }
};
