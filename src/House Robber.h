class Solution {
public:
    int rob(vector<int> &num) {
        if(num.size() == 0){
            return 0;
        }else if(num.size() == 1){
            return num[0];
        }
        int non = 0, have = num[0];
        for(int i=1; i<num.size(); i++){
            int temp = non;
            non = max(non, have);
            have = temp + num[i];
        }
        return max(non, have);
    }
};