#include <iostream>
using namespace std;

class Solution {
	char convertchar(int begin, int step) {
		return 'a' + begin + step;
	}
	void recursiveGen(string& digits, int pos, string& curStr,
			vector<string>& res) {
		if (pos >= digits.size()) {
			res.push_back(curStr);
			return;
		}
		if (digits[pos] == '0') {
			curStr.push_back(' ');
			recursiveGen(digits, pos + 1, curStr, res);
			curStr.erase(curStr.end() - 1, curStr.end());
		} else if (digits[pos] == '1') {
			recursiveGen(digits, pos + 1, curStr, res);
		} else if (digits[pos] == '8') {
			for (int i = 0; i < 3; i++) {
				char ch1 = (digits[pos] - '2') * 3 + 'a' + 1 + i;
				curStr.push_back(ch1);
				recursiveGen(digits, pos + 1, curStr, res);
				curStr.erase(curStr.end() - 1, curStr.end());
			}
		} else if (digits[pos] == '7') {
			for (int i = 0; i < 4; i++) {
				char ch1 = (digits[pos] - '2') * 3 + 'a' + i;
				curStr.push_back(ch1);
				recursiveGen(digits, pos + 1, curStr, res);
				curStr.erase(curStr.end() - 1, curStr.end());
			}
		} else if (digits[pos] == '9') {
			for (int i = 0; i < 4; i++) {
				char ch1 = (digits[pos] - '2') * 3 + 'a' + 1 + i;
				curStr.push_back(ch1);
				recursiveGen(digits, pos + 1, curStr, res);
				curStr.erase(curStr.end() - 1, curStr.end());
			}
		} else {
			for (int i = 0; i < 3; i++) {
				char ch1 = (digits[pos] - '2') * 3 + 'a' + i;
				curStr.push_back(ch1);
				recursiveGen(digits, pos + 1, curStr, res);
				curStr.erase(curStr.end() - 1, curStr.end());
			}
		}
	}

public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		string curStr = "";
		recursiveGen(digits, 0, curStr, res);
		return res;
	}
};
