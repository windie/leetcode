#include <iostream>
using namespace std;

class Solution {
	void recursive( int m, int k, vector<int> &cur, vector<vector<int> > &res){
		if(k==0){
			res.push_back(cur);
			return;
		}
		for(int i = m; i>=k; i--){
			cur[k-1] = i;
			recursive(i-1, k-1, cur, res);
		}
	}

public:
    vector<vector<int> > combine(int n, int k) {
    	vector<int> cur(k, 0);
    	vector<vector<int> > res;
    	recursive(n, k, cur, res);
    	return res;
    }
};


//class Solution {
//	void comb(int n, int m, vector<int>& cur, vector<vector<int> > &res) {
//		for (int i = n; i >= m; i--) {
//			cur[m - 1] = i;
//			if (m  > 1) {
//				comb(i - 1, m - 1, cur, res);
//			} else {
//				res.push_back(cur);
//			}
//		}
//	}
//
//public:
//	vector<vector<int> > combine(int n, int k) {
//		vector<vector<int> > res;
//		vector<int> cur;
//		for(int i=0; i<k; i++){
//			cur.push_back(0);
//		}
//		comb(n, k, cur, res);
//		return res;
//	}
//};
