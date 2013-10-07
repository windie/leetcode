#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.size() == 0) {
			return "";
		}
		if (strs.size() == 1) {
			return strs[0];
		}

		int pos = 0;
		string res = "";
		while (pos < strs[0].length()) {
			bool isCommon = true;
			for (int i = 1; i < strs.size(); i++) {

				if(pos == strs[i].length() || strs[i][pos] != strs[0][pos]){
					isCommon = false;
					break;
				}
			}
			if(isCommon){
				res.push_back(strs[0][pos]);
				pos++;
			}else{
				break;
			}
		}
		return res;
	}
};
