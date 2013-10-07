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
		if (root == NULL) {
			return;
		}
		TreeLinkNode *p = root;
		TreeLinkNode *rs = NULL;
		while (p) {
			TreeLinkNode *p1 = p->next;
			while (p1 && p1->left == NULL && p1->right == NULL) {
				p1 = p1->next;
			}
			if (p1 == NULL) {
				rs = NULL;
			} else if (p1->left) {
				rs = p1->left;
			} else {
				rs = p1->right;
			}
			if (p->left != NULL) {
				if (p->right != NULL) {
					p->left->next = p->right;
					p->right->next = rs;
				} else {
					p->left->next = rs;
				}
			} else if (p->right != NULL) {
				p->right->next = rs;
			}
			p = p->next;
		}
		connect(root->right);
		connect(root->left);
	}
};

//#include<iostream>
//using namespace std;
//
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
