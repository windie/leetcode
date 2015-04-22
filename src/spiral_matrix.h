class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int hei = matrix.size();
        if(hei == 0){
            return res;
        }
        int wid = matrix[0].size();
        int i = 0, j = 0;
        while(hei>0 && wid>0){
            if(hei == 1){
                for(int jj = j; jj < j+wid; jj++){
                    res.push_back(matrix[i][jj]);
                }
                break;
            }
            if(wid == 1){
                for(int ii = i; ii< i+ hei; ii++){
                    res.push_back(matrix[ii][j]);
                }
                break;
            }
            for(int jj = j; jj < j + wid -1; jj++){
                res.push_back(matrix[i][jj]);
            }
            for(int ii = i; ii < i + hei -1; ii++){
                res.push_back(matrix[ii][j + wid -1]);
            }
            for(int jj = j+wid-1; jj > j; jj--){
                res.push_back(matrix[i + hei -1][jj]);
            }
            for(int ii = i+hei-1; ii>i; ii--){
                res.push_back(matrix[ii][j]);
            }
            hei-=2;
            wid-=2;
            i++;
            j++;
        }
        return res;
    }
};

//#include <vector>
//using namespace std;
//
//class Solution {
//	void readedge(vector<vector<int> > & matrix, int rowi, int colj, int nrow,
//			int mcol, vector<int> &res) {
//		if (mcol <= 0 || nrow <= 0) {
//			return;
//		}
//		for (int j = colj; j < colj + mcol; j++) {
//			res.push_back(matrix[rowi][j]);
//		}
//		for (int i = rowi + 1; i < rowi + nrow; i++) {
//			res.push_back(matrix[i][colj + mcol - 1]);
//		}
//		for (int j = colj + mcol - 2; j >= colj && nrow!=1; j--) {
//			res.push_back(matrix[rowi + nrow - 1][j]);
//		}
//		for (int i = rowi + nrow - 2; i >= rowi + 1 && mcol!=1; i--) {
//			res.push_back(matrix[i][colj]);
//		}
//		readedge(matrix, rowi + 1, colj + 1, nrow - 2, mcol - 2, res);
//	}
//
//public:
//	vector<int> spiralOrder(vector<vector<int> > &matrix) {
//		vector<int> res;
//		if (matrix.size() == 0) {
//			return res;
//		}
//		readedge(matrix, 0, 0, matrix.size(), matrix[0].size(), res);
//		return res;
//	}
//};
