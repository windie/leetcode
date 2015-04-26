class Solution {
    void filldic(vector<int> &dic, string s){
        for(int i = 0; i<s.size(); i++){
            dic[s[i]]++;
        }
    }
    bool isvalid(vector<int> &tdic, vector<int> &sdic){
        for(int i = 0; i<tdic.size(); i++){
            if(sdic[i] < tdic[i]){
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        vector<int> tdic(256, 0);
        vector<int> sdic(256, 0);
        filldic(tdic, t);
        int begin = -1, end = -1;
        for(int i = 0; i<s.size(); i++){
            if(!tdic[s[i]]){
                continue;
            }
            if(begin == -1){
                begin = i;
            }
            sdic[s[i]]++;
            if(isvalid(tdic, sdic)){
                end = i;
                break;
            }
        }
        if(begin == -1 || end == -1){
            return "";
        }
        int res = end - begin + 1;
        int resbegin = begin;
        int prebegin = begin;
        while(begin<s.size()){
            if(begin == prebegin){
                sdic[s[prebegin]]--;
            }
            begin++;
            if(tdic[s[begin]]==0){
                continue;
            }
            if(sdic[s[prebegin]] >= tdic[s[prebegin]]){
                if(end - begin + 1 < res){
                    res = end - begin + 1;
                    resbegin = begin;
                }
            }else{
                end++;
                for(; end<s.size(); end++){
                    if(tdic[s[end]]==0){
                        continue;
                    }
                    sdic[s[end]]++;
                    if(sdic[s[prebegin]] >= tdic[s[prebegin]]){
                        if(end - begin + 1 < res){
                            res = end - begin + 1;
                            resbegin = begin;
                        }
                        break;
                    }
                }
                if(end == s.size()){
                    break;
                }
            }
            prebegin = begin;
        }
        return s.substr(resbegin, res);
    }
};

//class Solution {
//	void find(string & S, string &T, int start, string &res, int* dic) {
//		int *pdic = new int[256];
//		memcpy(pdic, dic, sizeof(int) * 256);
//		int size = T.size();
//		int firstpos = -1, secondpos = -1;
//		int i = 0;
//		for (i = start; i < S.size(); i++) {
//			if (dic[S[i]] > 0 && firstpos == -1) {
//				firstpos = i;
//			} else if (dic[S[i]] > 0 && secondpos == -1) {
//				secondpos = i;
//			}
//			if (pdic[S[i]] > 0) {
//				pdic[S[i]]--;
//				size--;
//			}
//			if (size == 0) {
//				break;
//			}
//		}
//		delete[] pdic;
//		if (size == 0) {
//			{
//				string tmpstr = S.substr(firstpos, i - start + 1);
//				if (res.size() == 0 || tmpstr.size() < res.size()) {
//					res = tmpstr;
//				}
//			}
//			if (secondpos >= 0) {
//				find(S, T, secondpos, res, dic);
//			}
//		}
//	}
//public:
//	string minWindow(string S, string T) {
//		if (S.size() == 0 || S.size() < T.size()) {
//			return "";
//		}
//		int * dic = new int[256];
//		memset(dic, 0, sizeof(int) * 256);
//		for (int i = 0; i < T.size(); i++) {
//			dic[T[i]]++;
//		}
//		int i = 0;
//		for (i = 0; i < S.size(); i++) {
//			if (dic[S[i]] > 0) {
//				break;
//			}
//		}
//		string res = "";
//		find(S, T, i, res, dic);
//		delete[] dic;
//		return res;
//	}
//};

class Solution {
public:
	string minWindow(string S, string T) {
		if (S.size() == 0 || S.size() < T.size()) {
			return "";
		}
		int t_cnt[256] = { 0 };
		int s_cnt[256] = { 0 };
		for (int i = 0; i < T.size(); i++) {
			t_cnt[T[i]]++;
		}
		int begin = -1, end = -1;
		for (int i = 0; i < S.size(); i++) {
			if (t_cnt[S[i]] > 0 && begin == -1) {
				begin = i;
			}
			s_cnt[S[i]]++;
			if (t_cnt[S[i]] > 0) {
				bool isfound = true;
				for (int j = 0; j < 256; j++) {
					if (s_cnt[j] < t_cnt[j]) {
						isfound = false;
						break;
					}
				}
				if (isfound) {
					end = i;
					break;
				}
			}
		}
		if (begin == -1 || end == -1) {
			return "";
		}
		int minlen = end - begin + 1;
		int resbegin = begin;
		while (begin < S.size()) {
			s_cnt[S[begin]]--;
			if (t_cnt[S[begin]] <= s_cnt[S[begin]]) {
				begin++;
				if (end - begin + 1 < minlen) {
					resbegin = begin;
					minlen = end - begin + 1;
				}
				continue;
			} else {
				begin++;
				while (end < S.size()) {
					end++;
					if (end == S.size()) {
						break;
					}
					s_cnt[S[end]]++;
					if (S[end] == S[begin - 1]) {
						if (end - begin + 1 < minlen) {
							resbegin = begin;
							minlen = end - begin + 1;
						}
						break;
					}
				}
				if (end == S.size()) {
					break;
				}
			}
		}
		return S.substr(resbegin, minlen);
	}
};
