//#include <unordered_map>
//
//class Solution {
//public:
//	vector<int> findSubstring(string S, vector<string> &L) {
//		unordered_map<string, int> dic;
//		for (int i = 0; i < L.size(); i++) {
//			if (dic.find(L[i]) == dic.end()) {
//				dic[L[i]] = 1;
//			} else {
//				dic[L[i]] = dic[L[i]] + 1;
//			}
//		}
//		unordered_map<string, int> tmp = dic;
//		vector<int> res;
//		if (L.size() == 0) {
//			return res;
//		}
//		for (int i = 0; i+ L[0].size()*L.size() <= S.size() ; i++) {
//			int cnt = 0;
//			for (int j = i; j < i + L[0].size()*L.size(); j += L[0].size()) {
//				string str = S.substr(j, L[0].size());
//				if (tmp.find(str) != tmp.end()
//						&& tmp[str] > 0) {
//					tmp[str]--;
//					cnt++;
//					if (cnt == L.size()) {
//						res.push_back(i);
//						break;
//					}
//				} else {
//					break;
//				}
//			}
//			tmp = dic;
//			cnt = 0;
//		}
//		return res;
//	}
//};
