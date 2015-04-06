class Solution {
public:
    void sortColors(int A[], int n) {
        int a= 0, b=0, c=0;
        for(int i = 0; i< n; i++){
            switch(A[i]){
                case 0: a++; break;
                case 1: b++; break;
                case 2: c++; break;
                default: ;
            }
        }
        int i = 0, j = 0;
        for(i = 0; i<a; i++){
            A[i] = 0;
        }
        for(j = 0; j<b; j++){
            A[i+j] = 1;
        }
        i = i+j;
        for(j = 0; j<c; j++){
            A[i+j] = 2;
        }
    }
};

//class Solution {
//public:
//    void sortColors(int A[], int n) {
//        int i1=-1, i2=-1;
//        for(int i = 0; i<n; i++){
//            if(A[i]==0){
//                if(i1>-1 && i2==-1){
//                    A[i1++] = 0;
//                    A[i] = 1;
//                }else if(i1==-1 && i2>-1){
//                    A[i2++] = 0;
//                    A[i] =2;
//                }else if(i1 > -1 && i2>-1){
//                    A[i1++] = 0;
//                    A[i2++] = 1;
//                    A[i] = 2;
//                }
//            }else if(A[i]==1){
//                if(i1==-1 && i2==-1){
//                    i1=i;
//                }else if(i1 == -1 && i2 >-1){
//                    A[i2] = 1;
//                    i1 = i2;
//                    i2++;
//                    A[i] = 2;
//                }else if(i1 > -1 && i2 >-1){
//                    A[i2++]=1;
//                    A[i] = 2;
//                }
//            }else {
//                if(i2==-1){
//                    i2 = i;
//                }
//            }
//        }
//    }
//};

//class Solution {
//public:
//    void sortColors(int A[], int n) {
//    	int i1=-1, i2=-1;
//    	for(int i=0; i<n; i++){
//    		if(A[i]==0){
//    			if(i1==-1 && i2>-1){
//    				A[i2] = 0;
//    				A[i] =2;
//    				i2++;
//    			}
//    			else if(i1>-1 && i2==-1){
//    				A[i1] = 0;
//    				A[i] =1;
//    				i1++;
//    			}
//    			else if(i1>-1 && i2 >-1){
//    				A[i1] = 0;
//    				i1++;
//    				A[i2] = 1;
//    				i2++;
//    				A[i] = 2;
//    			}
//    		}else if(A[i]==1){
//    			if(i1==-1 && i2==-1){
//    				i1 = i;
//    			}else if(i1==-1 && i2>-1){
//    				A[i2] = 1;
//    				i1=i2;
//    				i2++;
//    				A[i] = 2;
//    			}else if(i1>-1 && i2>-1){
//    				A[i2] = 1;
//    				i2++;
//    				A[i] = 2;
//    			}
//    		}else{
//    			if(i2==-1){
//    				i2=i;
//    			}
//    		}
//    	}
//    }
//};
