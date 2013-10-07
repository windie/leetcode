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
