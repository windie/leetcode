class Solution {
public:
    int longestConsecutive(vector<int> &num) {
    	unordered_set<int> hashset;
    	for(int i=0; i<num.size(); i++){
    		hashset.insert(num[i]);
    	}
    	int longest = 0;
    	for(int i=0; i<num.size(); i++){
    		int count=0;
    		int minus = num[i];
    		while(hashset.find(minus) != hashset.end() && minus>=0){
    			hashset.erase(minus);
    			count++;
    			minus--;
    		}
    		int plus = num[i]+1;
    		while(hashset.find(plus) != hashset.end()){
    			count++;
    			plus++;
    		}
    		if(count>longest){
    			longest = count;
    		}
    	}
    	return longest;
    }
};
