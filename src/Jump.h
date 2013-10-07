class Solution {
public:
    int jump(int A[], int n) {
    	int * minjump = new int[n];
    	int MAX = 65535;
    	minjump[n-1] = 0;
    	for(int i = n-2; i>=0; i--){
    		int tmpmin = MAX;
    		for(int j=i+1; j<=i+A[i] && j<n; j++){
    			if(minjump[j]+1 < tmpmin){
    				tmpmin = minjump[j]+1;
    			}
    			if(minjump[j] > 0 && j + A[j] <= i + A[i]){
    				if(minjump[j]-1 < tmpmin-1){
    					tmpmin = minjump[j];
    					j += A[j];
    				}
    			}
    		}
    		minjump[i]= tmpmin;
    	}
    	return minjump[0];
    }
};
