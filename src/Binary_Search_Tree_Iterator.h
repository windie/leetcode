/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    vector<TreeNode* > s;
    void left(TreeNode *root){
        TreeNode *p = root;
        while(p){
            s.push_back(p);
            p = p->left;
        }
    }
public:
    BSTIterator(TreeNode *root) {
        s.clear();
        left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * res = s[s.size()-1];
        s.pop_back();
        left(res->right);
        return res->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */