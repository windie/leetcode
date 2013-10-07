#include<iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> res(s.size(), 0);
        if(s.size()<2){
            return 0;
        }
        int mx = 0;
        for(int i = 1; i<s.size(); i++){
            if(s[i] == ')'){
                int pre = i-res[i-1]-1;
                if(pre>=0 && s[pre] == '('){
                    if(pre-1>=0){
                        res[i] = res[pre-1] + res[i-1] + 2;
                    }else{
                        res[i] = res[i-1] + 2;
                    }
                    mx = max(res[i], mx);
                }
            }
        }
        return mx;
    }
};

//class Solution {
//public:
//	int longestValidParentheses(string s) {
//		if (s.size() < 1) {
//			return 0;
//		}
//		int mx = 0;
//		vector<int> res(s.size(), 0);
//		for (int i = s.size() - 2; i >= 0; i--) {
//			if (s[i] == '(') {
//				int j = i + res[i + 1] + 1;
//				if (j < s.size() && s[j] == ')') {
//					if (j + 1 < s.size()) {
//						res[i] = res[j + 1] + res[i + 1] + 2;
//					} else {
//						res[i] = res[i + 1] + 2;
//					}
//					mx = max(mx, res[i]);
//				}
//			}
//		}
//		return mx;
//	}
//};
