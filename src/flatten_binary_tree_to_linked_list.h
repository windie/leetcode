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
private:
	TreeNode * recursive(TreeNode *root) {
		if (root == NULL) {
			return NULL;
		}

		TreeNode * lefttail, *righttail;
		lefttail = recursive(root->left);
		righttail = recursive(root->right);
		if(lefttail == NULL && righttail == NULL){
			return root;
		}
		if (lefttail == NULL) {
			return righttail;
		}
		if (righttail == NULL) {
			root->right = root->left;
			root->left = NULL;
			return lefttail;
		}
		lefttail->right = root->right;
		root->right = root->left;
		root->left = NULL;
		return righttail;
	}
public:
	void flatten(TreeNode *root) {
		recursive(root);
	}
};
