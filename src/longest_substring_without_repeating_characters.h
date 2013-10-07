//class Solution {
//	void clearDic(bool * pDic, int num) {
//		for (int i = 0; i < num; i++) {
//			pDic[i] = false;
//		}
//	}
//	int maxSubString(string s, int begin, int max) {
//		if (begin == s.size()) {
//			return max;
//		}
//		int numchar = 256;
//		bool *pDic = new bool[numchar];
//		clearDic(pDic, numchar);
//
//		int cnt = 0;
//		for (int i = begin ; i < s.size(); i++) {
//			if (!pDic[s[i]]) {
//				pDic[s[i]] = true;
//				cnt++;
//			} else {
//				break;
//			}
//		}
//		if (cnt > max) {
//			max = cnt;
//		}
//		clearDic(pDic, numchar);
//		return maxSubString(s, begin+1, max);
//	}
//public:
//	int lengthOfLongestSubstring(string s) {
//		return maxSubString(s, 0, 0);
//	}
//};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int isExist[256];
    	for(int i = 0; i < 256; i++){
    		isExist[i]= -1;
    	}
    	int max = 0, curlen = 0, curbegin=0;
    	for(int i=0; i<s.size(); i++){
    		if(isExist[s[i]]==-1){
    			isExist[s[i]] = i;
    			curlen++;
    		}else{
    			if(curlen > max){
    				max = curlen;
    			}
    			int j = 0;
    			for(j=curbegin; j<=isExist[s[i]]; j++){
    				isExist[j] = -1;
    				curlen--;
    			}
    			curbegin = j;
    			isExist[s[i]] = i;
    			curlen++;
    		}
    	}
    	if(curlen>max){
    		max = curlen;
    	}
    	return max;
    }
};
