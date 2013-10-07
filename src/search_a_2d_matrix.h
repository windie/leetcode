class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0){
            return false;
        }
        int n = matrix.size(), m =matrix[0].size();
        int beginrow = 0, endrow = n-1, targetrow = -1;
        while(beginrow <= endrow){
            int midrow = beginrow + (endrow-beginrow)/2;
            if(target == matrix[midrow][0] || target == matrix[midrow][m-1]){
                return true;
            }else if(target > matrix[midrow][0] && target < matrix[midrow][m-1]){
                targetrow = midrow;
                break;
            }else if(target < matrix[midrow][0]){
                endrow = midrow-1;
            }else{
                beginrow = midrow+1;
            }
        }
        if(target == -1){
            return false;
        }
        int begin = 0, end = m-1;
        while(begin<=end){
            int mid = begin + (end-begin)/2;
            if(matrix[targetrow][mid] == target){
                return true;
            }else if(target < matrix[targetrow][mid]){
                end = mid-1;
            }else{
                begin = mid+1;
            }
        }
        return false;
    }
};

//class Solution {
//private:
//	int findRow(vector<vector<int> > &matrix, int target, int low, int high) {
//		if (high < low) {
//			return -1;
//		}
//		int mid = low + (high - low) / 2;
//		if (target < matrix[mid][0]) {
//			return findRow(matrix, target, low, mid - 1);
//		}
//		if (target > matrix[mid][matrix[mid].size() - 1]) {
//			return findRow(matrix, target, mid + 1, high);
//		}
//		return mid;
//	}
//	bool binarySearch(vector<int> array, int target, int low, int high) {
//		if (high < low) {
//			return false;
//		}
//		int mid = low + (high - low) / 2;
//		if (target == array[mid]) {
//			return true;
//		}
//		if (target < array[mid]) {
//			return binarySearch(array, target, low, mid - 1);
//		} else {
//			return binarySearch(array, target, mid + 1, high);
//		}
//	}
//public:
//	bool searchMatrix(vector<vector<int> > &matrix, int target) {
//		int m = matrix.size();
//		if (m == 0) {
//			return false;
//		}
//		int n = matrix[0].size();
//		if (n == 0) {
//			return false;
//		}
//		int row = findRow(matrix, target, 0, m - 1);
//		if (row == -1) {
//			return false;
//		}
//		return binarySearch(matrix[row], target, 0, n - 1);
//	}
//};
