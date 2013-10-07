using namespace std;

class Solution {
public:
	int singleNumber(int A[], int n) {
		vector<int> digit(32, 0);
		int val = 1;
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < n; j++) {
				if (val & A[j]) {
					digit[i]++;
				}
			}
			val <<= 1;
		}
		val = 1;
		int res = 0;
		for (int i = 0; i < 32; i++) {
			if (digit[i] % 3) {
				res += val;
			}
			val <<= 1;
		}
		return res;
	}
};
