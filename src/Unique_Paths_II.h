class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.size()==0){
            return 0;
        }
        vector<int> num(obstacleGrid[0].size(), 0);
        for(int i=0; i<obstacleGrid[0].size(); i++){
            if(obstacleGrid[0][i]==1){
                int j=i;
                while(j<obstacleGrid[0].size()){
                    num[j++] = 0;
                }
                break;
            }else{
                num[i] = 1;
            }
        }
        for(int i=1; i<obstacleGrid.size(); i++){
            if(obstacleGrid[i][0] == 1){
                num[0] = 0;
            }
            for(int j=1; j<obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j]==1){
                    num[j] = 0;
                }else{
                    num[j] = num[j-1] + num[j];
                }
            }
        }
        return num[obstacleGrid[0].size()-1];
    }
};

//#include <vector>
//
//class Solution {
//public:
//    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
//    	int f[100];
//    	int m = obstacleGrid.size();
//    	int n;
//    	if(m>0){
//    		n = obstacleGrid[0].size();
//    	}else{
//    		n = 0;
//    	}
//    	for(int i = 0; i<n; i++){
//    		if(obstacleGrid[0][i]==1){
//    			f[i]=0;
//    		}else{
//    			if(i==0){
//    				f[i] = 1;
//    			}
//    			else{
//    				f[i] = f[i-1];
//    			}
//    		}
//    	}
//    	for(int i = 1; i<m; i++){
//    		if(obstacleGrid[i][0]==1){
//    			f[0]=0;
//    		}
//    		for(int j = 1; j<n; j++){
//    			if(obstacleGrid[i][j]==1){
//    				f[j]=0;
//    			}else{
//    				f[j]=f[j]+f[j-1];
//    			}
//    		}
//    	}
//    	return f[n-1];
//    }
//};
