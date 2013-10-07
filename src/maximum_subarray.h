class Solution {
private:
	int maxVal (int a, int b){ return a>b ? a : b;}
public:
    int maxSubArray(int A[], int n) {
    	if(n==0){
    		return 0;
    	}
    	int range = A[n-1];
    	int all = A[n-1];
    	for(int i=n-2; i>=0; i--){
    		range = maxVal(A[i], range+A[i]);
    		all = maxVal(range, all);
    	}
    	return all;
    }
};
