class Solution {
    void maxPathSum(TreeNode *root, int &res, int &maxPath){
        if(root== NULL){
            maxPath = 0;
            return;
        }
        int left = 0, right = 0;
        maxPathSum(root->left, res, left);
        maxPathSum(root->right, res, right);
        int sum = root->val;
        if(left > 0){
            sum += left;
        }
        if(right > 0){
            sum += right;
        }
        if(sum > res){
            res = sum;
        }
        if(left <=0 && right <=0){
            maxPath = root->val;
        }else{
            maxPath = root->val + max(left, right);
        }
    }
public:
    int maxPathSum(TreeNode *root) {
        if(root == NULL){
            return 0;
        }
        int res = INT_MIN, maxPath;
        maxPathSum(root, res, maxPath);
        return res;
    }
};

///**
// * Definition for binary tree
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
//class Solution {
//private:
//	int mathPath(TreeNode *root, int &max) {
//		if (root == NULL) {
//			return 0;
//		}
//		int leftMax = mathPath(root->left, max);
//		int rightMax = mathPath(root->right, max);
//		if (leftMax > 0 && rightMax > 0) {
//			if (leftMax + rightMax + root->val > max) {
//				max = leftMax + rightMax + root->val;
//			}
//			return (root->val + leftMax > root->val + rightMax) ?
//					(root->val + leftMax) : (root->val + rightMax);
//		} else if (leftMax > 0) {
//			if (root->val + leftMax > max) {
//				max = root->val + leftMax;
//			}
//			return root->val + leftMax;
//		} else if (rightMax > 0) {
//			if (root->val + rightMax > max) {
//				max = root->val + rightMax;
//			}
//			return root->val + rightMax;
//		} else {
//			if (root->val > max) {
//				max = root->val;
//			}
//			return root->val;
//		}
//	}
//
//public:
//	int maxPathSum(TreeNode *root) {
//		if (root == NULL) {
//			return 0;
//		}
//		int max = -65535;
//		mathPath(root, max);
//		return max;
//	}
//};
