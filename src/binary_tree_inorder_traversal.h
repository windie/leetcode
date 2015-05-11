class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<TreeNode*> stack;
        vector<int> res;
        TreeNode* cur= root;
        while(stack.size()>0 || cur){
            if(cur){
                stack.push_back(cur);
                cur = cur->left;
            }else{
                cur = stack[stack.size()-1];
                res.push_back(cur->val);
                stack.pop_back();
                cur = cur->right;
            }
        }
        return res;
    }
};

    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode* > s;
        vector<int> res;
        TreeNode *cur = root;
        while(cur || !s.empty()){
            while(cur) {
                s.push(cur);
                cur = cur->left;
            }
            TreeNode *node = s.top();
            s.pop();
            res.push_back(node->val);
            cur = node->right;
        }
        return res;
    }

//#include <vector>
//using namespace std;
//
//class Solution {
//	void inorder(TreeNode *root, vector<int>& res){
//		if(root==NULL){
//			return;
//		}else{
//			inorder(root->left, res);
//			res.push_back(root->val);
//			inorder(root->right, res);
//		}
//	}
//public:
//    vector<int> inorderTraversal(TreeNode *root) {
//    	vector<int> res;
//    	inorder(root, res);
//    	return res;
//    }
//};
