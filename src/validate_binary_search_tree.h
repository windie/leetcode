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
	bool recursive(TreeNode *root, int& min, int& max) {
		if(root == NULL){
			return true;
		}
		if (root->left!=NULL && root->right!=NULL) {
			int leftmin, leftmax, rightmin, rightmax;
			bool left = recursive(root->left, leftmin, leftmax);
			bool right = recursive(root->right, rightmin, rightmax);
			min = leftmin;
			max = rightmax;
			return (leftmax < root->val) && (rightmin > root->val) && left && right;
		} else if (root->left != NULL) {
			int leftmin, leftmax;
			bool left = recursive(root->left, leftmin, leftmax);
			min =leftmin;
			max = root->val;
			return (leftmax < root->val) && left;
		}else if (root->right != NULL) {
			int  rightmin, rightmax;
			bool right = recursive(root->right, rightmin, rightmax);
			min = root->val;
			max = rightmax;
			return (rightmin > root->val) && right;
		}else{
			min = root->val;
			max = root->val;
			return true;
		}
	}
public:
	bool isValidBST(TreeNode *root) {
		if (root == NULL) {
			return true;
		}
		int min, max;
		return recursive (root, min, max);
	}
};
