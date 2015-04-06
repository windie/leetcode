class Solution {
public:
    int trailingZeroes(int n) {
        int base = 5;
        int res = 0;
        while(n/base > 0){
        	res += n/base;
        	if(base > INT_MAX/5){
        	    break;
        	}
        	base *= 5;
        }
        return res;
    }
};