class Solution {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		vector < vector<int> > res;
		if (root == NULL) {
			return res;
		}
		vector<TreeNode*> level;
		level.push_back(root);
		int begin = 0, size = 1;
		vector<int> levelnum;
		levelnum.push_back(1);
		while (begin < size) {
			int num = 0;
			for (int i = begin; i < size; i++) {
				if (level[i]->left != NULL) {
					level.push_back(level[i]->left);
					num++;
				}
				if (level[i]->right != NULL) {
					level.push_back(level[i]->right);
					num++;
				}
			}
			if (num > 0) {
				levelnum.push_back(num);
			}
			begin = size;
			size = level.size();
		}
		int end = level.size();
		for (int i = levelnum.size() - 1; i >= 0; i--) {
			int num = levelnum[i];
			vector<int> tmp;
			for (int j = end - num; j < end; j++) {
				tmp.push_back(level[j]->val);
			}
			res.push_back(tmp);
			end -= num;
		}
		return res;
	}
};

//#include <vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<vector<int> > levelOrderBottom(TreeNode *root) {
//		vector < vector<int> > res;
//		if (root == NULL) {
//			return res;
//		}
//		vector<TreeNode*> nodes;
//		nodes.push_back(root);
//		nodes.push_back(NULL);
//		int begin = 0;
//		int size = nodes.size();
//		while (begin != size) {
//			for (int i = begin; i < size - 1; i++) {
//				if (nodes[i]->left != NULL) {
//					nodes.push_back(nodes[i]->left);
//				}
//				if (nodes[i]->right != NULL) {
//					nodes.push_back(nodes[i]->right);
//				}
//			}
//			if (size != nodes.size()) {
//				nodes.push_back(NULL);
//			}
//			begin = size;
//			size = nodes.size();
//		}
//		vector<int> onelevel;
//		for (int i = nodes.size() - 2; i >= 0;i--) {
//			if (nodes[i] == NULL) {
//				res.push_back(onelevel);
//				onelevel.clear();
//			} else {
//				onelevel.insert(onelevel.begin(), nodes[i]->val);
//			}
//		}
//		res.push_back(onelevel);
//		return res;
//	}
//};
