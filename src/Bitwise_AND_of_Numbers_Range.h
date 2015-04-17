class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res=0;
        for(int i=0; i<31; i++){
            if((1<<i) & m){
                int right = (1<<(i+1)) - 1;
                int k = m | right;
                if(n <= k){
                    res |= (1<<i);
                }
            }
        }
        return res;
    }
};