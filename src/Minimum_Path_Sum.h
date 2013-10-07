#include <vector>

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
    	int m = grid.size();
    	int n;
    	if(m==0){
    		return 0;
    	}else{
    		n = grid[0].size();
    	}
    	int *f = new int[n];
    	f[0] = grid[0][0];
    	for(int i=1; i<n; i++){
    		f[i] = f[i-1] + grid[0][i];
    	}
    	for(int i=1; i<m; i++){
    		f[0] = f[0] + grid[i][0];
    		for(int j = 1; j<n; j++){
    			f[j] = min(f[j], f[j-1]) + grid[i][j];
    		}
    	}
    	return f[n-1];
    }
};
