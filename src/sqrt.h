class Solution {
public:
	int sqrt(int x) {
		int begin = 1, end = x / 2 + 1;

		while (begin <= end) {
			int64_t mid = begin + (end - begin) / 2;
			if (mid * mid == x) {
				return mid;
			} else if (mid * mid > x) {
				end = mid - 1;
			} else {
				begin = mid + 1;
			}
		}
		return begin-1;
	}
};

//class Solution {
//public:
//	int sqrt(int x) {
//		double xn1 = 1.0;
//		while (fabs(xn1 * xn1 - x) > 1E-6) {
//			xn1 = xn1 / 2 + x * 1.0 / 2 / xn1;
//		}
//		return (int) xn1;
//	}
//};
