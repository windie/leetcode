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
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        vector<TreeNode*> queue;
        if(root == NULL){
            return res;
        }else{
            queue.push_back(root);

        }
        int begin = 0;
        int end = 1;
        while(begin < end){
            res.push_back(queue[end-1]->val);
            for(int i = begin; i<end; i++){
                if(queue[i]->left!=NULL){
                    queue.push_back(queue[i]->left);
                }
                if(queue[i]->right!=NULL){
                    queue.push_back(queue[i]->right);
                }
            }
            begin = end;
            end = queue.size();
        }
        return res;
    }
};