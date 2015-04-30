class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftmax(height.size());
        int res = 0;
        if(height.size()<=2){
            return 0;
        }
        leftmax[0] = height[0];
        int maxval = height[0];
        for(int i = 1; i<height.size(); i++){
            if(height[i] > maxval){
                maxval = height[i];
            }
            leftmax[i] = maxval;
        }
        int rightmax = height[height.size()-1];
        for(int i = height.size()-2; i>=1; i--){
            rightmax = max(height[i], rightmax);
            int h = min(leftmax[i-1], rightmax);
            if(h > height[i]){
                res += (h-height[i]);
            }
        }
        return res;
    }
};

//class Solution {
//public:
//	int trap(int A[], int n) {
//		if(n<=2){
//			return 0;
//		}
//		vector<int> leftheighest(n);
//		int mmax = 0;
//		for(int i=0; i<n; i++){
//			leftheighest[i] = mmax;
//			mmax = max(mmax, A[i]);
//		}
//		mmax = A[n-1];
//		int res = 0;
//		for(int i=n-2; i>=0; i--){
//			int h = min(leftheighest[i], mmax);
//			if(h>A[i]){
//				res += h-A[i];
//			}
//			mmax = max(mmax, A[i]);
//		}
//		return res;
//	}
//};
