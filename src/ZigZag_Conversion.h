class Solution {
public:
    string convert(string s, int nRows) {
        int size = 2*nRows - 2;
        if(nRows < 2){
            return s;
        }
        string res = "";
        int nparts = s.size()%size ? s.size()/size+1 : s.size()/size;
        for(int i = 0; i<nRows; i++){
            for(int j = 0; j<nparts; j++){
                if(i == 0){
                    res += s[j*size];
                }else if (i == nRows-1){
                    if(j*size+nRows-1 < s.size()){
                        res += s[j*size+nRows-1];
                    }
                }else{
                    if(j*size + i < s.size()){
                        res += s[j*size+i];
                    }
                    if((j+1)*size-i < s.size()){
                        res += s[(j+1)*size-i];
                    }
                }
            }
        }
        return res;
    }
};

//
//class Solution {
//public:
//    string convert(string s, int nRows) {
//    	int partLen = (nRows*2-2);
//    	if(partLen<1){  //!!!
//    		return s;
//    	}
//    	int nParts = s.length()/partLen + 1;
//    	string res="";
//    	for(int i=0; i<nRows; i++){
//        	for(int j=0; j<nParts; j++){
//        		int index1 = i + j*partLen;
//        		if(index1 < s.length()){
//        			res += s[index1];
//        		}
//        		int index2 = (j+1)*partLen-i;
//        		if(i>0 && i<nRows-1 && index2 < s.length()){
//        			res += s[index2];
//        		}
//        	}
//    	}
//    	return res;
//    }
//};
