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
    bool isleaf(TreeNode *root){
        return root->left==NULL && root->right==NULL;
    }
    int minDepth(TreeNode *root, int depth){
        if(root == NULL){
            return 0;
        }
        if(isleaf(root)){
            return depth;
        }
        int minDep = INT_MAX;
        if(root->left!=NULL){
            minDep = min(minDep, minDepth(root->left, depth+1));
        }
        if(root->right!=NULL){
            minDep = min(minDep, minDepth(root->right, depth+1));
        }
        return minDep;
    }
public:
    int minDepth(TreeNode *root) {
        return minDepth(root, 1);
    }
};

//class Solution {
//private:
//	int level(TreeNode *node, int curlevel){
//		if(node->left==NULL && node->right==NULL){
//			return curlevel;
//		}else if(node->left!=NULL && node->right!=NULL){
//			return min(level(node->left, curlevel+1), level(node->right, curlevel+1));
//		}else if(node->left!=NULL){
//			return level(node->left, curlevel+1);
//		}else{
//			return level(node->right, curlevel+1);
//		}
//	}
//public:
//    int minDepth(TreeNode *root) {
//    	if(root==NULL){
//    		return 0;
//    	}
//    	return level(root, 1);
//    }
//};
