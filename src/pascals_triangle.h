class Solution {
public:
    vector<vector<int> > generate(int numRows) {
    	vector<vector<int> > res;
    	for(int i=1; i<=numRows; i++){
    		vector<int> tmp;
    		tmp.push_back(1);
    		for(int j=2; j<i; j++){
    			tmp.push_back(res[i-2][j-2] + res[i-2][j-1]);
    		}
    		if(i>1){
    			tmp.push_back(1);
    		}
    		res.push_back(tmp);
    	}
    	return res;
    }
};
