#include <stdlib.h>
#include <ctype.h>

class Solution {
public:
    bool isPalindrome(string s) {
    	if (s == "") return true;
    	bool isPal = true;
    	int index = 0;
    	int rev_index = s.length()-1;
    	while(index <= rev_index){
    		if(!isalnum(s[index])){
    			index++;
    			continue;
    		}
    		if(!isalnum(s[rev_index])){
    			rev_index--;
    			continue;
    		}
    		if(tolower(s[rev_index]) == tolower(s[index])){
    			index++;
    			rev_index--;
    		}else{
    			isPal = false;
    			break;
    		}
    	}
    	return isPal;
    }
};

