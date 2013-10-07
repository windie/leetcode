class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (*p == NULL) {
			return *s == NULL;
		}
		if (*(p + 1) == '*') {
			const char *ss = s;
			while (*ss && (*p == '.' || *p == *ss)) { // match more than one character
				if (isMatch(ss + 1, p + 2)) {
					return true;
				}
				ss++;
			}
			return isMatch(s, p + 2); //match zero character
		} else if (*p == '.') {
			return *s==NULL ? false: isMatch(s + 1, p + 1);
		} else {
			return (*s == *p) && isMatch(s + 1, p + 1);
		}
	}
};

//class Solution {
//public:
//	bool isMatch(const char *s, const char *p) {
//		if (*p == NULL) {
//			return *s == NULL ? true : false;
//		}
//		if (*(p + 1) != NULL && *(p + 1) == '*') {
//			for (int i = 0; *(s + i) != NULL && (*p == '.' || *p == *(s + i));
//					i++) {
//				if (isMatch(s + i + 1, p + 2)) {
//					return true;
//				}
//			}
//			return isMatch(s, p + 2);
//		}
//		if (*s != NULL && (*p == '.' || *p == *s)) {
//			return isMatch(s + 1, p + 1);
//		}
//		return false;
//	}
//};
