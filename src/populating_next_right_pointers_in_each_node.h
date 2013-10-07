/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right==NULL){
            return;
        }
        TreeLinkNode *p = root;
        TreeLinkNode *rightsibling = NULL;
        while(p){
            if(p->next == NULL){
                rightsibling = NULL;
            }else{
                rightsibling = p->next->left;
            }
            p->left->next = p->right;
            p->right->next = rightsibling;
            p = p->next;
        }
        connect(root->left);
    }
};


//class Solution {
//public:
//	void connect(TreeLinkNode *root) {
//		if (root == NULL) {
//			return;
//		}
//		vector<TreeLinkNode *> cur;
//		cur.push_back(root);
//		int begin = 0, size = 1;
//		while (begin != size) {
//			for (int i = begin; i < size; i++) {
//				if (i + 1 < size) {
//					cur[i]->next = cur[i + 1];
//				}
//				if (cur[i]->left != NULL) {
//					cur.push_back(cur[i]->left);
//				}
//				if (cur[i]->right != NULL) {
//					cur.push_back(cur[i]->right);
//				}
//			}
//			begin = size;
//			size = cur.size();
//		}
//	}
//};
