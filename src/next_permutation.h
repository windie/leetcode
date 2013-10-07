#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
    	next_permutation(num.begin(), num.end());
    }
};

//class Solution {
//	void reverse(vector<int> &num, int begin , int end){
//		while(begin < end){
//			int tmp = num[begin];
//			num[begin] = num[end];
//			num[end] = tmp;
//			begin++;
//			end--;
//		}
//	}
//public:
//    void nextPermutation(vector<int> &num) {
//    	int k= num.size()-2;
//    	while(k>=0 && num[k] >= num[k+1]){
//    		k--;
//    	}
//    	if(k==-1){
//    		return;
//    	}
//    	int l;
//    	for(int i = k+1; i<num.size(); i++){
//    		if(num[i] > num[k]){
//    			l = i;
//    		}else{
//    			break;
//    		}
//    	}
//    	// swap num[k] and num[l]
//    	int tmp = num[k];
//    	num[k] = num[l];
//    	num[l] = tmp;
//    	// reverse num[k+1, end]
//    	reverse(num, k+1, num.size()-1);
//    }
//};
