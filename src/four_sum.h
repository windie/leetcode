class Solution {
    vector<vector<int> > twoSum(vector<int> &num, int begin, int target){
        vector<vector<int> > res;
        if(num.size() <2 || begin >= num.size()-1){
            return res;
        }
        int low = begin, high = num.size()-1;
        while(low<high){
            if(num[low] + num[high] == target){
                if(res.size()>0 && res[res.size()-1][0]== num[low]
                && res[res.size()-1][1] == num[high]){
                }else{
                    vector<int> tmp;
                    tmp.push_back(num[low]);
                    tmp.push_back(num[high]);
                    res.push_back(tmp);
                }
                low++;
                high--;
            }else if(num[low] + num[high] < target){
                low++;
            }else{
                high--;
            }
        }
        return res;
    }
    vector<vector<int> > threeSum(vector<int> &num, int begin, int target){
        vector<vector<int> > res;
        if(begin >= num.size()-2){
            return res;
        }
        for(int i = begin; i<num.size()-2; i++){
            if(i > begin && num[i] == num[i-1]){
                continue;
            }
            vector<vector<int> > two = twoSum(num, i+1, target-num[i]);
            for(int j = 0; j<two.size(); j++){
                two[j].insert(two[j].begin(), num[i]);
                res.push_back(two[j]);
            }
        }
        return res;
    }

public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if(num.size() < 4) {
            return res;
        }
        sort(num.begin(), num.end());
        for(int i = 0; i<num.size()-3; i++){
            if(i>0 && num[i] == num[i-1]){
                continue;
            }
            vector<vector<int> > three = threeSum(num, i+1, target-num[i]);
            for(int j = 0; j<three.size(); j++){
                three[j].insert(three[j].begin(), num[i]);
                res.push_back(three[j]);
            }
        }
        return res;
    }
};

//class Solution {
//private:
//	vector<vector<int> > twoSum(vector<int> &numbers, int begin, int target) {
//		vector < vector<int> > res;
//		if(numbers.size()<2) return res;
//		for (int i = begin, j = numbers.size() - 1; i < j;) {
//			int sum = numbers[i] + numbers[j];
//			if (sum == target) {
//				vector<int> tmp;
//				tmp.push_back(numbers[i]);
//				tmp.push_back(numbers[j]);
//				j--;
//				i++;
//				if (res.size() > 0 && res[res.size() - 1][0] == tmp[0]
//						&& res[res.size() - 1][1] == tmp[1]
////						&& res[res.size() - 1][2] == tmp[2]
//						                                 ) {
//					continue;
//				}
//				res.push_back(tmp);
//			} else if (sum > target) {
//				j--;
//			} else if (sum < target) {
//				i++;
//			}
//		}
//		return res;
//	}
//
//	vector<vector<int> > threeSum(vector<int> &num, int begin, int target) {
//		vector<vector<int> > tmp, res;
//		if (num.size() < 3)
//			return res;
//		int pretarget = 0;
//		for (int i = begin; i < num.size() - 2; i++) {
//			if (i == begin) {
//				pretarget = target - num[i];
//			} else if (pretarget == target - num[i]) {
//				continue;
//			} else {
//				pretarget = target - num[i];
//			}
//			tmp = twoSum(num, i + 1, target - num[i]);
//			for (int j = 0; j < tmp.size(); j++) {
//				if(num[i] < tmp[j][0]){
//					tmp[j].insert(tmp[j].begin(), num[i]);
//				}else if(num[i] < tmp[j][1]) {
//					tmp[j].insert(tmp[j].begin()+1, num[i]);
//				}else{
//					tmp[j].push_back(num[i]);
//				}
//				res.push_back(tmp[j]);
//			}
//		}
//		return res;
//	}
//public:
//	vector<vector<int> > fourSum(vector<int> &num, int target) {
//		vector<vector<int> > tmp, res;
//		if(num.size()<4) return res;
//		sort(num.begin(), num.end());
//		int prei = 0;
//		for (int i = 0; i < num.size(); i++) {
//			if (i == 0) {
//				prei = num[i];
//			} else {
//				if (prei == num[i]) {
//					continue;
//				} else {
//					prei = num[i];
//				}
//			}
//			tmp = threeSum(num, i + 1, target - num[i]);
//			for (int j = 0; j < tmp.size(); j++) {
//				if(num[i] < tmp[j][0]){
//					tmp[j].insert(tmp[j].begin(), num[i]);
//				}else if(num[i] < tmp[j][1]) {
//					tmp[j].insert(tmp[j].begin()+1, num[i]);
//				}else if(num[i] < tmp[j][2]) {
//					tmp[j].insert(tmp[j].begin()+2, num[i]);
//				}else{
//					tmp[j].push_back(num[i]);
//				}
//				res.push_back(tmp[j]);
//			}
//		}
//		return res;
//	}
//};
