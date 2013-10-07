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
    void f(TreeNode *root, int target, vector<int> &cur, vector<vector<int> > &res){
        if(root == NULL){
            return;
        }
        cur.push_back(root->val);
        if(root->left && root->right){
        f(root->left, target-root->val, cur, res);
        f(root->right, target-root->val, cur, res);
        }else if(root->left){
            f(root->left, target-root->val, cur, res);
        }else if(root->right){
            f(root->right, target-root->val, cur, res);
        }else if(target-root->val == 0){
            res.push_back(cur);
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
        f(root, sum, cur, res);
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
