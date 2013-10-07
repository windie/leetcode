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
	TreeNode *constructTree(vector<int> &preorder, int plow, int phigh,
			vector<int> &inorder, int ilow, int ihigh) {
		if (plow > phigh) {
			return NULL;
		}
		TreeNode * proot = new TreeNode(preorder[plow]);
		int cnt = 0;
		int i = 0;
		for (i = ilow; i <= ihigh; i++) {
			if (inorder[i] == preorder[plow]) {
				break;
			}
			cnt++;
		}
		proot->left = constructTree(preorder, plow + 1, plow + cnt, inorder,
				ilow, i - 1);
		proot->right = constructTree(preorder, plow + cnt + 1, phigh, inorder,
				i + 1, ihigh);
		return proot;
	}

public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return constructTree(preorder, 0, preorder.size() - 1, inorder, 0,
				inorder.size() - 1);
	}
};
