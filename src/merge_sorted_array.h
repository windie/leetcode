class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int i = m-1, j = n-1, k = m+n-1;
		while(i>=0 && j>=0){
			if(A[i] > B[j]){
				A[k--] = A[i--];
			}else{
				A[k--] = B[j--];
			}
		}
		while(j>=0){
			A[k--] = B[j--];
		}
	}
};

//class Solution {
//public:
//	void merge(int A[], int m, int B[], int n) {
//		int i = 0, j = 0, k = 0;
//		int *C = new int[m + n];
//		while (i < m && j < n) {
//			if (A[i] < B[j]) {
//				C[k++] = A[i++];
//			} else {
//				C[k++] = B[j++];
//			}
//		}
//		if (i < m && j == n) {
//			int pos = m + n - 1;
//			int Apos = m - 1;
//			while (i <= Apos) {
//				A[pos--] = A[Apos--];
//			}
//		} else if (i == m && j < n) {
//			int pos = m + n - 1;
//			int Bpos = n - 1;
//			while (j <= Bpos) {
//				A[pos--] = B[Bpos--];
//			}
//		}
//		for (i = 0; i < k; i++) {
//			A[i] = C[i];
//		}
//	}
//};
