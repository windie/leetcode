class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if(root==NULL){
            return res;
        }
        vector<TreeNode *> level;
        level.push_back(root);
        int size = 1, begin =0;
        bool isleft2right = true;
        while(begin < size){
            vector<int> tmp;
            for(int i = begin; i<size; i++){
                if(isleft2right){
                    tmp.push_back(level[i]->val);
                }else{
                    tmp.insert(tmp.begin(), level[i]->val);
                }
                if(level[i]->left != NULL){
                    level.push_back(level[i]->left);
                }
                if(level[i]->right != NULL){
                    level.push_back(level[i]->right);
                }
            }
            res.push_back(tmp);
            begin = size;
            size = level.size();
            isleft2right = !isleft2right;
        }
        return res;
    }
};

//class Solution {
//public:
//    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
//    	vector<vector<int> > res;
//    	if(root==NULL){
//    		return res;
//    	}
//    	vector<TreeNode*> nodes;
//    	nodes.push_back(root);
//    	int begin = 0;
//    	int size = nodes.size();
//    	bool isLeft2Right = true;
//    	while(begin != size){
//    		vector<int> onelevel;
//			if (isLeft2Right) {
//				for (int i = begin; i < size; i++) {
//					onelevel.push_back(nodes[i]->val);
//				}
//			} else {
//				for (int i = size - 1; i >= begin; i--) {
//					onelevel.push_back(nodes[i]->val);
//				}
//			}
//			for (int i = begin; i < size; i++) {
//				if (nodes[i]->left != NULL) {
//					nodes.push_back(nodes[i]->left);
//				}
//				if (nodes[i]->right != NULL) {
//					nodes.push_back(nodes[i]->right);
//				}
//			}
//    		res.push_back(onelevel);
//    		begin = size;
//    		size = nodes.size();
//    		isLeft2Right = !isLeft2Right;
//    	}
//    	return res;
//    }
//};
