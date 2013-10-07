class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0){
            return 0;
        }
        int pos = 0;
        for(int i = 1; i<n; i++){
            if(A[i] != A[pos]){
                A[pos+1] = A[i];
                pos++;
            }
        }
        return pos+1;
    }
};

//class Solution {
//public:
//    int removeDuplicates(int A[], int n) {
//    	if(n==0) return 0;
//    	int validpos = 1;
//    	int curvalue = A[0];
//    	for(int i=1; i<n; i++){
//    		if(A[i] == curvalue){
//    			continue;
//    		}else{
//    			A[validpos] = A[i];
//    			curvalue = A[i];
//    			validpos++;
//    		}
//    	}
//    	return validpos;
//    }
//};
