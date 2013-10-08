enum Status {
	START, SIGNAL, INT, POINT, FRAC, E, SINGAL_E, INT_E
};

class Solution {
	const char * trim(const char *s, int& len) {
		const char *p = s;
		while (*p == ' ') {
			p++;
		}
		const char *ss = p;
		while (*ss) {
			len++;
			ss++;
		}
		ss--;
		while (*ss == ' ') {
			ss--;
			len--;
		}
		return p;
	}
public:
	bool isNumber(const char *s) {
		int len = 0;
		const char * p = trim(s, len);
		Status status = START;
		bool hasINT = false, hasFRAC = false;
		for (int i = 0; i < len; i++) {
			char ch = *p;
			p++;
			switch (status) {
			case START:
				if (ch == '+' || ch == '-') {
					status = SIGNAL;
				} else if (ch == '.') {
					status = POINT;
				} else if (ch >= '0' && ch <= '9') {
					status = INT;
					hasINT = true;
				} else {
					return false;
				}
				break;
			case SIGNAL:
				if (ch == '.') {
					status = POINT;
				} else if (ch >= '0' && ch <= '9') {
					status = INT;
					hasINT = true;
				} else {
					return false;
				}
				break;
			case INT:
				if (ch == '.') {
					status = POINT;
				} else if (ch >= '0' && ch <= '9') {
					status = INT;
				} else if (ch == 'E' || ch == 'e') {
					status = E;
				} else {
					return false;
				}
				break;
			case POINT:
				if (ch >= '0' && ch <= '9') {
					status = FRAC;
					hasFRAC = true;
				} else if (ch == 'E' || ch == 'e') {
					status = E;
				} else {
					return false;
				}
				break;
			case FRAC:
				if (ch >= '0' && ch <= '9') {
					status = FRAC;
				} else if (ch == 'E' || ch == 'e') {
					status = E;
				} else {
					return false;
				}
				break;
			case E:
				if (ch == '+' || ch == '-') {
					status = SINGAL_E;
				} else if (ch >= '0' && ch <= '9') {
					status = INT_E;
				} else {
					return false;
				}
				break;
			case SINGAL_E:
			case INT_E:
				if (ch >= '0' && ch <= '9') {
					status = INT_E;
				} else {
					return false;
				}
				break;
			}
		}
		if (status == E || status == SIGNAL || status == SINGAL_E
				|| status == START) {
			return false;
		}
		return hasINT || hasFRAC;
	}
};
