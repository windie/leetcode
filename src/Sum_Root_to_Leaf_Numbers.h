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
    int sum(TreeNode *root, int res){
        if(root==NULL){
            return 0;
        }else if(root->left==NULL && root->right==NULL){
            return res*10+ root->val;
        }
        return sum(root->left, res*10 + root->val) + sum(root->right, res*10 + root->val);
    }
public:
    int sumNumbers(TreeNode *root) {
        return sum(root, 0);
    }
};

//class Solution {
//private:
//	bool isLeaf(TreeNode *node){
//		return (node->left == NULL) && (node->right == NULL);
//	}
//
//	int recSum(TreeNode *node, int num){
//		if(node==NULL){
//			return 0;
//		}
//		if(isLeaf(node)){
//			return node->val + num*10;
//		}else{
//			return recSum(node->left, node->val + num*10)
//					+ recSum(node->right, node->val + num*10);
//		}
//	}
//
//public:
//    int sumNumbers(TreeNode *root) {
//    	return recSum(root, 0);
//    }
//};
