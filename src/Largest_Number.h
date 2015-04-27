string i2s(int a){
    stringstream ss;
    ss << a;
    return ss.str();
}
bool cmp(int a, int b){
    string stra = i2s(a);
    string strb = i2s(b);
    return stra + strb > strb + stra;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size()==0){
            return "";
        }
        sort(nums.begin(), nums.end(), cmp);
        if(nums[0] == 0){
            return "0";
        }
        string res = "";
        for(int i = 0; i<nums.size(); i++){
            res += i2s(nums[i]);
        }
        return res;
    }
};