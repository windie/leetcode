class Solution {
public:
    double pow(double x, int n) {
        if(n==0){
            return 1;
        }else if(n==1){
            return x;
        }
        bool isNeg=false;
        if(n<0){
            n = -n;
            isNeg=true;
        }
        double val = pow(x, n/2);
        double res = n%2 ? val*val*x : val*val;
        return isNeg ? 1/res : res;
    }
};

//class Solution {
//public:
//	double pow(double x, int n) {
//		bool isNeg = false;
//		bool tag = false;
//		if (n < 0) {
//			n = -n;
//			isNeg = true;
//			if(n==0x80000000){
//				tag = true;
//				n /= 2;
//				n = -n;
//			}
//		}
//		double res = 1;
//		double pow = x;
//		while (n) {
//			if (n & 1) {
//				res *= pow;
//			}
//			n >>= 1;
//			pow *= pow;
//		}
//		if (!isNeg) {
//			return res;
//		} else if(!tag){
//			return 1 / res;
//		}else{
//			return 1 / res /res;
//		}
//	}
//};
