class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.size()==0){
            return 0;
        }
        int begin = 0, end = num.size()-1;
        int res = num[begin];
        while(begin <= end){
            int mid = begin + (end-begin)/2;
            if(num[begin] <= num[mid]){
                res = min(res, num[begin]);
                begin = mid+1;
            }else {
                res = min(res, num[mid]);
                end = mid-1;
            }
        }
        return res;
    }
};