
class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n+1);
        res[0] = res[1] = 1;
        for(int i = 2; i<=n; i++){
            for(int j = 0; j<i; j++){
                res[i] += res[i-j-1] * res[j];
            }
        }
        return res[n];
    }
};

//class Solution {
//public:
//    int numTrees(int n) {
//        if(n==0 || n==1){
//            return 1;
//        }
//        int cnt = 0;
//        for(int i = 1; i<=n; i++){
//            cnt+= numTrees(n-i)*numTrees(i-1);
//        }
//        return cnt;
//    }
//};

//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//    int numTrees(int n) {
//    	vector<int> cnt(n+1, 0);
//    	cnt[0] = 1;
//    	cnt[1] = 1;
//    	for(int i=2; i<=n; i++){
//    		for(int k = 0; k < i; k++){
//    			cnt[i] += cnt[k] * cnt[i-k-1];
//    		}
//    	}
//    	return cnt[n];
//    }
//};
