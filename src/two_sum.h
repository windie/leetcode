struct num{
    int val;
    int index;
};

bool cmp(num a, num b){
    return a.val < b.val;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<num> nums;
        for(int i =0; i<numbers.size(); i++){
            num tmp;
            tmp.val = numbers[i];
            tmp.index = i+1;
            nums.push_back(tmp);
        }
        sort(nums.begin(), nums.end(), cmp);
        int begin = 0, end = nums.size()-1;
        vector<int> res;
        while(begin < end){
            if(nums[begin].val + nums[end].val == target){
                res.push_back(min(nums[begin].index, nums[end].index));
                res.push_back(max(nums[begin].index, nums[end].index));
                return res;
            }else if(nums[begin].val + nums[end].val < target){
                begin++;
            }else{
                end--;
            }
        }
    }
};

//#include<vector>
//using namespace std;
//
//struct num{
//	int val;
//	int index;
//};
//
//bool mycmp (num i, num j) { return (i.val<j.val); }
//
//class Solution {
//public:
//	vector<int> twoSum(vector<int> &numbers, int target) {
//		vector<num> nums;
//		for(int i=0; i<numbers.size(); i++){
//			num tmp;
//			tmp.val = numbers[i];
//			tmp.index = i+1;
//			nums.push_back(tmp);
//		}
//		sort(nums.begin(), nums.end(), mycmp);
//		vector<int> res;
//		for(int i=0,  j = nums.size()-1; i < j;){
//			int sum = nums[i].val + nums[j].val;
//			if( sum == target){
//				res.push_back(nums[i].index < nums[j].index ? nums[i].index : nums[j].index);
//				res.push_back(nums[i].index > nums[j].index ? nums[i].index : nums[j].index);
//				break;
//			}
//			else if(sum > target){
//				j--;
//			}
//			else if(sum < target){
//				i++;
//			}
//		}
//		return res;
//	}
//};
