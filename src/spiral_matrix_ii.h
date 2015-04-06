class Solution {
    void rec(vector<vector<int> > &in, int x, int wid, int& begin){
        if(wid == 1){
            in[x][x] = begin;
            return;
        }
        for(int i = 0; i<wid-1; i++){
            in[x][x+i]=begin++;
        }
        for(int i = 0; i<wid-1; i++){
            in[x+i][x+wid-1]=begin++;
        }
        for(int i = 0; i<wid-1; i++){
            in[x+wid-1][x+wid-1-i]=begin++;
        }
        for(int i = 0; i<wid-1; i++){
            in[x+wid-1-i][x]=begin++;
        }
    }
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        int begin = 1;
        int wid = n;
        for(int x = 0; x <= n/2; x++, wid-=2){
            rec(res, x, wid, begin);
        }
        return res;
    }
};

//#include <vector>
//using namespace std;
//
//class Solution {
//	void filledge(vector<vector<int> > &res, int rowi, int colj, int n, int begin){
//		if(n<=0){
//			return;
//		}
//		for(int j = colj; j< colj+n; j++ ){
//			res[rowi][j] = begin++;
//		}
//		for(int i = rowi+1; i<rowi+n; i++){
//			res[i][colj+n-1] = begin++;
//		}
//		for(int j = colj+n-2; j>= colj; j--){
//			res[rowi+n-1][j] = begin++;
//		}
//		for(int i = rowi+n-2; i>= rowi+1; i--){
//			res[i][colj] = begin++;
//		}
//		filledge(res, rowi+1, colj+1, n-2, begin);
//	}
//
//public:
//    vector<vector<int> > generateMatrix(int n) {
//    	vector<vector<int> > res;
//    	vector<int> tmp;
//    	for(int i=0; i<n; i++){
//    		tmp.push_back(0);
//    	}
//    	for(int i=0; i<n; i++){
//    		res.push_back(tmp);
//    	}
//    	filledge(res, 0, 0, n, 1);
//    	return res;
//    }
//};
