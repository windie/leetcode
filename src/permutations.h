#include<algorithm>
using namespace std;

//class Solution {
//public:
//    vector<vector<int> > permute(vector<int> &num) {
//    	vector<vector<int> > res;
//    	sort(num.begin(), num.end());
//    	res.push_back(num);
//    	while (next_permutation(num.begin(), num.end())){
//    		res.push_back(num);
//    	}
//    	return res;
//    }
//};
class Solution {
	void swap(vector<int> &num, int i, int k){
		int tmp = num[i];
		num[i] = num[k];
		num[k] = tmp;
	}
	void recursive(vector<int> &num, int n, int k, vector<vector<int> > & res){
		if(k==n-1){
			res.push_back(num);
		}else{
			for(int i =k; i<n; i++){
				swap(num, k, i);
				recursive(num, n, k+1, res);
				swap(num, k, i);
			}
		}
	}
public:
    vector<vector<int> > permute(vector<int> &num) {
    	vector<vector<int> > res;
    	recursive(num, num.size(), 0, res);
    	return res;
    }
};

