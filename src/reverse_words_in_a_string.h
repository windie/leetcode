class Solution {
public:
	void reverseWords(string &s) {
		string res;
		int begin = -1, end = -1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				if (begin >= 0) {
					if (res.size() > 0) {
						res.push_back(' ');
					}
					for (int j = end; j >= begin; j--) {
						res.push_back(s[j]);
					}
					begin = end = -1;
				}
			} else {
				if (begin < 0) {
					begin = end = i;
				} else {
					end++;
				}
			}
		}
		if (begin >= 0) {
			if (res.size() > 0) {
				res.push_back(' ');
			}
			for (int i = end; i >= begin; i--) {
				res.push_back(s[i]);
			}
		}
		for (int i = 0, j = res.size() - 1; i <= j; i++, j--) {
			char tmp = res[i];
			res[i] = res[j];
			res[j] = tmp;
		}
		s = res;
	}
};
