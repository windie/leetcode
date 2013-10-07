
class Solution {
public:
    string convert(string s, int nRows) {
    	int partLen = (nRows*2-2);
    	if(partLen<1){  //!!!
    		return s;
    	}
    	int nParts = s.length()/partLen + 1;
    	string res="";
    	for(int i=0; i<nRows; i++){
        	for(int j=0; j<nParts; j++){
        		int index1 = i + j*partLen;
        		if(index1 < s.length()){
        			res += s[index1];
        		}
        		int index2 = (j+1)*partLen-i;
        		if(i>0 && i<nRows-1 && index2 < s.length()){
        			res += s[index2];
        		}
        	}
    	}
    	return res;
    }
};
