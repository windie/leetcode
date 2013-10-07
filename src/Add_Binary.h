class Solution {
	string addone(string a) {
		int add = 1;
		for (int i = a.size()-1; i >= 0; i--) {
			if (add == 0) {
				break;
			}
			int num = a[i] - '0' + add;
			a[i]= num % 2 + '0';
			add = num / 2;
		}
		return add ? "1" + a : a;
	}
public:
	string addBinary(string a, string b) {
		if (a.size() == 0) {
			return b;
		}
		if (b.size() == 0) {
			return a;
		}
		int add = 0;
		int ia = a.size() - 1, ib = b.size() - 1;
		string res = "";
		while (ia >= 0 && ib >= 0) {
			string digit = "0";
			int di = (add + a[ia] - '0' + b[ib] - '0') % 2;
			add = (add + a[ia] - '0' + b[ib] - '0') / 2;
			digit[0] += di;
			res = digit + res;
			ia--;
			ib--;
		}
		if (ia < 0 && ib < 0) {
			return add ? "1" + res : res;
		} else if (ia < 0) {
			string substr = b.substr(0, ib+1);
			return add ? addone(substr) + res : substr + res;
		} else {
			string substr = a.substr(0, ia+1);
			return add ? addone(substr) + res : substr + res;
		}
	}
};

//class Solution {
//private:
//	string addadd(string a, int i, int add){
//		string res = "";
//		while(i>=0){
//			int num = add + a[i]-'0';
//			add = num/2;
//			res.insert(res.begin(), num%2+'0');
//			i--;
//		}
//		if(add > 0){
//			res.insert(res.begin(), '1');
//		}
//		return res;
//	}
//public:
//    string addBinary(string a, string b) {
//    	string res="";
//    	int add = 0;
//
//    	int i,j;
//    	for(i = a.length()-1, j = b.length()-1; i>=0 && j>=0; i--, j--){
//    		int ai = a[i]-'0';
//    		int bj = b[j]-'0';
//    		int num = add + ai + bj;
//    		add = num/2;
//    		res.insert(res.begin(), num%2 + '0');
//    	}
//    	if(add>0 && a.length() == b.length()){
//    		res.insert(res.begin(), '1');
//    	}else if(a.length() > b.length()){
//    		res = addadd(a, i, add) + res;
//    	}else if(a.length() < b.length()){
//    		res = addadd(b, j, add) + res;
//    	}
//    	return  res;
//    }
//};
