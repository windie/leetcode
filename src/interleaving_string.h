#include<iostream>
using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length()) {
			return false;
		}
		vector<vector<bool> > m(s1.length() + 1, vector<bool>(s2.length() + 1));
		m[0][0] = true;
		for (int i = 1; i <= s2.length(); i++) {
			m[0][i] = m[0][i - 1] && (s3[i - 1] == s2[i - 1]);
		}
		for (int i = 1; i <= s1.length(); i++) {
			m[i][0] = m[i - 1][0] && (s3[i - i] == s1[i - i]);
		}
		for (int i = 1; i <= s1.length(); i++) {
			for (int j = 1; j <= s2.length(); j++) {
				m[i][j] = ((s3[i + j - 1] == s1[i - 1]) && m[i - 1][j])
						|| ((s3[i + j - 1] == s2[j - 1]) && m[i][j - 1]);
			}
		}
		return m[s1.length()][s2.length()];
	}
};

//class Solution {
//	bool isInter(string &s1, int i1, string &s2, int i2, string &s3, int i3) {
//		if(s1.length()-i1 + s2.length()-i2 != s3.length()-i3){
//			return false;
//		}
//		if (i1 == s1.length() && i2 == s2.length()) {
//			return i3 == s3.length();
//		}
//		if (i1 == s1.length()) {
//			return s2.substr(i2) == s3.substr(i3);
//		}
//		if (i2 == s2.length()) {
//			return s1.substr(i1) == s3.substr(i3);
//		}
//		if (s1[i1] != s2[i2]) {
//			if (s3[i3] == s1[i1]) {
//				return isInter(s1, i1 + 1, s2, i2, s3, i3 + 1);
//			} else if (s3[i3] == s2[i2]) {
//				return isInter(s1, i1, s2, i2 + 1, s3, i3 + 1);
//			} else {
//				return false;
//			}
//		} else {
//			if (s3[i3] == s1[i1]) {
//				return isInter(s1, i1 + 1, s2, i2, s3, i3 + 1)
//						|| isInter(s1, i1, s2, i2 + 1, s3, i3 + 1);
//			} else {
//				return false;
//			}
//		}
//	}
//
//public:
//	bool isInterleave(string s1, string s2, string s3) {
//		return isInter(s1, 0, s2, 0, s3, 0);
//	}
//};
//
