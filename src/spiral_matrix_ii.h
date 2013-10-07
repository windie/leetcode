#include <vector>
using namespace std;

class Solution {
	void filledge(vector<vector<int> > &res, int rowi, int colj, int n, int begin){
		if(n<=0){
			return;
		}
		for(int j = colj; j< colj+n; j++ ){
			res[rowi][j] = begin++;
		}
		for(int i = rowi+1; i<rowi+n; i++){
			res[i][colj+n-1] = begin++;
		}
		for(int j = colj+n-2; j>= colj; j--){
			res[rowi+n-1][j] = begin++;
		}
		for(int i = rowi+n-2; i>= rowi+1; i--){
			res[i][colj] = begin++;
		}
		filledge(res, rowi+1, colj+1, n-2, begin);
	}

public:
    vector<vector<int> > generateMatrix(int n) {
    	vector<vector<int> > res;
    	vector<int> tmp;
    	for(int i=0; i<n; i++){
    		tmp.push_back(0);
    	}
    	for(int i=0; i<n; i++){
    		res.push_back(tmp);
    	}
    	filledge(res, 0, 0, n, 1);
    	return res;
    }
};
