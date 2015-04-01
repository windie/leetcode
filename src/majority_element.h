class Solution {
public:
    int majorityElement(vector<int> &num) {
        if(num.size() == 0){
            return 0;
        }
        int val = num[0];
        int cnt = 1;
        for(int i = 1; i<num.size(); i++){
            if(cnt == 0){
                val = num[i];
                cnt = 1;
            }else{
                if(val == num[i]){
                    cnt++;
                }else{
                    cnt--;
                }
            }
        }
        return val;
    }
};