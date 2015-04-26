class Solution {
public:
    int minCut(string s) {
        vector<vector<bool> > valid(s.size(), vector<bool>(s.size(), false));
        vector<int> dp(s.size()+1);
        for(int i = 0; i<=s.size(); i++){
            dp[i] = s.size()-i;
        }
        for(int i = s.size()-1; i>=0; i--){
            for(int j = i; j<s.size(); j++){
                if(s[i] == s[j] && (j-i<=2 || valid[i+1][j-1])){
                    valid[i][j] = true;
                    dp[i] = min(dp[i], dp[j+1]+1);
                }
            }
        }
        return dp[0]-1;
    }
};

//class Solution {
//public:
//	int minCut(string s) {
//		int D[s.length()+1];
//		bool P[s.length()][s.length()];
//		for (int i = 0; i <= s.length(); i++) {
//			D[i] = s.length() - i;
//		}
//		for (int i = 0; i < s.length(); i++) {
//			for (int j = 0; j < s.length(); j++) {
//				P[i][j] = false;
//			}
//		}
//		for (int i = s.length() - 1; i >= 0; i--) {
//			for (int j = i; j < s.length(); j++) {
//				if (s[i] == s[j] && ((j - i < 2) || P[i + 1][j - 1])) {
//					P[i][j] = true;
//					D[i] = min(D[i], 1 + D[j + 1]);
//				}
//			}
//		}
//		return D[0]-1;
//	}
//};

//class Solution {
//	private:
//	bool isValid(const char * s, int size) {
//		for (int i = 0; i < size / 2; i++) {
//			if (s[i] != s[size - i - 1]) {
//				return false;
//			}
//		}
//		return true;
//	}
//	void recursive(const char * s, int size, int begin,
//			vector<string> & curStrSet, vector<vector<string> >& res, int &min) {
//		if (begin == size) {
//			if (!curStrSet.empty()) {
//				res.push_back(curStrSet);
//				if(curStrSet.size()-1 < min){
//					min = curStrSet.size()-1;
//				}
//			}
//			return;
//		}
//		for (int i = begin; i < size; i++) {
//			if (isValid(s + begin, i - begin + 1)) {
//				string str(s + begin, i - begin + 1);
//				curStrSet.push_back(str);
//				if(curStrSet.size()-1 <= min){
//					recursive(s, size, i + 1, curStrSet, res, min);
//				}
//				curStrSet.pop_back();
//			}
//		}
//	}
//public:
//    int minCut(string s) {
//		vector < string > part;
//		vector < vector<string> > res;
//		int min = s.size();
//		recursive(s.c_str(), s.length(), 0, part, res, min);
//		return min;
//    }
//};
