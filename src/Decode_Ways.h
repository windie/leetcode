class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), 0);
        if(s.size() == 0){
            return 0;
        }
        dp[0] = s[0] == '0' ? 0 : 1;
        for(int i = 1; i<s.size(); i++){
            dp[i] += (s[i] == '0' ? 0 : dp[i-1]);
            if(s[i-1]=='2' && s[i]<='6' || s[i-1]=='1'){
                if(i==1){
                    dp[i]++;
                }else{
                    dp[i] += dp[i-2];
                }
            }
        }
        return dp[s.size()-1];
    }
};

//class Solution {
//public:
//    int numDecodings(string s) {
//    	if(s.size()==0){
//    		return 0;
//    	}
//    	vector<int> f(s.size()+1, 0);
//    	f[0] = 1;
//    	for(int i=1; i<=s.size(); i++){
//    		int val = 0;
//    		if(s[i-1]>='1' && s[i-1] <='9'){
//    			val += f[i-1];
//    		}
//    		if(i>=2){
//    			int num = (s[i-2] - '0' )*10 + (s[i-1] - '0');
//    			if(num>=10 && num<=26){
//    				val += f[i-2];
//    			}
//    		}
//    		f[i] = val;
//    	}
//    	return f[s.size()];
//    }
//};

//class Solution {
//public:
//    int numDecodings(string s) {
//    	if(s.length() == 0){
//    		return 0;
//    	}
//    	int *f = new int[s.length()+1];
//    	f[0] = 1;
//    	if(s[0]>'0' && s[0]<='9'){
//    		f[1] = 1;
//    	}else{
//    		f[1] = 0;
//    	}
//    	if(s.length() == 1){
//    		return f[1];
//    	}
//    	int i = 2;
//    	while(i<=s.length()){
//    		int add=0;
//    		if(s[i-1] > '0'){
//    			add += f[i-1];
//    		}
//    		if((s[i-2] == '2' && s[i-1] <= '6') || s[i-2] == '1'){
//    			add += f[i-2];
//    		}
//    		f[i] = add;
//    		i++;
//    	}
//    	return f[s.length()];
//    }
//};
