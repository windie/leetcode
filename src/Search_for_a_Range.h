class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int begin = -1, end =-1;
        int low =0, high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(A[mid] == target){
                begin = mid;
                high = mid-1;
            }else if(A[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        vector<int> res;
        if(begin==-1){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        low = begin;
        high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(A[mid] == target){
                end = mid;
                low = mid + 1;
            }else if(A[mid] > target){
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        res.push_back(begin);
        res.push_back(end);
        return res;
    }
};

//#include <vector>
//
//class Solution {
//public:
//	vector<int> searchRange(int A[], int n, int target) {
//		vector<int> res;
//		int low = 0, high = n - 1;
//		int lastpos = -1, firstpos = -1;
//		while (low <= high) {
//			int middle = low + (high - low) / 2;
//			if (A[middle] == target) {
//				lastpos = middle;
//				low = middle + 1;
//			} else if (target > A[middle]) {
//				low = middle + 1;
//			} else {
//				high = middle - 1;
//			}
//		}
//		if (lastpos == -1) {
//			res.push_back(-1);
//			res.push_back(-1);
//			return res;
//		}
//		low = 0, high = lastpos;
//		while (low <= high) {
//			int middle = low + (high - low) / 2;
//			if (A[middle] == target) {
//				firstpos = middle;
//				high = middle - 1;
//			} else if (target > A[middle]) {
//				low = middle + 1;
//			} else {
//				high = middle - 1;
//			}
//		}
//		res.push_back(firstpos);
//		res.push_back(lastpos);
//		return res;
//	}
//};
