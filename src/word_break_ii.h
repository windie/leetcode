class Solution {
    void checkvalid(string s, unordered_set<string>& wordDict, vector<bool> &valid){
        valid[0] = true;
        for(int i = 0; i<s.size(); i++){
            bool tmp = false;
            for(int j = i; j>=0; j--){
                if(valid[j] && wordDict.find(s.substr(j, i-j+1)) != wordDict.end()){
                    tmp = true;
                    break;
                }
            }
            valid[i+1] = tmp;
        }
    }
    void rec(int begin, string s, unordered_set<string>& wordDict, vector<string> &res, string &cur, vector<bool> valid){
        if(begin == s.size()){
            res.push_back(cur);
            return;
        }
        for(int i = begin; i<s.size(); i++){
            if(!valid[i+1]){
                continue;
            }
            string sub = s.substr(begin, i-begin+1);
            if(wordDict.find(sub) != wordDict.end()){
                int len = cur.size();
                if(cur.size()==0){
                    cur=sub;
                }else{
                    cur += " ";
                    cur += sub;
                }
                rec(i+1, s, wordDict, res, cur, valid);
                cur = cur.substr(0, len);
            }
        }
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if(s.size()==0){
            return res;
        }
        vector<bool> valid(s.size()+1, false);
        checkvalid(s, wordDict, valid);
        string cur;
        if(valid[s.size()]){
            rec(0, s, wordDict, res, cur, valid);
        }
        return res;
    }
};

//class Solution {
//	bool wordBreakValid(string s, unordered_set<string> &dict) {
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
//
//	void recursive(string &s, int begin, string &cur, vector<string> &res,
//			unordered_set<string> &dict) {
//		if (begin == s.size()) {
//			res.push_back(cur);
//			return;
//		}
//		for (int i = begin; i < s.size(); i++) {
//			string substr = s.substr(begin, i - begin + 1);
//			if (dict.find(substr) != dict.end()) {
//				int len = cur.length();
//				if (cur.size() != 0) {
//					cur += " ";
//				}
//				cur += substr;
//				recursive(s, i+1, cur, res, dict);
//				cur = cur.substr(0, len);
//			}
//		}
//	}
//public:
//	vector<string> wordBreak(string s, unordered_set<string> &dict) {
//		vector < string > res;
//		if(wordBreakValid(s, dict)){
//			string cur;
//			recursive(s, 0, cur, res, dict);
//		}
//		return res;
//	}
//};
