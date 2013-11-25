#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
	void swap(vector<int> & a, int i, int j){
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
	void reverse(vector<int> & a, int begin, int end){
		while(begin < end){
			int tmp = a[begin];
			a[begin] = a[end];
			a[end] = tmp;
			begin++;
			end--;
		}
	}
public:
    void nextPermutation(vector<int> &num) {
    	int i = num.size() - 1;
    	int partitionNum, changeNum;
    	while(i>0){
    		if(num[i-1] < num[i]){
    			break;
    		}
    		i--;
    	}
    	if(i>0){
    		partitionNum = --i;
    		i = num.size()-1;
    		while(i>partitionNum){
    			if(num[i]>num[partitionNum]){
    				break;
    			}
    			i--;
    		}
    		changeNum = i;
    		swap(num, partitionNum, changeNum);
    		reverse(num, partitionNum+1, num.size()-1);
    	}else{
    		reverse(num, 0, num.size()-1);
    	}
    }
};

//class Solution {
//public:
//    void nextPermutation(vector<int> &num) {
//    	next_permutation(num.begin(), num.end());
//    }
//};
