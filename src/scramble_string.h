#include<iostream>
using namespace std;

class Solution {
	bool islegal(string &s1, int begin1, string &s2, int begin2, int len) {
		int dic[26] = { 0 };
		for (int i = begin1; i < begin1 + len; i++) {
			dic[s1[i] - 'a']++;
		}
		for (int i = begin2; i < begin2 + len; i++) {
			dic[s2[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++) {
			if (dic[i]) {
				return false;
			}
		}
		return true;
	}

	bool isScramble(string &s1, int begin1, int end1, string &s2, int begin2,
			int end2) {
		if (begin1 == end1) {
			return s1[begin1] == s2[begin2];
		}
		bool isfound = false;
		for (int i = 1; i <= end1 - begin1; i++) {
			if (islegal(s1, begin1, s2, begin2, i)
					&& islegal(s1, begin1 + i, s2, begin2 + i,
							end1 - begin1 - i + 1)) {
				isfound = isScramble(s1, begin1, begin1 + i - 1, s2, begin2,
						begin2 + i - 1)
						&& isScramble(s1, begin1 + i, end1, s2, begin2 + i,
								end2);
			}
			if (!isfound && islegal(s1, begin1, s2, end2 - i + 1, i)
					&& islegal(s1, begin1 + i, s2, begin2,
							end1 - begin1 - i + 1)) {
				isfound = isScramble(s1, begin1, begin1 + i - 1, s2,
						end2 - i + 1, end2)
						&& isScramble(s1, begin1 + i, end1, s2, begin2,
								end2 - i);
			}
			if (isfound) {
				break;
			}
		}
		return isfound;
	}
public:
	bool isScramble(string s1, string s2) {
		if (s1.length() != s2.length()) {
			return false;
		}
		return isScramble(s1, 0, s1.length() - 1, s2, 0, s2.length() - 1);
	}
};
