#include <iostream>
using namespace std;

class Solution {
	bool isBalanced(TreeNode *root, int &level) {
		if (root == NULL) {
			level = 0;
			return true;
		}
		bool isleftvalid = false, isrightvalid = false;
		int left_lev = 0, right_lev = 0;
		isleftvalid = isBalanced(root->left, left_lev);
		isrightvalid = isBalanced(root->right, right_lev);
		if(!isleftvalid || !isrightvalid){
			return false;
		}
		if(abs(left_lev-right_lev) >1){
			return false;
		}
		level = (left_lev > right_lev ? left_lev : right_lev) + 1;
		return true;
	}
public:
	bool isBalanced(TreeNode *root) {
		int level=0;
		return isBalanced(root, level);
	}
};

//class Solution {
//
//private:
//    int getBalancedTreeHeight(TreeNode *root) {
//        if (root == NULL) return 0;
//	int leftHeight = getBalancedTreeHeight(root->left);
//	int rightHeight = getBalancedTreeHeight(root->right);
//	if (leftHeight >= 0 && rightHeight >= 0) {
//		if (leftHeight + 1 == rightHeight) {
//			return rightHeight + 1;
//		}
//		else if (leftHeight == rightHeight + 1 || leftHeight == rightHeight){
//			return leftHeight + 1;
//		}
//	}
//	return -1;
//    }
//
//public:
//    bool isBalanced(TreeNode *root) {
//        return getBalancedTreeHeight(root) >= 0;
//    }
//};


