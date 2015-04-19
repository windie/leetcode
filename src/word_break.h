class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        if(s.size() == 0){
            return true;
        }
        for(int i = 0; i<s.size(); i++){
            bool isvalid = false;
            for(int j = i; j>=0; j--){
                if(dp[j] && wordDict.find(s.substr(j, i-j+1)) != wordDict.end()){
                    isvalid = true;
                    break;
                }
            }
            dp[i+1] = isvalid;
        }
        return dp[s.size()];
    }
};


//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//	bool wordBreak(string s, unordered_set<string> &dict) {
//		vector<bool> dp(s.size() + 1, false);
//		if (s.size() == 0) {
//			return true;
//		}
//		dp[0] = true;
//		for (int i = 0; i < s.size(); i++) {
//			bool isvalid = false;
//			for (int j = i; j >= 0; j--) {
//				string substr = s.substr(j, i - j + 1);
//				if (dp[j] && dict.find(substr) != dict.end()) {
//					isvalid = true;
//					break;
//				}
//			}
//			dp[i + 1] = isvalid;
//		}
//		return dp[s.size()];
//	}
//};
