class Solution {
public:
    int numDistinct(string S, string T) {
        if(T.size() == 0){
            return S.size();
        }
        if(S.size()== 0){
            return 0;
        }
        vector<vector<int> > dp(T.size(), vector<int>(S.size(), 0));
        for(int i=0; i<S.size(); i++){
            if(i==0){
                if(S[0] == T[0]){
                    dp[0][0] = 1;
                }
            }else{
                if(S[i] == T[0]){
                    dp[0][i] = dp[0][i-1] +1;
                }else{
                    dp[0][i] = dp[0][i-1];
                }
            }
        }
        for(int i=1; i<T.size(); i++){
            for(int j = i; j<S.size(); j++){
                if(T[i] == S[j]){
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[T.size()-1][S.size()-1];
    }
};

//class Solution {
//public:
//	int numDistinct(string S, string T) {
//		int **f = new int*[S.size() + 1];
//		for (int i = 0; i <= S.size(); i++) {
//			f[i] = new int[T.size() + 1];
//		}
//		for (int i = 0; i <= T.size(); i++) {
//			if (i == 0) {
//				f[0][i] = 1;
//			} else {
//				f[0][i] = 0;
//			}
//		}
//		for (int i = 1; i <= S.size(); i++) {
//			f[i][0] = 1;
//			for (int j = 1; j <= T.size(); j++) {
//				if (S[i-1] != T[j-1]) {
//					f[i][j] = f[i - 1][j];
//				} else {
//					f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
//				}
//			}
//		}
//		int res =  f[S.size()][T.size()];
//		for(int i=0; i<=S.size(); i++){
//			delete[] f[i];
//		}
//		delete[] f;
//		return res;
//	}
//};
