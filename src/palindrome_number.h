class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int digit = 1;
        while(x/digit >= 10){
            digit*=10;
        }
        while(x>=10){
            if(x/digit != x%10){
                return false;
            }
            x= x % digit / 10;
            digit/=100;
        }
        return true;
    }
};

//class Solution {
//public:
//    bool isPalindrome(int x) {
//    	if (x<0) {
//    		return false;
//    	}
//    	bool isfinished = false;
//    	int tmp = x;
//    	int reverse = 0;
//    	while(!isfinished){
//    		reverse = reverse*10 + tmp % 10;
//    		tmp = tmp / 10;
//    		if (tmp == 0){
//    			isfinished = true;
//    		}
//    	}
//    	return (reverse == x);
//    }
//};
