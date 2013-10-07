class Solution {

	int64_t dividePos(int64_t dividend, int64_t divisor) {
		if (dividend < divisor) {
			return 0;
		}
		int64_t power = 0;
		while ((divisor << power) <= dividend) {
			++power;
		}
		int64_t part = 1U << (power - 1);
		return part + dividePos(dividend - (divisor<< (power-1)), divisor);
	}
public:
	int divide(int dividend, int divisor) {
		bool isNeg = false;
		int64_t a = dividend, b = divisor;
		if (a < 0) {
			a = -a;
			isNeg = !isNeg;
		}
		if (b < 0) {
			b = -b;
			isNeg = !isNeg;
		}
		int res = dividePos(a, b);
		if (isNeg) {
			return -res;
		} else {
			return res;
		}
	}
};
