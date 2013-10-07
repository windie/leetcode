#include <vector>
using namespace std;

class Solution {
	TreeNode *sortedArrayToBST(vector<int> &num, int begin, int end) {
		if(begin>end) {
			return NULL;
		}
		int middle = begin + (end-begin)/2;
		TreeNode *tmp = new TreeNode(num[middle]);
		tmp->left = sortedArrayToBST(num, begin, middle-1);
		tmp->right = sortedArrayToBST(num, middle+1, end);
		return tmp;
	}

public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
    	return sortedArrayToBST(num, 0, num.size()-1);
    }
};
