#include<iostream>
using namespace std;

class Solution {
	void combine(vector<int>& num, int target, vector<int> &cur,
			vector<vector<int> > &res, int index) {
		if (target < 0 ) {
			return;
		} else if (target == 0) {
			res.push_back(cur);
			return;
		} else {
			for (int i = index; i < num.size(); i++) {
				cur.push_back(num[i]);
				combine(num, target - num[i], cur, res, i + 1);
				cur.pop_back();
				while ((i + 1 < num.size()) && (num[i] == num[i + 1])) {
					i++;
				}
			}
		}
	}
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<int> cand = num;
		sort(cand.begin(), cand.end());
		vector<int> cur;
		vector<vector<int> > res;
		combine(cand, target, cur, res, 0);
		return res;
	}
};
