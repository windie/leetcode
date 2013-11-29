#include <vector>
using namespace std;

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
    void recursive(vector<vector<int> > & res, vector<int> &cur, int sum, TreeNode *root){
        cur.push_back(root->val);
        if(root->left){
            recursive(res, cur, sum - root->val, root->left);
        }
        if(root->right){
            recursive(res, cur, sum - root->val, root->right);
        }
        if(root->left == NULL && root->right == NULL){
            if(sum == root->val){
                res.push_back(cur);
            }
        }
        cur.pop_back();
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> cur;
        if(root == NULL){
            return res;
        }
        recursive(res, cur, sum, root);
        return res;
    }
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//private:
//	void hasPathSum(TreeNode *root, vector<int> curPath, int sum, vector<vector<int> > & res) {
//		if (root == NULL) {
//			return;
//		}
//		curPath.push_back(root->val);
//    	if(root->left != NULL && root->right != NULL){
//    		hasPathSum(root->left, curPath, sum - root->val, res);
//    		hasPathSum(root->right, curPath, sum- root->val, res);
//    	}
//    	else if(root->left != NULL){
//    		hasPathSum(root->left, curPath, sum - root->val, res);
//    	}else if(root->right != NULL){
//    		hasPathSum(root->right, curPath, sum- root->val, res);
//    	}else if(root->val == sum){
//    		res.push_back(curPath);
//    	}
//    	curPath.pop_back();
//	}
//public:
//    vector<vector<int> > pathSum(TreeNode *root, int sum) {
//    	vector<vector<int> > res;
//    	vector<int> curPath;
//    	hasPathSum(root, curPath, sum, res);
//    	return res;
//    }
//};
