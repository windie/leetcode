class Solution {
    int findmid(vector<int> &nums1, int b1, int len1, vector<int> &nums2, int b2, int len2, int k){
        if(len1 <= 0){
            return nums2[k-1];
        }
        if(len2 <= 0){
            return nums1[k-1];
        }
        if(k<=1){
            return min(nums1[b1], nums2[b2]);
        }
        if(nums1[b1+len1/2] <= nums2[b2+len2/2]){
            if(len1/2+len2/2+1 >= k){
                return findmid(nums1, b1, len1, nums2, b2, len2/2, k);
            }else{
                return findmid(nums1, b1 + len1/2 + 1, len1 - len1/2 - 1, nums2, b2, len2, k - len1/2 - 1);
            }
        }else{
            if(len1/2+len2/2+1 >= k){
                return findmid(nums1, b1, len1/2, nums2, b2, len2, k);
            }else{
                return findmid(nums1, b1, len1, nums2, b2 + len2/2 + 1, len2 - len2/2 - 1, k - len2/2 - 1);
            }
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if(len%2==0){
            return (findmid(nums1, 0, nums1.size(), nums2, 0, nums2.size(), len/2)
             + findmid(nums1, 0, nums1.size(), nums2, 0, nums2.size(), len/2+1))/2.0;
        }else{
            return findmid(nums1, 0, nums1.size(), nums2, 0, nums2.size(), len/2+1);
        }
    }
};

//int MAX = 65535;
//
//class Solution {
//	int find_kth_in_two_sorted_array(int A[], int nA, int B[], int nB, int k) {
//		int l = max(0, k - nB);
//		int u = min(nA, k);
//		while (l < u) {
//			int x = l + (u - l) / 2;
//			int A_x_1 = x <= 0 ? -MAX : A[x - 1];
//			int A_x = x >= nA ? MAX : A[x];
//			int B_k_x_1 = k - x <= 0 ? -MAX : B[k - x - 1];
//			int B_k_x = k - x >= nB ? MAX : B[k - x];
//			if (A_x < B_k_x_1) {
//				l = x + 1;
//			} else if (A_x_1 > B_k_x) {
//				u = x - 1;
//			} else {
//				return max(A_x_1, B_k_x_1);
//			}
//		}
//		int A_l_1 = l <= 0 ? -MAX : A[l - 1];
//		int B_k_l_1 = k - l - 1 < 0 ? -MAX : B[k - l - 1];
//		return max(A_l_1, B_k_l_1);
//	}
//public:
//	double findMedianSortedArrays(int A[], int m, int B[], int n) {
//		int k = (m + n) / 2;
//		if ((m + n) % 2) {
//			return find_kth_in_two_sorted_array(A, m, B, n, k + 1);
//		} else {
//			return (find_kth_in_two_sorted_array(A, m, B, n, k)
//					+ find_kth_in_two_sorted_array(A, m, B, n, k + 1)) / 2.0;
//		}
//	}
//};
