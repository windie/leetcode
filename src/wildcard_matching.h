#include<iostream>
using namespace std;

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (!*p) {
			return !*s;
		}
		int len_p = strlen(p), len_s = strlen(s);

		// special filter
		int count_p = 0;
		const char* ptr = p;
		while (*ptr) {
			if (*ptr != '*')
				count_p++;
			ptr++;
		}
		if (count_p > len_s)
			return false;
		// special filter

		vector<bool> match(len_p, false);
		match[0] = *p == '*';
		for (int i = 1; i < len_p; i++) {
			match[i] = match[i - 1] && p[i] == '*';
		}
		bool diagnal = true;
		bool left = false;
		for (int i = 0; i < len_s; i++) {
			for (int j = 0; j < len_p; j++) {
				bool rs = false;
				if (p[j] == '*') {
					rs = diagnal || left || match[j]; // diagnal, left, up
				} else {
					rs = diagnal && (p[j] == s[i] || p[j] == '?');
				}
				diagnal = match[j];
				left = match[j] = rs;
			}
			left = false;
			diagnal = false;
		}
		return match[len_p - 1];
	}
};
