class Solution {
public:
	int reverse(int x) {
		int val = x > 0 ? x : -x;
		int res = 0;
		while(val>0){
			res = (res * 10 + val % 10);
			val /= 10;
		}
		return x >0 ? res : -res;
	}
};
