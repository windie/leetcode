class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL){
            return true;
        }
        vector<TreeNode*> s1, s2;
        s1.push_back(root->left);
        s2.push_back(root->right);
        while(!s1.empty() && ! s2.empty()){
            TreeNode *p1 = s1[s1.size()-1];
            TreeNode *p2 = s2[s2.size()-1];
            s1.pop_back();
            s2.pop_back();
            if(p1 == NULL && p2 == NULL){
                continue;
            }else if(!p1 || !p2){
                return false;
            }else if(p1->val != p2->val){
                return false;
            }else {
                s1.push_back(p1->left);
                s1.push_back(p1->right);
                s2.push_back(p2->right);
                s2.push_back(p2->left);
            }
        }
        return true;
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
//	bool isSymmetric(TreeNode *left, TreeNode* right) {
//		if (left == NULL || right == NULL) {
//			return left == right;
//		}
//		if (left->val != right->val) {
//			return false;
//		}
//		return isSymmetric(left->right, right->left)
//				&& isSymmetric(left->left, right->right);
//	}
//public:
//	bool isSymmetric(TreeNode *root) {
//		if (root == NULL) {
//			return true;
//		} else {
//			return isSymmetric(root->left, root->right);
//		}
//	}
//};
