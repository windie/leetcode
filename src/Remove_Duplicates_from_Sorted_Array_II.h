class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n == 0) {
			return 0;
		}
		int pos = 0, cnt = 1;
		for (int i = 1; i < n; i++) {
			if (A[i] == A[pos]) {
				if (cnt == 1) {
					A[pos + 1] = A[i];
					pos++;
					cnt++;
				}
			} else {
				A[pos + 1] = A[i];
				pos++;
				cnt = 1;
			}
		}
		return pos + 1;
	}
};

//class Solution {
//public:
//    int removeDuplicates(int A[], int n) {
//    	if(n==0){
//    		return 0;
//    	}
//    	int validpos = 1;
//    	int curvalue = A[0];
//    	int curcount = 1;
//    	for(int i=1; i<n; i++){
//    		if(A[i]==curvalue){
//    			curcount++;
//    		}else{
//    			curvalue = A[i];
//    			curcount=1;
//    		}
//    		if(curcount<=2){
//    			A[validpos] = A[i];
//    			validpos++;
//    			continue;
//    		}
//    	}
//    	return validpos;
//    }
//};
