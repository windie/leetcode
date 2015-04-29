class Solution {
    vector<vector<int> > twoSum(vector<int> &num, int begin, int target){
        int i = begin, j = num.size()-1;
        vector<vector<int> > res;
        while(i<j){
            if(num[i] + num[j] == target){
                if(res.size()==0 || res[res.size()-1][0] != num[i] || res[res.size()-1][1] != num[j]){
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    res.push_back(tmp);
                }
                i++;
                j--;
            }else if(num[i] + num[j] < target){
                i++;
            }else {
                j--;
            }
        }
        return res;
    }
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > res;
        for(int i = 0; i + 2 < num.size(); i++){
            if(i > 0 && num[i] == num[i-1]){
                continue;
            }
            vector<vector<int> > tmp =  twoSum(num, i+1, -num[i]);
            for(int j = 0; j<tmp.size(); j++){
                tmp[j].insert(tmp[j].begin(), num[i]);
                res.push_back(tmp[j]);
            }
        }
        return res;
    }
};

//#include<iostream>
//using namespace std;
//
//class Solution {
//	void twoSum(vector<int> &num, int begin, int target,
//			vector<vector<int> > &res) {
//		int low = begin, high = num.size() - 1;
//		while (low < high) {
//			if (num[low] + num[high] == target) {
//				vector<int> tmp;
//				tmp.push_back(-target);
//				tmp.push_back(num[low]);
//				tmp.push_back(num[high]);
//				if (!(res.size() > 0 && res[res.size() - 1][0] == tmp[0]
//						&& res[res.size() - 1][1] == tmp[1]
//						&& res[res.size() - 1][2] == tmp[2])) {
//					res.push_back(tmp);
//				}
//				low++;
//				high--;
//			} else if (num[low] + num[high] > target) {
//				high--;
//			} else {
//				low++;
//			}
//		}
//	}
//
//public:
//	vector<vector<int> > threeSum(vector<int> &num) {
//		vector<vector<int> > res;
//		if (num.size() < 3) {
//			return res;
//		}
//		sort(num.begin(), num.end());
//		for (int i = 0; i <= num.size() - 3; i++) {
//			if (i > 0 && num[i] == num[i - 1]) {
//				continue;
//			}
//			twoSum(num, i + 1, -num[i], res);
//		}
//		return res;
//	}
//};

//#include<vector>
//using namespace std;

//class Solution {
//private:
//	vector<vector<int> > twoSum(vector<int> &numbers, int begin, int target) {
//		vector<vector<int> > res;
//		for (int i = begin, j = numbers.size() - 1; i < j;) {
//			int sum = numbers[i] + numbers[j];
//			if (sum == target) {
//				vector<int> tmp;
//				tmp.push_back(numbers[i]);
//				tmp.push_back(numbers[j]);
//				if(target<0){
//					tmp.push_back(-target);
//				}else{
//					tmp.insert(tmp.begin(), -target);
//				}
//				j--;
//				i++;
//				if(res.size()>0 && res[res.size()-1][0] == tmp[0]
//				&& res[res.size()-1][1] == tmp[1] && res[res.size()-1][2] == tmp[2]){
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
//public:
//    vector<vector<int> > threeSum(vector<int> &num) {
//    	vector<vector<int> > tmp, res;
//    	if(num.size()<3) return res;
//    	sort(num.begin(), num.end());
//    	int pretarget=0;
//    	for(int i=0; i<num.size()-2; i++){
//    		if(i==0){
//    			pretarget = num[i];
//    		}else if(pretarget == num[i]){
//    			continue;
//    		}else{
//    			pretarget = num[i];
//    		}
//    		tmp = twoSum(num, i+1, -num[i]);
//    		for(int j=0; j<tmp.size(); j++){
//    			res.push_back(tmp[j]);
//    		}
//    	}
//    	return res;
//    }
//};
