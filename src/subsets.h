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

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    void rec(vector<int> &num, int idx, vector<int> cur, vector<vector<int> > &res) {
        res.push_back(cur);
        for(int i = idx; i < num.size(); i++) {
            cur.push_back(num[i]);
            rec(num, i + 1, cur, res);
            cur.pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > res;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        rec(nums, 0, cur, res);
        return res;
    }
};

