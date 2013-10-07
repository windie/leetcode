//#include<iostream>
//using namespace std;
//
//int int_max = 2147483647;
//int int_min = -2147483648;
//
//class Solution {
//public:
//	int atoi(const char *str) {
//		const char *p = str;
//		int rs = 0;
//		bool isNeg = false;
//		bool isFirst = true;
//		bool isOverFlow = false;
//		bool isInCalculate = false;
//		while (*p != '\0') {
//			if (*p == ' ' && isFirst && !isInCalculate) {
//				p++;
//				continue;
//			}
//			if (*p == '+' && isFirst) {
//				isFirst = false;
//				p++;
//				continue;
//			}
//			if (*p == '-' && isFirst) {
//				isNeg = true;
//				isFirst = false;
//				p++;
//				continue;
//			}
//			if (*p >= '0' && *p <= '9') {
//				isInCalculate = true;
//				int pre = rs;
//				rs = rs * 10 + (*p) - '0';
//				if (((int_max -((*p) - '0'))/10 < pre )) {
//					isOverFlow = true;
//					break;
//				}
//				p++;
//				continue;
//			}
//			break;
//		}
//		if (isOverFlow) {
//			return isNeg ? int_min : int_max;
//		} else {
//			return isNeg ? -rs : rs;
//		}
//	}
//};
class Solution {
public:
	int atoi(const char *str) {
		int rs = 0;
		const char *p = str;
		bool isoverflow = false, isneg = false;
		int state = 1;
		while (*p) {
			if (state == 1 && *p != '+' && *p != '-'
					&& !(*p >= '0' && *p <= '9')) {
				if (*p == ' ') {
					p++;
					continue;
				} else {
					break;
				}
			}
			if (state == 1) {
				if (*p == '-' || *p == '+') {
					isneg = (*p == '-' ? true : false);
				} else if (*p >= '0' && *p <= '9') {
					rs = rs * 10 + *p - '0';
				}
				p++;
				state = 2;
				continue;
			}
			if (*p >= '0' && *p <= '9') {
				if ((INT_MAX - (*p - '0')) / 10 < rs) {
					isoverflow = true;
					break;
				}
				rs = rs * 10 + *p - '0';
				p++;
			} else {
				break;
			}
		}
		if (state == 1) {
			return 0;
		}
		if (isoverflow) {
			return !isneg ? INT_MAX : INT_MIN;
		} else {
			return !isneg ? rs : -rs;
		}
	}
};
