class Solution {
	bool search(int A[], int begin, int end, int target) {
		if (begin > end) {
			return false;
		}
		int mid = begin + (end - begin) / 2;
		if (A[mid] == target) {
			return true;
		}
		if (A[mid] > A[begin]) {
			if (target < A[begin] || target > A[mid]) {
				return search(A, mid + 1, end, target);
			} else {
				return search(A, begin, mid - 1, target);
			}
		} else if (A[mid] < A[end]) {
			if (target < A[mid] || target > A[end]) {
				return search(A, begin, mid - 1, target);
			} else {
				return search(A, mid + 1, end, target);
			}
		} else {
			return search(A, begin, mid - 1, target)
					|| search(A, mid + 1, end, target);
		}
	}

public:
	bool search(int A[], int n, int target) {
		return search(A, 0, n - 1, target);
	}
};
//class Solution {
//	bool binarySearch(int A[], int low, int high, int target) {
//		if (high < low) {
//			return false;
//		}
//		int mid = low + (high - low) / 2;
//		if (A[mid] == target) {
//			return true;
//		}
//		if (A[low] < A[mid]) {
//			if (target >= A[low] && target <= A[mid]) {
//				return binarySearch(A, low, mid - 1, target);
//			} else {
//				return binarySearch(A, mid + 1, high, target);
//			}
//		} else if (A[low] > A[mid]) {
//			if (target >= A[mid] && target <= A[high]) {
//				return binarySearch(A, mid + 1, high, target);
//			} else {
//				return binarySearch(A, low, mid - 1, target);
//			}
//		} else {
//			bool res = binarySearch(A, mid + 1, high, target);
//			if (!res) {
//				return binarySearch(A, low, mid - 1, target);
//			} else {
//				return res;
//			}
//		}
//	}
//public:
//	bool search(int A[], int n, int target) {
//		return binarySearch(A, 0, n - 1, target);
//	}
//};
