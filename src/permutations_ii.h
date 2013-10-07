class Solution {
	void recursive(vector<int> &num, vector<int> & s, int k,
			vector<int> &visited, vector<vector<int> > & res) {
		if (k == num.size()-1) {
			res.push_back(s);
		} else {
			for (int i = 0; i < num.size(); i++) {
				if (visited[i]) {
					continue;
				}
				if (i > 0 && num[i] == num[i - 1] && visited[i - 1]==0) {
					//相等的时候则前面的数必须使用了，自己才能使用
					continue;
				}
				visited[i] = 1;
				s.push_back(num[i]);
				recursive(num, s, k + 1, visited, res);
				s.pop_back();
				visited[i] = 0;
			}
		}
	}
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
		sort(num.begin(), num.end());
		vector < vector<int> > res;
		vector<int> s;
		vector<int> visited(num.size(), 0);
		recursive(num, s, 0, visited, res);
		return res;
	}
};

