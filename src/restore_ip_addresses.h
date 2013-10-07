class Solution {
	void f(vector<string> & cur, int begin, vector<vector<string> > &res,
			string s) {
		if (cur.size() == 4) {
			if (begin == s.size()) {
				res.push_back(cur);
			}
			return;
		}
		if (begin < s.size()) {
			string sub1 = s.substr(begin, 1);
			cur.push_back(sub1);
			f(cur, begin + 1, res, s);
			cur.pop_back();
		}
		if (begin + 1 < s.size()) {
			string sub2 = s.substr(begin, 2);
			if (sub2[0] != '0') {
				cur.push_back(sub2);
				f(cur, begin + 2, res, s);
				cur.pop_back();
			}
		}
		if (begin + 2 < s.size()) {
			string sub3 = s.substr(begin, 3);
			if (sub3[0] != '0') {
				int n = 0;
				sscanf(sub3.c_str(), "%d", &n);
				if (n < 256) {
					cur.push_back(sub3);
					f(cur, begin + 3, res, s);
					cur.pop_back();
				}
			}
		}
	}
public:
	vector<string> restoreIpAddresses(string s) {
		vector < vector<string> > res;
		vector<string> cur, rs;
		f(cur, 0, res, s);
		for (int i = 0; i < res.size(); i++) {
			string tmp = "";
			for (int j = 0; j < res[i].size(); j++) {
				if (j != 0) {
					tmp += ".";
				}
				tmp += res[i][j];
			}
			rs.push_back(tmp);
		}
		return rs;
	}
};
//class Solution {
//	void restoreIP(string s, int begin, vector<string> & curIp,
//			vector<string>& res) {
//		//
//		if (begin == s.length()) {
//			if (curIp.size() == 4) {
//				res.push_back(
//						curIp[0] + "." + curIp[1] + "." + curIp[2] + "."
//								+ curIp[3]);
//			}
//			return;
//		}
//		//
//		if (s.length() - begin > (4 - curIp.size()) * 3
//				|| s.length() - begin < (4 - curIp.size())) {
//			return;
//		}
//		//
//		if(curIp.size() == 4){
//			return;
//		}
//		// 1
//		curIp.push_back(s.substr(begin, 1));
//		restoreIP(s, begin + 1, curIp, res);
//		curIp.pop_back();
//		// 2
//		if(s.size() - begin < 2){
//			return;
//		}
//		string tmp = s.substr(begin, 2);
//		if(tmp[0] == '0'){
//			return;
//		}else{
//			curIp.push_back(tmp);
//			restoreIP(s, begin + 2, curIp, res);
//			curIp.pop_back();
//		}
//		// 3
//		if(s.size() - begin < 3){
//			return;
//		}
//		string temp = s.substr(begin, 3);
//		if(temp[0]=='0' || atoi(temp.c_str()) > 255){
//			return;
//		}else{
//			curIp.push_back(temp);
//			restoreIP(s, begin +3, curIp, res);
//			curIp.pop_back();
//		}
//	}
//
//public:
//	vector<string> restoreIpAddresses(string s) {
//		vector<string> cur, res;
//		restoreIP(s, 0, cur, res);
//		return res;
//	}
//};
