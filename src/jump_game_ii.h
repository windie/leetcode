class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() < 2){
            return 0;
        }
        int cnt= 0, step_max = 0, one_more_step_max = 0;
        // step_max: distance can jump using cnt steps
        // one_more_step_max: distance can jump using cnt+1 steps
        for(int i = 0; i<nums.size(); i++){
            if(i > step_max){
                cnt++;
                step_max = one_more_step_max;
            }
            one_more_step_max = max(one_more_step_max, i+nums[i]);
        }
        return cnt;

    }
};

//// dp: time limit exceeded
//class Solution {
//public:
//    int jump(int A[], int n) {
//        if(n <=1){
//            return 0;
//        }
//        int *minstep = new int[n];
//        minstep[n-1] = 0;
//        for(int i = n-2; i>=0; i--){
//            if(A[i] >= n-i-1){
//                minstep[i] = 1;
//                continue;
//            }else if(A[i] == 0){
//                minstep[i] = INT_MAX;
//                continue;
//            }
//            int minV= INT_MAX;
//            for(int j = i+1; j<n && j <= A[i] + i; j++){
//                minV = min(minV, minstep[j]+1);
//            }
//            minstep[i]  = minV;
//        }
//        return minstep[0];
//    }
//};

//class Solution {
//public:
//    int jump(int A[], int n) {
//    	int * minjump = new int[n];
//    	int MAX = 65535;
//    	minjump[n-1] = 0;
//    	for(int i = n-2; i>=0; i--){
//    		int tmpmin = MAX;
//    		for(int j=i+1; j<=i+A[i] && j<n; j++){
//    			if(minjump[j]+1 < tmpmin){
//    				tmpmin = minjump[j]+1;
//    			}
//    			if(minjump[j] > 0 && j + A[j] <= i + A[i]){
//    				if(minjump[j]-1 < tmpmin-1){
//    					tmpmin = minjump[j];
//    					j += A[j];
//    				}
//    			}
//    		}
//    		minjump[i]= tmpmin;
//    	}
//    	return minjump[0];
//    }
//};
