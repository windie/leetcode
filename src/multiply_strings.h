class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() == 0 || num2.size() == 0){
            return "";
        }
        if(num1.size()==1 && num1[0] == '0' || num2.size()==1 && num2[0] == '0'){
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string res(num1.size() + num2.size() + 1, '0');
        for(int i = 0; i<num1.size(); i++){
            if(num1[i] == '0'){
                continue;
            }
            for(int j = 0; j<num2.size(); j++){
                int val = (num1[i]-'0') * (num2[j]-'0');
                int remain = res[i+j]-'0';
                res[i+j] = ((remain+val)%10) + '0';
                res[i+j+1] += ((remain+val)/10);
            }
        }
        int i = 0;
        for(i = res.size()-1; i>=0; i--){
            if(res[i] != '0'){
                break;
            }
        }
        if(i < 0){
            return "0";
        }
        res = res.substr(0, i+1);
        reverse(res.begin(), res.end());
        return res;
    }
};

//class Solution {
//public:
//	string multiply(string num1, string num2) {
//		string res = "";
//		if (num1.size() == 0 || num2.size() == 0) {
//			return res;
//		}
//		if ((num1.size() == 1 && num1[0] == '0')
//				|| (num2.size() == 1 && num2[0] == '0')) {
//			return "0";
//		}
//		std::reverse(num1.begin(), num1.end());
//		std::reverse(num2.begin(), num2.end());
//		vector<int> num(num1.size() + num2.size() + 1, 0);
//		for (int i = 0; i < num1.size(); i++) {
//			if (num1[i] == '0') {
//				continue;
//			}
//			for (int j = 0; j < num2.size(); j++) {
//				int val = (num1[i] - '0') * (num2[j] - '0');
//				int add = num[j + i];
//				num[j + i] = (val + add) % 10;
//				num[j + i + 1] += (val + add) / 10;
//			}
//		}
//		int i = num1.size() + num2.size();
//		while(i>=0 && num[i]==0){
//			i--;
//		}
//		for(int j = 0; j<=i; j++){
//			res.insert(res.begin(), num[j]+'0');
//		}
//		return res;
//	}
//};
