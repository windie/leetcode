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
			if (pre == NULL || pre->left == cur || pre->right == cur) {
				if (cur->left) {
					s.push(cur->left);
				} else if (cur->right) {
					s.push(cur->right);
				} else {
					res.push_back(cur->val);
					s.pop();
				}
			} else if (cur->left == pre) {
				if (cur->right) {
					s.push(cur->right);
				} else {
					res.push_back(cur->val);
					s.pop();
				}
			} else if (cur->right == pre) {
				res.push_back(cur->val);
				s.pop();
			}
			pre = cur;
		}
		return res;
	}
};

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
