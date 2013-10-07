int MAX = 65535;

class Solution {
	int find_kth_in_two_sorted_array(int A[], int nA, int B[], int nB, int k) {
		int l = max(0, k - nB);
		int u = min(nA, k);
		while (l < u) {
			int x = l + (u - l) / 2;
			int A_x_1 = x <= 0 ? -MAX : A[x - 1];
			int A_x = x >= nA ? MAX : A[x];
			int B_k_x_1 = k - x <= 0 ? -MAX : B[k - x - 1];
			int B_k_x = k - x >= nB ? MAX : B[k - x];
			if (A_x < B_k_x_1) {
				l = x + 1;
			} else if (A_x_1 > B_k_x) {
				u = x - 1;
			} else {
				return max(A_x_1, B_k_x_1);
			}
		}
		int A_l_1 = l <= 0 ? -MAX : A[l - 1];
		int B_k_l_1 = k - l - 1 < 0 ? -MAX : B[k - l - 1];
		return max(A_l_1, B_k_l_1);
	}
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int k = (m + n) / 2;
		if ((m + n) % 2) {
			return find_kth_in_two_sorted_array(A, m, B, n, k + 1);
		} else {
			return (find_kth_in_two_sorted_array(A, m, B, n, k)
					+ find_kth_in_two_sorted_array(A, m, B, n, k + 1)) / 2.0;
		}
	}
};
