class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if(num.size()<3){
            return 0;
        }
        sort(num.begin(), num.end());
        int res=num[0]+num[1]+num[2];
        for(int i=0; i<num.size()-2; i++){
            int j = i+1, k=num.size()-1;
            while(j<k){
                int tmp = num[i] + num[j] + num[k];
                if(abs(target - tmp) < abs(res-target)){
                    res = tmp;
                }
                if(tmp == target){
                    return tmp;
                }else if(tmp < target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return res;
    }
};

//class Solution {
//public:
//	int threeSumClosest(vector<int> &num, int target) {
//		sort(num.begin(), num.end());
//		if (num.size() < 3) {
//			return 0;
//		}
//		int res = num[0] + num[1] + num[num.size() - 1];
//		for (int i = 0; i < num.size() - 2; i++) {
//			int j = i + 1;
//			int k = num.size() - 1;
//			while (j < k) {
//				int sum = num[i] + num[j] + num[k];
//				if (abs(sum - target) < abs(res - target)) {
//					res = sum;
//				}
//				if (sum == target) {
//					return sum;
//				} else if (sum < target) {
//					j++;
//				} else {
//					k--;
//				}
//			}
//		}
//		return res;
//	}
//};
