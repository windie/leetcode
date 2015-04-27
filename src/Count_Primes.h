class Solution {
public:
    int countPrimes(int n) {
        bool* m = new bool[n]; // vector does not work
        int s = (int)sqrt(n-1);
        for(int i = 2; i<n; i++){
            m[i] = false;
        }
        for(int i = 2; i<=s; i++){
            if(m[i]){
                continue;
            }
            for(int j = i + i; j < n; j += i){
                m[j] = true;
            }
        }
        int res = 0;
        for(int i = 2; i < n; i++){
            if(!m[i]){
                res++;
            }
        }
        delete []m;
        return res;
    }
};