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
private:
	TreeNode *constructTree(vector<int> &inorder, int ilow, int ihigh,
			vector<int> &postorder, int plow, int phigh) {
		if (plow > phigh) {
			return NULL;
		}
		TreeNode *proot = new TreeNode(postorder[phigh]);
		int cnt = 0, i = 0;
		for (i = ilow; i <= ihigh; i++) {
			if (inorder[i] == postorder[phigh]) {
				break;
			}
			cnt++;
		}
		proot->left = constructTree(inorder, ilow, i - 1, postorder, plow,
				plow + cnt -1);
		proot->right = constructTree(inorder, i + 1, ihigh, postorder,
				plow + cnt, phigh - 1);
		return proot;
	}

public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return constructTree(inorder, 0, inorder.size() - 1, postorder, 0,
				postorder.size() - 1);
	}
};
