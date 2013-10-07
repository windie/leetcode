class Solution {
	void swap(int A[], int i, int j) {
		int tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}
public:
	int firstMissingPositive(int A[], int n) {
		if (n == 0) {
			return 1;
		}
		for (int i = 0; i < n;) {
			if (A[i] <= n && A[i] >= 1 && A[i] != i + 1
					&& A[A[i] - 1] != A[i]) {
				swap(A, i, A[i] - 1);
			} else {
				i++;
			}
		}
		for (int i = 0; i < n; i++) {
			if (A[i] != i + 1) {
				return i + 1;
			}
		}
		return n + 1;
	}
};

//class Solution {
//public:
//	int firstMissingPositive(int A[], int n) {
//		int MAX = 65536;
//		bool * hash = new bool[MAX];
//		for (int i = 0; i < MAX; i++) {
//			hash[i] = false;
//		}
//		for (int i = 0; i < n; i++) {
//			if (A[i] > 0) {
//				hash[A[i]] = true;
//			}
//		}
//		int first = -1, second = -1;
//		for (int i = 0; i < MAX; i++) {
//			if (hash[i] && first == -1) {
//				first = i;
//			}
//			if (hash[i] && first >= 0 && second == -1) {
//				second = i;
//			}
//		}
//		if (first == second && first != 1) {
//			return 1;
//		} else {
//			for (int i = first; i < MAX; i++) {
//				if (!hash[i]) {
//					return i;
//				}
//			}
//		}
//		delete[] hash;
//	}
//};
