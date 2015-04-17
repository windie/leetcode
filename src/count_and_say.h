class Solution {
public:
    string countAndSay(int n) {
        vector<string> f(n);
        if(n==0){
            return "";
        }
        f[0] = "1";
        for(int i = 1; i<n; i++){
            string res="";
            int ch = f[i-1][0];
            int cnt = 1;
            for(int j = 1; j < f[i-1].size(); j++){
                if(f[i-1][j] == ch){
                    cnt++;
                }else{
                    res.push_back(cnt+'0');
                    res.push_back(ch);
                    ch = f[i-1][j];
                    cnt = 1;
                }
            }
            res.push_back(cnt+'0');
            res.push_back(ch);
            f[i] = res;
        }
        return f[n-1];
    }
};

//class Solution {
//    string f(int n){
//        if(n==0){
//            return "";
//        }
//        if(n==1){
//            return "1";
//        }
//        string s = f(n-1);
//        string res = "";
//        int cnt = 1;
//        char ch = s[0];
//        for(int i=1; i<s.size(); i++){
//            if(s[i] == ch){
//                cnt++;
//            }else{
//                res += (cnt+'0');
//                res += ch;
//                ch = s[i];
//                cnt = 1;
//            }
//        }
//        res += (cnt + '0');
//        res += ch;
//        return res;
//    }
//
//public:
//    string countAndSay(int n) {
//        return f(n);
//    }
//};

//#include <iostream>
//using namespace std;
//
//class Solution {
//	string next(string s) {
//		char ch = s[0];
//		int cnt = 1;
//		string res = "";
//		for (int i = 1; i < s.length(); i++) {
//			if (s[i] == ch) {
//				cnt++;
//			} else {
//				res.push_back(cnt + '0');
//				res.push_back(ch);
//				cnt = 1;
//				ch = s[i];
//			}
//		}
//		res.push_back(cnt + '0');
//		res.push_back(ch);
//		return res;
//	}
//public:
//	string countAndSay(int n) {
//		if (n == 0) {
//			return "";
//		}
//		string rs = "1";
//		for (int i = 1; i < n; i++) {
//			rs = next(rs);
//		}
//		return rs;
//	}
//};
