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
    void rec(TreeNode *root, TreeNode * &head, TreeNode *&tail){
        if(root == NULL){
            head = tail = NULL;
            return;
        }
        TreeNode *lefthead = NULL, *lefttail = NULL;
        TreeNode *righthead = NULL, *righttail = NULL;
        rec(root->left, lefthead, lefttail);
        rec(root->right, righthead, righttail);
        if(lefthead == NULL){
            root->left = NULL;
            root->right = righthead;
            head = root;
            if(righttail != NULL){
                tail = righttail;
            }else{
                tail = root;
            }
        }else{
            root->left = NULL;
            root->right = lefthead;
            lefttail->right = righthead;
            head = root;
            if(righttail != NULL){
                tail = righttail;
            }else{
                tail = lefttail;
            }
        }
    }
public:
    void flatten(TreeNode *root) {
        TreeNode *head, *tail;
        rec(root, head, tail);
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
//	TreeNode * recursive(TreeNode *root) {
//		if (root == NULL) {
//			return NULL;
//		}
//
//		TreeNode * lefttail, *righttail;
//		lefttail = recursive(root->left);
//		righttail = recursive(root->right);
//		if(lefttail == NULL && righttail == NULL){
//			return root;
//		}
//		if (lefttail == NULL) {
//			return righttail;
//		}
//		if (righttail == NULL) {
//			root->right = root->left;
//			root->left = NULL;
//			return lefttail;
//		}
//		lefttail->right = root->right;
//		root->right = root->left;
//		root->left = NULL;
//		return righttail;
//	}
//public:
//	void flatten(TreeNode *root) {
//		recursive(root);
//	}
//};
