//class Solution {
//private:
//	int find(int A[], int begin, int end, int target){
//		int middle = (begin + end)/2;
//		if(A[middle] == target){
//			return middle;
//		}else if(A[middle] > target){
//			if(begin <= middle-1){
//				return find(A, begin, middle-1, target);
//			}else{
//				if(target > A[begin])
//					return begin+1;
//				else
//					return begin;
//			}
//		}else{
//			if(middle+1 <= end)
//			{
//				return find(A, middle+1, end, target);
//			}else{
//				if(target > A[end])
//					return end+1;
//				else
//					return end;
//			}
//		}
//	}
//public:
//    int searchInsert(int A[], int n, int target) {
//    	if(n==0) return 0;
//    	return find(A, 0, n-1, target);
//    }
//};


class Solution {
public:
    int searchInsert(int A[], int n, int target) {
    	int low = 0;
    	int high = n-1;
    	while(low <= high){
    		int middle = low + (high-low)/2;
    		if(A[middle] == target){
    			return middle;
    		}else if(target > A[middle]){
    			low = middle+1;
    		}else{
    			high = middle-1;
    		}
    	}
    	return low;
    }
};
