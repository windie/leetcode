class Solution {
    vector<string> split(string str, char delimiter) {
        vector<string> res;
        stringstream ss(str);
        string tok;
        while(getline(ss, tok, delimiter)) {
            res.push_back(tok);
        }
        return res;
    }
    int s2i(string s){
        int val;
        istringstream s1(s);
        s1 >> val;
        return val;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1 = split(version1, '.');
        vector<string> v2 = split(version2, '.');
        int i = 0;
        while(i < v1.size() && i < v2.size()){
            int val1 = s2i(v1[i]), val2 = s2i(v2[i]);
            if(val1<val2){
                return -1;
            }else if(val1>val2){
                return 1;
            }
            i++;
        }
        if(i==v1.size() && i==v2.size()){
            return 0;
        }else if(i==v1.size()){
            while(i<v2.size()){
                if(s2i(v2[i])){
                    return -1;
                }
                i++;
            }
            return 0;
        }else{
            while(i<v1.size()){
                if(s2i(v1[i])){
                    return 1;
                }
                i++;
            }
            return 0;
        }
    }
};
