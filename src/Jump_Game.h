class Solution {
public:
    bool canJump(int A[], int n) {
    	if(n==1){
    		return true;
    	}
    	int require = 1;
    	for(int i=n-2; i>0; i--){
    		if(A[i]>=require){
    			require=1;
    			continue;
    		}else{
    			require++;
    		}
    	}
    	return A[0]>=require;
    }
};
