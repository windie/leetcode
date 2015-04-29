class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m;
        unordered_set<char> d;
        if(s.size() != t.size()){
            return false;
        }
        for(int i = 0; i<s.size(); i++){
            auto ita = m.find(s[i]);
            if(ita == m.end()){
                if(d.find(t[i]) == d.end()){
                    m[s[i]] = t[i];
                    d.insert(t[i]);
                }else{
                    return false;
                }
            }else if(m[s[i]] != t[i]){
                return false;
            }
        }
        return true;
    }
};