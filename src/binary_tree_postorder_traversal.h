#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> res;
		if (root == NULL) {
			return res;
		}
		stack<TreeNode*> s;
		s.push(root);
		TreeNode * pre = NULL;
		while (!s.empty()) {
			TreeNode *cur = s.top();
			if (pre == NULL || pre->left == cur || pre->right == cur) {  // traverse down the tree
				if (cur->left) {
					s.push(cur->left);
				} else if (cur->right) {
					s.push(cur->right);
				} else {
					res.push_back(cur->val);
					s.pop();
				}
			} else if (cur->left == pre) { // traverse up the tree from the left
				if (cur->right) {
					s.push(cur->right);
				} else {
					res.push_back(cur->val);
					s.pop();
				}
			} else if (cur->right == pre) { // traverse up the tree from the right
				res.push_back(cur->val);
				s.pop();
			}
			pre = cur;
		}
		return res;
	}
};

vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> res;
        TreeNode *pre = NULL, *cur = NULL;
        if(root == NULL) {
            return res;
        }
        s.push(root);
        while(!s.empty()){
            cur = s.top();
            if(pre == NULL || pre->left == cur || pre->right == cur){ // traverse down the tree
                if(cur->left) {
                    s.push(cur->left);
                }else if(cur->right) {
                    s.push(cur->right);
                }
            }else if(cur->left == pre) {  // traverse up the tree from the left
                if(cur->right) {
                    s.push(cur->right);
                }
            }else { // traverse up the tree from the right
                res.push_back(cur->val);
                s.pop();
            }
            pre = cur;
        }
        return res;
    }

//class Solution {
//	void postorder(TreeNode * root, vector<int> &res) {
//		if (root == NULL) {
//			return;
//		}
//		postorder(root->left, res);
//		postorder(root->right, res);
//		res.push_back(root->val);
//	}
//public:
//	vector<int> postorderTraversal(TreeNode *root) {
//		vector<int> res;
//		postorder(root, res);
//		return res;
//	}
//};
