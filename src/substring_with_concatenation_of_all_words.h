class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.size()==0){
            return res;
        }
        unordered_map<string, int> m;
        for(int i = 0; i<words.size(); i++){
            auto it = m.find(words[i]);
            if(it == m.end()){
                m[words[i]] = 1;
            }else{
                m[words[i]]++;
            }
        }
        int wordlen = words[0].size();
        for(int i = 0; i + wordlen*words.size() <= s.size(); i++){
            unordered_map<string, int> tmp;
            for(int j = 1; j<=words.size(); j++){
                string sub = s.substr(i + (j-1) * wordlen, wordlen);
                auto it = m.find(sub);
                if(it == m.end()){
                    break;
                }else{
                    if(tmp.find(sub) == tmp.end()){
                        tmp[sub] = 1;
                    }else{
                        tmp[sub]++;
                    }
                }
            }
            if(tmp==m){
                res.push_back(i);
            }
        }
        return res;
    }
};

//class Solution {
//private:
//	bool isEquals(unordered_map<string, int> &map1, unordered_map<string, int> &map2) {
//		if(map1.size() == map2.size()) {
//			auto iter1 = map1.begin();
//			while(iter1!= map1.end()) {
//				auto iter2 = map2.find(iter1->first);
//				if(iter2 == map2.end() || iter1->second != iter2->second) {
//					return false;
//				}
//				++iter1;
//			}
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//public:
//	vector<int> findSubstring(string S, vector<string> &L) {
//		unordered_map<string, int> map;
//		for (int i = 0; i < L.size(); i++) {
//			if (map.find(L[i]) != map.end()) {
//				map[L[i]]++;
//			} else {
//				map[L[i]] = 1;
//			}
//		}
//		vector<int> res;
//		if (S.size() == 0 || L.size() == 0) {
//			return res;
//		}
//		for (int i = 0; i + L[0].size() * L.size() <= S.size(); i++) {
//			unordered_map<string, int> tmp;
//			//bool skip = false;
//			for (int j = i, num = 1; num <= L.size(); num++, j += L[0].size()) {
//				string substr = S.substr(j, L[0].size());
//				auto mapit = map.find(substr);
//				if(mapit==map.end()){
//				    //skip = true;
//					break;
//				}
//				auto it = tmp.find(substr);
//				if (it != tmp.end()) {
//					(*it).second++;
//					if(mapit->second < it->second){
//					    //skip = true;
//					    break;
//					}
//				} else {
//					tmp[substr] = 1;
//				}
//			}
//			if (isEquals(tmp, map)) {
//				res.push_back(i);
//			}
//		}
//		return res;
//	}
//};

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
