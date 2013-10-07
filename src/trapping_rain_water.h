class Solution {
public:
	int trap(int A[], int n) {
		if(n<=2){
			return 0;
		}
		vector<int> leftheighest(n);
		int mmax = 0;
		for(int i=0; i<n; i++){
			leftheighest[i] = mmax;
			mmax = max(mmax, A[i]);
		}
		mmax = A[n-1];
		int res = 0;
		for(int i=n-2; i>=0; i--){
			int h = min(leftheighest[i], mmax);
			if(h>A[i]){
				res += h-A[i];
			}
			mmax = max(mmax, A[i]);
		}
		return res;
	}
};
