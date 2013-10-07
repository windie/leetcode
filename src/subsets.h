class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
    	vector<vector<int> > res;
    	vector<int> emp;
    	res.push_back(emp);
    	sort(S.begin(), S.end());
    	for(int i=0; i<S.size(); i++){
    		int size = res.size();
    		for(int j=0; j<size; j++){
    			vector<int> tmp = res[j];
    			tmp.push_back(S[i]);
    			res.push_back(tmp);
    		}
    	}
    	return res;
    }
};
