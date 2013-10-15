class Solution {
	TreeNode *buildTree(vector<int> &inorder, vector<int> &preorder, int ibegin,
			int iend, int pbegin, int pend) {
		if (ibegin > iend || pbegin > pend) {
			return NULL;
		}
		TreeNode*root = new TreeNode(preorder[pbegin]);
		int i, num;
		for (i = ibegin, num = 0; i <= iend; i++, num++) {
			if (inorder[i] == preorder[pbegin]) {
				break;
			}
		}
		root->left = buildTree(inorder, preorder, ibegin, i - 1, pbegin + 1,
				pbegin + num);
		root->right = buildTree(inorder, preorder, i + 1, iend,
				pbegin + num + 1, pend);
		return root;
	}
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return buildTree(inorder, preorder, 0, inorder.size() - 1, 0,
				preorder.size() - 1);
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
//	TreeNode *constructTree(vector<int> &preorder, int plow, int phigh,
//			vector<int> &inorder, int ilow, int ihigh) {
//		if (plow > phigh) {
//			return NULL;
//		}
//		TreeNode * proot = new TreeNode(preorder[plow]);
//		int cnt = 0;
//		int i = 0;
//		for (i = ilow; i <= ihigh; i++) {
//			if (inorder[i] == preorder[plow]) {
//				break;
//			}
//			cnt++;
//		}
//		proot->left = constructTree(preorder, plow + 1, plow + cnt, inorder,
//				ilow, i - 1);
//		proot->right = constructTree(preorder, plow + cnt + 1, phigh, inorder,
//				i + 1, ihigh);
//		return proot;
//	}
//
//public:
//	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
//		return constructTree(preorder, 0, preorder.size() - 1, inorder, 0,
//				inorder.size() - 1);
//	}
//};
