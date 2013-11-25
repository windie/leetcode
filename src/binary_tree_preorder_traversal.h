#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> res;
		stack<TreeNode *> s;
		if (root == NULL) {
			return res;
		}
		s.push(root);
		while (!s.empty()) {
			res.push_back(s.top()->val);
			TreeNode * tmp = s.top();
			s.pop();
			if (tmp->right) {
				s.push(tmp->right);
			}
			if (tmp->left) {
				s.push(tmp->left);
			}
		}
		return res;
	}
};

//class Solution {
//    void preorder(vector<int> &res, TreeNode* root){
//        if(root==NULL){
//            return;
//        }
//        res.push_back(root->val);
//        preorder(res, root->left);
//        preorder(res, root->right);
//    }
//public:
//    vector<int> preorderTraversal(TreeNode *root) {
//        vector<int> res;
//        preorder(res, root);
//        return res;
//    }
//};
