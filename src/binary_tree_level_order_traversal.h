#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector < vector<int> > res;
		if (root == NULL) {
			return res;
		}
		vector<TreeNode*> queue;
		queue.push_back(root);
		int index = 0;

		while (index != queue.size()) {
			int size = queue.size();
			vector<int> tmp;
			for (int i = index; i < size; i++) {
				tmp.push_back(queue[i]->val);
				if (queue[i]->left != NULL) {
					queue.push_back(queue[i]->left);
				}
				if (queue[i]->right != NULL) {
					queue.push_back(queue[i]->right);
				}
			}
			res.push_back(tmp);
			index = size;
		}
		return res;
	}
};
