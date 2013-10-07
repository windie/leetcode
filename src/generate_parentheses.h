class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n==0){
            return res;
        }
        if(n==1){
            string s = "()";
            res.push_back(s);
            return res;
        }
        vector<string> pre = generateParenthesis(n-1);
        for(int i = 0; i<pre.size(); i++){
            vector<int> validpos;
            int cnt = 0;
            for(int j=0; j<pre[i].size(); j++){
                if(cnt == 0){
                    validpos.push_back(j);
                }
                if(pre[i][j]=='('){
                    cnt++;
                }else{
                    cnt--;
                }
            }
            validpos.push_back(pre[i].size()-1);
            for(int k = 0; k<validpos.size(); k++){
                string s = pre[i];
                s.insert(validpos[k], 1, ')');
                s.insert(0, 1,'(');
                res.push_back(s);
            }
        }
        return res;
    }
};

//class Solution {
//	void recursive(int leftcnt, int rightcnt, char * cur, int count,
//			vector<string>& res) {
//		if(leftcnt < 0 || leftcnt > rightcnt){
//			return;
//		}
//		if(leftcnt == 0 && rightcnt == 0){
//			cur[count] = 0;
//			res.push_back(cur);
//			return;
//		}
//		if(leftcnt>0){
//			cur[count] = '(';
//			recursive(leftcnt-1, rightcnt, cur, count+1, res);
//		}
//		if(leftcnt < rightcnt){
//			cur[count] = ')';
//			recursive(leftcnt, rightcnt-1, cur, count+1, res);
//		}
//	}
//public:
//	vector<string> generateParenthesis(int n) {
//		vector<string > res;
//		char * curstr = new char[2*n+1];
//		memset(curstr, 0, sizeof(char)*(2*n+1));
//		recursive(n, n, curstr, 0, res);
//		return res;
//	}
//};
