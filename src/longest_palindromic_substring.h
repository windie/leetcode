// 不是最优解
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty() || s.size()==1){
            return s;
        }
        int len = s.size();
        bool dp[len][len];
        int res = 1, start =0;
        int i, j;
        for(j = 0; j < len; j++){
            for(i = 0; i < j; i++){
                if(s[i] == s[j] && ((j-i<2) || dp[i+1][j-1])){
                    dp[i][j] = true;
                }else{
                    dp[i][j] = false;
                }
                if(dp[i][j] && j-i+1>res){
                    res = j-i+1;
                    start = i;
                }
            }
            dp[j][j] = true;
        }
        return s.substr(start, res);
    }
};

//class Solution {
//public:
//    string longestPalindrome(string s) {
//        if(s.size()==0 || s.size()==1){
//            return s;
//        }
//        vector<vector<bool> > p(s.size(), vector<bool>(s.size(), false));
//        for(int i =0; i<s.size(); i++){
//            for(int j=0; j<s.size(); j++){
//                if(i>=j){
//                    p[i][j] = true;
//                }
//            }
//        }
//        int maxlen = 1, begin = 0;
//        for(int k= 1; k<s.size(); k++){
//            for(int i = 0; i+k <s.size(); i++){
//                int j = i + k;
//                if(s[i] == s[j]){
//                    p[i][j] = p[i+1][j-1];
//                }else{
//                    p[i][j] = false;
//                }
//                if(p[i][j] && j-i+1 > maxlen){
//                    maxlen = j-i+1;
//                    begin = i;
//                }
//            }
//        }
//        return s.substr(begin, maxlen);
//    }
//};

//class Solution {
//private:
//	void range(string &s, int pre, int nxt, int &begin, int &len) {
//		while (pre >= 0 && nxt < s.size()) {
//			if (s[pre] == s[nxt]) {
//				len += 2;
//				begin = pre;
//				pre--;
//				nxt++;
//			} else {
//				break;
//			}
//		}
//	}
//
//public:
//	string longestPalindrome(string s) {
//		if (s.length() == 0) {
//			return 0;
//		}
//		int maxlen = 0;
//		int begin = 0;
//		for (int i = 0; i < s.size(); i++) {
//			// case 1
//			int pre = i - 1, nxt = i + 1;
//			int curbegin = i, curlen = 1;
//			range(s, pre, nxt, curbegin, curlen);
//			if (curlen > maxlen) {
//				maxlen = curlen;
//				begin = curbegin;
//			}
//			// case 2
//			if (i + 1 < s.size() && s[i + 1] == s[i]) {
//				pre = i - 1;
//				nxt = i + 2;
//				curbegin = i, curlen = 2;
//				range(s, pre, nxt, curbegin, curlen);
//			}
//			if (curlen > maxlen) {
//				maxlen = curlen;
//				begin = curbegin;
//			}
//		}
//		return s.substr(begin, maxlen);
//	}
//};
