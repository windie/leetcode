class Solution {
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder,
			int ibegin, int iend, int pbegin, int pend) {
		if (ibegin > iend || pbegin > pend) {
			return NULL;
		}
		TreeNode*root = new TreeNode(postorder[pend]);
		int i, num;
		for (i = ibegin, num = 0; i <= iend; i++, num++) {
			if (inorder[i] == postorder[pend]) {
				break;
			}
		}
		root->left = buildTree(inorder, postorder, ibegin, i - 1, pbegin,
				pbegin + num - 1);
		root->right = buildTree(inorder, postorder, i + 1, iend, pbegin + num,
				pend - 1);
		return root;
	}
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return buildTree(inorder, postorder, 0, inorder.size() - 1, 0,
				postorder.size() - 1);
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
//	TreeNode *constructTree(vector<int> &inorder, int ilow, int ihigh,
//			vector<int> &postorder, int plow, int phigh) {
//		if (plow > phigh) {
//			return NULL;
//		}
//		TreeNode *proot = new TreeNode(postorder[phigh]);
//		int cnt = 0, i = 0;
//		for (i = ilow; i <= ihigh; i++) {
//			if (inorder[i] == postorder[phigh]) {
//				break;
//			}
//			cnt++;
//		}
//		proot->left = constructTree(inorder, ilow, i - 1, postorder, plow,
//				plow + cnt -1);
//		proot->right = constructTree(inorder, i + 1, ihigh, postorder,
//				plow + cnt, phigh - 1);
//		return proot;
//	}
//
//public:
//	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
//		return constructTree(inorder, 0, inorder.size() - 1, postorder, 0,
//				postorder.size() - 1);
//	}
//};
