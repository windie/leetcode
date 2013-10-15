class Solution {
	int pow(int k){
		int res = 1;
		while(k--){
			res<<=1;
		}
		return res;
	}
public:
	vector<int> grayCode(int n) {
		vector<int> res;
		if (n == 0) {
			res.push_back(0);
			return res;
		}
		vector<int> pre = grayCode(n - 1);
		int powVal = pow(n - 1);
		res = pre;
		for (int i = pre.size() - 1; i >= 0; i--) {
			res.push_back(pre[i] + powVal);
		}
		return res;
	}
};

//#include <vector>
//
//class Solution {
//private:
//	int power(int k){
//		int i=0;
//		int res=1;
//		while(i<k){
//			res<<=1;
//			i++;
//		}
//		return res;
//	}
//	vector<int> genFromPre(int k, vector<int> pre){
//		vector<int> res;
//		if(k==0){
//			res.push_back(0);
//			res.push_back(1);
//			return res;
//		}
//		res=pre;
//		for(int i=pre.size()-1; i>=0; i--){
//			res.push_back( power(k) + pre[i] );
//		}
//		return res;
//	}
//public:
//    vector<int> grayCode(int n) {
//    	vector<int> res;
//    	if(n==0){
//    		res.push_back(0);
//    		return res;
//    	}
//    	for(int i=0; i<n; i++){
//    		res = genFromPre(i, res);
//    	}
//    	return res;
//    }
//};
