#include<algorithm>
using namespace std;

//class Solution {
//public:
//	string getPermutation(int n, int k) {
//		char p1[10] = "123456789";
//		p1[n]='\0';
//		int i=1;
//		while (i < k && next_permutation(p1, p1 + n )){
//			i++;
//		}
//		return p1;
//	}
//};


class Solution {
public:
	string getPermutation(int n, int k) {
		char str[10] = "123456789";
		vector<bool> used(10, false);
		str[n] = '\0';
		int i = 1, p = 1;
		while (i <= n) {
			p *= i;
			i++;
		}
		k--;
		string res = "";
		for (i = 0; i < n ; i++) {
			p = p / (n-i);
			int th = k / p;
			k = k % p;
			int j, cnt = -1;
			for (j = 0; j < n; j++) {
				if (!used[j]) {
					cnt++;
				}
				if (cnt == th) {
					break;
				}
			}
			res.push_back(str[j]);
			used[j] = true;
		}
		return res;
	}
};
