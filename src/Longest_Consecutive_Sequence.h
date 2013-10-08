class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> set;
        for(int i = 0; i<num.size(); i++){
            if(set.find(num[i]) == set.end()){
                set.insert(num[i]);
            }
        }
        int res = 0;
        for(int i=0; i<num.size(); i++){
            int len = 0;
            if(set.find(num[i]) != set.end()){
                len = 1;
                set.erase(num[i]);
                int val = num[i] - 1;
                while(set.find(val) != set.end()){
                    len ++;
                    set.erase(val);
                    val--;
                }
                val = num[i]+1;
                while(set.find(val) != set.end()){
                    len ++;
                    set.erase(val);
                    val++;
                }
            }
            res = max(res, len);
        }
        return res;
    }
};
