class Solution {
    string n2c(char n){
        string res;
        switch(n){
            case ('1'): res = ""; break;
            case ('2'): res = "abc"; break;
            case ('3'): res = "def"; break;
            case ('4'): res = "ghi"; break;
            case ('5'): res = "jkl"; break;
            case ('6'): res = "mno"; break;
            case ('7'): res = "pqrs"; break;
            case ('8'): res = "tuv"; break;
            case ('9'): res = "wxyz"; break;
            case ('0'): res = " "; break;
            default: break;
        }
        return res;
    }
    void rec(vector<string> &res, string &cur, string digits, int pos){
        if(pos == digits.size()){
            res.push_back(cur);
            return;
        }
        string s = n2c(digits[pos]);
        for(int i = 0; i<s.size(); i++){
            cur.push_back(s[i]);
            rec(res, cur, digits, pos+1);
            cur.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0){
            return res;
        }
        string cur;
        rec(res, cur, digits, 0);
        return res;
    }
};

//#include <iostream>
//using namespace std;
//
//class Solution {
//	char convertchar(int begin, int step) {
//		return 'a' + begin + step;
//	}
//	void recursiveGen(string& digits, int pos, string& curStr,
//			vector<string>& res) {
//		if (pos >= digits.size()) {
//			res.push_back(curStr);
//			return;
//		}
//		if (digits[pos] == '0') {
//			curStr.push_back(' ');
//			recursiveGen(digits, pos + 1, curStr, res);
//			curStr.erase(curStr.end() - 1, curStr.end());
//		} else if (digits[pos] == '1') {
//			recursiveGen(digits, pos + 1, curStr, res);
//		} else if (digits[pos] == '8') {
//			for (int i = 0; i < 3; i++) {
//				char ch1 = (digits[pos] - '2') * 3 + 'a' + 1 + i;
//				curStr.push_back(ch1);
//				recursiveGen(digits, pos + 1, curStr, res);
//				curStr.erase(curStr.end() - 1, curStr.end());
//			}
//		} else if (digits[pos] == '7') {
//			for (int i = 0; i < 4; i++) {
//				char ch1 = (digits[pos] - '2') * 3 + 'a' + i;
//				curStr.push_back(ch1);
//				recursiveGen(digits, pos + 1, curStr, res);
//				curStr.erase(curStr.end() - 1, curStr.end());
//			}
//		} else if (digits[pos] == '9') {
//			for (int i = 0; i < 4; i++) {
//				char ch1 = (digits[pos] - '2') * 3 + 'a' + 1 + i;
//				curStr.push_back(ch1);
//				recursiveGen(digits, pos + 1, curStr, res);
//				curStr.erase(curStr.end() - 1, curStr.end());
//			}
//		} else {
//			for (int i = 0; i < 3; i++) {
//				char ch1 = (digits[pos] - '2') * 3 + 'a' + i;
//				curStr.push_back(ch1);
//				recursiveGen(digits, pos + 1, curStr, res);
//				curStr.erase(curStr.end() - 1, curStr.end());
//			}
//		}
//	}
//
//public:
//	vector<string> letterCombinations(string digits) {
//		vector<string> res;
//		string curStr = "";
//		recursiveGen(digits, 0, curStr, res);
//		return res;
//	}
//};
