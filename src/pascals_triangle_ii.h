class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res;
		for (int i = 0; i <= rowIndex; i++) {
			if (i == 0) {
				res.push_back(1);
				continue;
			}
			if (i == 1) {
				res.push_back(1);
				continue;
			}
			for (int j = i - 1; j >= 1; j--) {
				res[j] = res[j] + res[j - 1];
			}
			res.push_back(1);
		}
		return res;
	}
};
