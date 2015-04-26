class Solution {
    int s2i(string s){
        int res = 0;
        for(int i = 0; i<s.size(); i++){
            res <<= 2;
            switch(s[i]){
                case 'A': res |= 0; break;
                case 'C': res |= 1; break;
                case 'G': res |= 2; break;
                case 'T': res |= 3; break;
                default: break;
            }
        }
        return res;
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<int, int> m;
        for(int i = 0; i+10 <= s.size(); i++){
            string tmp = s.substr(i, 10);
            int tmpi = s2i(tmp);
            auto it = m.find(tmpi);
            if(it == m.end()){
                m[tmpi] = 1;
            }else{
                m[tmpi]++;
                if(m[tmpi] == 2){
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};