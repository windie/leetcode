class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<int> tmp;
        vector<vector<int> > res;
        res.push_back(tmp);
        sort(S.begin(), S.end());
        int begin = 0;
        for(int i = 0; i<S.size(); i++){
            int size = res.size();
            for(int j = begin; j<size; j++){
                vector<int> temp = res[j];
                temp.push_back(S[i]);
                res.push_back(temp);
            }
            if(i+1 < S.size() && S[i]==S[i+1]){ // if next S[i] is equal to this, skip
                begin = size;
            }else{
                begin = 0;
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
    void rec(vector<int> &s, vector<vector<int> > &res, vector<int> cur, int pos){
        res.push_back(cur);
        for(int i = pos; i < s.size(); i++){
            if(i > 0 && i != pos && s[i] == s[i-1]){
                continue;
            }
            cur.push_back(s[i]);
            rec(s, res, cur, i+1);
            cur.pop_back();
        }
    }
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        vector<int> s = S;
        sort(s.begin(), s.end());
        vector<vector<int> > res;
        vector<int> cur;
        rec(s, res, cur, 0);
        return res;
    }
};



//class Solution {
//public:
//	vector<vector<int> > subsetsWithDup(vector<int> &S) {
//		vector < vector<int> > res;
//		vector<int> emp;
//		res.push_back(emp);
//		sort(S.begin(), S.end());
//		int preS = 0;
//		int prePos = 0;
//		for (int i = 0; i < S.size(); i++) {
//			int j = 0;
//			if (i > 0 && S[i] == preS) {
//				j = prePos;
//			}
//			int size = res.size();
//			preS = S[i];
//			prePos = size;
//			for (; j < size; j++) {
//				vector<int> tmp = res[j];
//				tmp.push_back(S[i]);
//				res.push_back(tmp);
//			}
//		}
//		return res;
//	}
//};
