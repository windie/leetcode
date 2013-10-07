class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size()==0 || triangle[0].size()==0){
            return 0;
        }
        vector<int> dp = triangle[triangle.size()-1];
        for(int j = triangle.size()-2; j>=0; j--){
            for(int i = 0; i<triangle[j].size(); i++){
                dp[i] = min(dp[i], dp[i+1]) + triangle[j][i];
            }
        }
        return dp[0];
    }
};

//class Solution {
//public:
//	int minimumTotal(vector<vector<int> > &triangle) {
//		if(triangle.size()==0 || triangle[0].size()==0){
//			return 0;
//		}
//		int level = triangle.size();
//		for (int i = level - 2; i >= 0; i--) {
//			for (int j = 0; j <= i; j++) {
//				triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1])
//						+ triangle[i][j];
//			}
//		}
//		return triangle[0][0];
//	}
//};
