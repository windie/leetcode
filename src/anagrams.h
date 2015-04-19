struct newstr{
    string str;
    int idx;
};
bool cmp(newstr &a, newstr &b){
    return a.str<b.str;
}

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<newstr> s;
        for(int i = 0; i<strs.size(); i++){
            newstr tmp;
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            tmp.str = temp;
            tmp.idx = i;
            s.push_back(tmp);
        }
        sort(s.begin(), s.end(), cmp);
        vector<string> res;
        if(strs.size()<=1){
            return res;
        }
        int pre = 0;
        int cnt = 1;
        for(int i = 1; i<s.size(); i++){
            if(s[pre].str == s[i].str){
                if(cnt == 1){
                    res.push_back(strs[s[pre].idx]);
                }
                res.push_back(strs[s[i].idx]);
                cnt++;
            }else{
                pre = i;
                cnt = 1;
            }
        }
        return res;
    }
};

//struct newstr {
//	string str;
//	int idx;
//};
//
//bool cmp(newstr a, newstr b) {
//	return a.str < b.str;
//}
//
//class Solution {
//public:
//	vector<string> anagrams(vector<string> &strs) {
//		vector<newstr> vecstr;
//		for (int i = 0; i < strs.size(); i++) {
//			newstr tmp;
//			string s = strs[i];
//			sort(s.begin(), s.end());
//			tmp.str = s;
//			tmp.idx = i;
//			vecstr.push_back(tmp);
//		}
//		sort(vecstr.begin(), vecstr.end(), cmp);
//		vector < string > res;
//		bool isfirst = true;
//		for (int i = 1; i < vecstr.size(); i++) {
//			if (vecstr[i].str == vecstr[i - 1].str) {
//				res.push_back(strs[vecstr[i].idx]);
//				if (isfirst) {
//					res.push_back(strs[vecstr[i - 1].idx]);
//					isfirst = false;
//				}
//			} else {
//				isfirst = true;
//			}
//		}
//		return res;
//	}
//};

//#include<iostream>
//using namespace std;
//
//struct newSTR {
//	string str;
//	int index;
//};
//
//bool comp(newSTR s1, newSTR s2) {
//	return s1.str < s2.str;
//}
//
//class Solution {
//public:
//	vector<string> anagrams(vector<string> &strs) {
//		vector<string> res;
//		vector<newSTR> newstrs;
//		for (int i = 0; i < strs.size(); i++) {
//			newSTR tmp;
//			tmp.str = strs[i];
//			sort(tmp.str.begin(), tmp.str.end());
//			tmp.index = i;
//			newstrs.push_back(tmp);
//		}
//		sort(newstrs.begin(), newstrs.end(), comp);
//		int begin = -1, cnt = 1;
//		vector<vector<int> > items;
//		for (int i = 1; i < newstrs.size(); i++) {
//			if (newstrs[i].str.compare(newstrs[i - 1].str) != 0) {
//				if (begin != -1) {
//					vector<int> tmp;
//					tmp.push_back(begin);
//					tmp.push_back(cnt);
//					items.push_back(tmp);
//					begin = -1;
//					cnt = 1;
//				}
//				continue;
//			} else {
//				if (begin == -1) {
//					begin = i - 1;
//				}
//				cnt++;
//			}
//		}
//		if (begin != -1) {
//			vector<int> tmp;
//			tmp.push_back(begin);
//			tmp.push_back(cnt);
//			items.push_back(tmp);
//		}
//		for(int i=0; i<items.size(); i++){
//			for (int j = items[i][0]; j < items[i][0] + items[i][1]; j++) {
//				res.push_back(strs[newstrs[j].index]);
//			}
//		}
//		return res;
//	}
//};
