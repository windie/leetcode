#include<iostream>
using namespace std;

class Solution {
	void combine(vector<int> &cand, int index, int target,
			vector<int>& cur, vector<vector<int> >&res) {
		if(index >= cand.size() || target < 0){
			return;
		}
		if (0 == target) {
			res.push_back(cur);
		} else {
			for(int i=index; i<=cand.size(); i++){
				cur.push_back(cand[i]);
				combine(cand, i, target - cand[i], cur, res);
				cur.pop_back();
			}
		}
	}

public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<int> cand = candidates;
		sort(cand.begin(), cand.end());
		vector<int> cur;
		vector<vector<int> > res;
		combine(cand, 0, target, cur, res);
		return res;
	}
};
