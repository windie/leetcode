class Solution {
    bool isValid(vector<string> & chess, int row, int col, int n){
        int ii =row, jj = col;
        for(int i=0; i<n; i++){
        	if(chess[i][col]=='Q'){
        		return false;
        	}
        }
        while(ii>=0&&jj>=0){
            if(chess[ii--][jj--]=='Q'){
                return false;
            }
        }
        ii = row, jj = col;
        while(ii>=0 && jj<n){
            if(chess[ii--][jj++]=='Q'){
                return false;
            }
        }
        return true;
    }
    void recursive(int row, vector<string> &cur, vector<vector<string> > & res, int n){
        if(row >=n){
            res.push_back(cur);
            return;
        }
        for(int i =0 ;i<n; i++){
            if(isValid(cur, row, i, n)){
                cur[row][i] = 'Q';
                recursive(row+1, cur, res, n);
                cur[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string> > solveNQueens(int n) {
        string s(n, '.');
        vector<string> cur(n, s);
        vector<vector<string> > res;
        recursive(0, cur, res, n);
        return res;
    }
};

//#include <vector>
//using namespace std;
//
//class Solution {
//	bool isValid(vector<string> &curQueens, int row, int col){
//		for(int i=0; i<curQueens.size(); i++){
//			for(int j=0; j<curQueens[i].size(); j++){
//				if(curQueens[i][j]=='Q'){
//					if(j==col){
//						return false;
//					}
//					if(abs(row-i) == abs(col-j)){
//						return false;
//					}
//				}
//			}
//		}
//		return true;
//	}
//
//	void recursiveFind(int n, int curRow, vector<string> & curQueens,
//			vector<vector<string> > & rs) {
//		if(curRow >= n){
//			rs.push_back(curQueens);
//			return;
//		}
//
//		for(int colj=0; colj<n; colj++){
//			if(!isValid(curQueens, curRow, colj)){
//				continue;
//			}else{
//				string strqueen = "";
//				for(int i=0; i<n; i++){
//					if(i==colj){
//						strqueen.push_back('Q');
//					}else{
//						strqueen.push_back('.');
//					}
//				}
//				curQueens.push_back(strqueen);
//				recursiveFind(n, curRow+1, curQueens, rs);
//				curQueens.pop_back();
//			}
//		}
//	}
//
//public:
//	vector<vector<string> > solveNQueens(int n) {
//		vector<string> curQueens;
//		vector<vector<string> > rs;
//		recursiveFind(n, 0, curQueens, rs);
//		return rs;
//	}
//};
