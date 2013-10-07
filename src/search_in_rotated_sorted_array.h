class Solution {
public:
    int search(int A[], int n, int target) {
        int begin = 0, end =n-1;
        while(begin<=end){
            int mid = begin + (end-begin)/2;
            if(A[mid] == target){
                return mid;
            }else if(A[mid] >= A[begin]){
                if(target > A[mid] || target < A[begin]){
                    begin = mid+1;
                }else {
                    end = mid-1;
                }
            }else{
                if(target < A[mid] || target > A[end]){
                    end = mid -1;
                }else{
                    begin = mid+1;
                }
            }
        }
        return -1;
    }
};

//class Solution {
//	int binarySearch(int A[], int low, int high, int target){
//		if(low>high){
//			return -1;
//		}
//		int mid = low + (high-low)/2;
//		if(A[mid] == target){
//			return mid;
//		}
//		if(low < mid-1 && A[low] < A[mid-1]){
//			if(target >= A[low] && target <= A[mid-1]){
//				return binarySearch(A, low, mid-1, target);
//			}else{
//				return binarySearch(A, mid+1, high, target);
//			}
//		}else if (mid+1 < high && A[mid+1] < A[high]) {
//			if(target >= A[mid+1] && target <= A[high]){
//				return binarySearch(A, mid+1, high, target);
//			}else{
//				return binarySearch(A, low, mid-1, target);
//			}
//		}else{
//			int res = binarySearch(A, low, mid-1, target);
//			if(-1 == res){
//				return binarySearch(A, mid+1, high, target);
//			}else{
//				return res;
//			}
//		}
//	}
//public:
//    int search(int A[], int n, int target) {
//    	if(n==0){
//    		return -1;
//    	}
//    	return binarySearch(A, 0, n-1, target);
//    }
//};
