#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
    	if(digits.size()<1) return digits;
    	bool is_add_digit = false;
    	digits[digits.size()-1]++;
    	for(int i=digits.size()-1; i>=0; i-- ){
    		if(digits[i]<10){
    			break;
    		}else{
    			digits[i] = 0;
    			if(i>0){
    				digits[i-1]++;
    			}else{
    				is_add_digit = true;
    			}
    		}
    	}
    	if(is_add_digit){
    		digits.insert(digits.begin(), 1);
    	}
    	return digits;
    }
};
