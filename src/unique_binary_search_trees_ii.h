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
	vector<TreeNode *> generateTree(int begin, int end) {
		vector<TreeNode *> res;
		if (begin > end) {
			res.push_back(NULL);
			return res;
		}
		for (int i = begin; i <= end; i++) {
			vector<TreeNode *> leftNodes = generateTree(begin, i - 1);
			vector<TreeNode *> rightNodes = generateTree(i + 1, end);
			for (int j = 0; j < leftNodes.size(); j++) {
				for (int k = 0; k < rightNodes.size(); k++) {
					TreeNode *tmp = new TreeNode(i);
					tmp->left = leftNodes[j];
					tmp->right = rightNodes[k];
					res.push_back(tmp);
				}
			}
		}
		return res;
	}
public:
	vector<TreeNode *> generateTrees(int n) {
		return generateTree(1, n);
	}
};
