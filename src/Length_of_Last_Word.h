#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
    	int len = strlen(s);
    	if(len==0) return 0;
    	int count=0;
    	bool is_filter=false;
    	for(int i=len-1; i>=0; i--){
    		if(s[i]==' ' && count==0){
    			continue;
    		}
    		if(s[i]==' ' && count>0){
    			break;
    		}
    		if(s[i]!=' '){
    			count++;
    		}
    	}
    	return count;
    }
};
