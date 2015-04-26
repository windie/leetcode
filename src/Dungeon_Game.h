class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if(dungeon.size() == 0 || dungeon[0].size() == 0){
            return -1;
        }
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = dungeon[m-1][n-1] < 0 ? -dungeon[m-1][n-1]+1 : 1;
        for(int i = m-2; i>=0; i--){
            dp[i][n-1] = max(dp[i+1][n-1] - dungeon[i][n-1], 1);
        }
        for(int j = n-2; j>=0; j--){
            dp[m-1][j] = max(dp[m-1][j+1] - dungeon[m-1][j], 1);
        }
        for(int i = m-2; i>=0; i--){
            for(int j = n-2; j>=0; j--){
                dp[i][j] = max(1, min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};