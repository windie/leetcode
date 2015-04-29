class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int res = nums[0];
        int maxv = nums[0], minv = nums[0];
        for(int i = 1; i<nums.size(); i++){
            int tmp_maxv = max(max(maxv*nums[i], minv*nums[i]), nums[i]);
            int tmp_minv = min(min(maxv*nums[i], minv*nums[i]), nums[i]);
            maxv = tmp_maxv;
            minv = tmp_minv;
            res = max(res, maxv);
        }
        return res;
    }
};