class Solution {
	string connect(vector<string> &words, int begin, int end, int len, int L,
			bool isLeft) {
		string res;
		if (isLeft || begin == end) {
			for (int i = begin; i <= end; i++) {
				if (i != begin) {
					res += " ";
				}
				res += words[i];
			}
			res.append(L - res.size(), ' ');
			return res;
		}
		int avgspc = (L - len) / (end - begin);
		int extraspc = (L - len) % (end - begin);
		res = words[begin];
		for (int i = begin + 1; i <= end; i++) {
			string space(avgspc, ' ');
			if (extraspc > 0) {
				space.push_back(' ');
			}
			res += space;
			res += words[i];
			extraspc--;
		}
		return res;
	}
public:
	vector<string> fullJustify(vector<string> &words, int L) {
		int begin = 0;
		vector < string > res;
		int len = 0;
		for (int i = 0; i < words.size(); i++) {
			if (len + words[i].size() + i - begin > L) {
				res.push_back(connect(words, begin, i - 1, len, L, false));
				begin = i;
				len = words[i].size();
			}else{
				len += words[i].size();
			}
		}
		res.push_back(connect(words, begin, words.size() - 1, len, L, true));
		return res;
	}
};

//class Solution {
//private:
//	string getLine(vector<string> &words, int L, int startWordId, int endWordId,
//			int linecnt) {
//		string perLine = "";
//		int intervalNum = endWordId - startWordId;
//		if (intervalNum == 0) { // left align
//			perLine = words[startWordId];
//			perLine.append(L - words[startWordId].length(), ' ');
//		} else {
//			int avgSpcLen = (L - (linecnt - intervalNum)) / intervalNum;
//			int extraSpc = (L - (linecnt - intervalNum)) % intervalNum;
//			for (int j = startWordId; j < endWordId; j++) {
//				perLine += words[j];
//				perLine.append(avgSpcLen, ' ');
//				if (extraSpc > 0) {
//					perLine.append(" ");
//					extraSpc--;
//				}
//			}
//			perLine += words[endWordId];
//		}
//		return perLine;
//	}
//
//public:
//	vector<string> fullJustify(vector<string> &words, int L) {
//		vector < string > res;
//		if (words.size() == 0 || L == 0) {
//			return words;
//		}
//		int linecnt = 0;
//		int startWordId = -1, endWordId = -1;
//		for (int i = 0; i < words.size(); i++) {
//			int needspace = (
//					startWordId == -1 ?
//							words[i].length() : words[i].length() + 1);
//			if (needspace + linecnt <= L) { // add to word list
//				if (startWordId == -1) {
//					startWordId = i;
//				}
//				endWordId = i;
//				linecnt += needspace;
//			} else { // get a line
//				res.push_back(
//						getLine(words, L, startWordId, endWordId, linecnt));
//				linecnt = 0;
//				startWordId = -1;
//				endWordId = -1;
//				i--;
//			}
//		}
//		if (endWordId != -1) { // last line
//			string tmp = "";
//			for (int i = startWordId; i <= endWordId; i++) {
//				if (i > startWordId) {
//					tmp += " ";
//				}
//				tmp += words[i];
//			}
//			tmp.append(L - tmp.size(), ' ');
//			res.push_back(tmp);
//		}
//		return res;
//	}
//};
//
