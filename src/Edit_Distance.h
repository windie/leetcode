class Solution {
    int minTri(int a, int b, int c){
        return min(min(a, b),c);
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > dp(word1.size()+1, vector<int> (word2.size()+1, 0));
        for(int i = 0; i<=word2.size(); i++){
            dp[0][i] = i;
        }
        for(int j = 0; j<=word1.size(); j++){
            dp[j][0] = j;
        }
        for(int i = 0; i<word1.size(); i++){
            for(int j = 0; j<word2.size(); j++){
                dp[i+1][j+1] = minTri(dp[i][j+1]+1, dp[i+1][j]+1, dp[i][j] + (word1[i]==word2[j]?0:1) );
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

// why compile error?

//class Solution {
//public:
//    int minDistance(string word1, string word2) {
//        vector<vector<int> > f(word1.size()+1, vector<int>(word2.size()+1, 0));
//        for(int i = 0; i<=word2.size(); i++){
//            f[0][i] = i;
//        }
//        for(int i = 0; i<=word1.size(); i++){
//            f[i][0] = i;
//        }
//        for(int i = 1; i<=word1.size(); i++){
//            for(int j = 1; j<=word2.size(); j++){
//                int tmp = min(f[i-1][j] + 1, f[i][j-1] +1);
//                f[i][j] = min(tmp, f[i-1]f[j-1] + (word1[i]==word2[j]?0:1));
//            }
//        }
//        return f[word1.size()][word2.size()];
//    }
//};

//class Solution {
//private:
//	int mindis(int a, int b, int c){
//		int m1 = a < b ? a : b;
//		return m1 < c ? m1 : c;
//	}
//public:
//    int minDistance(string word1, string word2) {
//    	int len1 = word1.size();
//    	int len2 = word2.size();
//    	if(len1==0) {
//    		return len2;
//    	}
//    	if(len2==0){
//    		return len1;
//    	}
//    	int dis[len1+1][len2+1];
//    	for(int i = 0;i <= len1;i++){
//    		dis[i][0] = i;
//    	}
//    	for(int j = 0;j <= len2;j++){
//    		dis[0][j] = j;
//    	}
//    	for(int i = 1;i <= len1;i++){
//        	for(int j = 1;j <= len2;j++) {
//        	   dis[i][j] = mindis(dis[i-1][j]+1, dis[i][j-1]+1, dis[i-1][j-1]+ (word1[i-1]==word2[j-1]?0:1));
//        	}
//    	}
//    	return dis[len1][len2];
//    }
//};
