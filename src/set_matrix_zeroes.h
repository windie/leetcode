//class Solution {
//public:
//    void setZeroes(vector<vector<int> > &matrix) {
//    	if(matrix.empty()){
//    		return;
//    	}
//    	int nRow = matrix.size();
//    	int nCol = matrix[0].size();
//    	bool *rowtag = new bool[nRow];
//    	bool *coltag = new bool[nCol];
//    	memset(rowtag, false, sizeof(bool) * nRow);
//    	memset(coltag, false, sizeof(bool) * nCol);
//    	for(int i = 0; i< nRow; i++){
//    		for(int j = 0; j<nCol; j++){
//    			if(matrix[i][j]==0){
//    				rowtag[i]=true;
//    				coltag[j]=true;
//    			}
//    		}
//    	}
//    	for(int i=0; i< nRow; i++){
//    		for(int j=0; j<nCol; j++){
//    			if(rowtag[i] || coltag[j]){
//    				matrix[i][j] = 0;
//    			}
//    		}
//    	}
//    }
//};

class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		if (matrix.empty()) {
			return;
		}
		int nRow = matrix.size();
		int nCol = matrix[0].size();
		bool iscolzero = false;
		for (int i = 0; i < nRow; i++) {
			if (matrix[i][0] == 0) {
				iscolzero = true;
				break;
			}
		}
		int isrowzero = false;
		for (int i = 0; i < nCol; i++) {
			if (matrix[0][i] == 0) {
				isrowzero = true;
				break;
			}
		}

		for (int i = 1; i < nRow; i++) {
			for (int j = 1; j < nCol; j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i < nRow; i++) {
			for (int j = 1; j < nCol; j++) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}
		if (iscolzero) {
			for (int i = 0; i < nRow; i++) {
				matrix[i][0] = 0;
			}
		}
		if (isrowzero) {
			for (int i = 0; i < nCol; i++) {
				matrix[0][i] = 0;
			}
		}
	}
};
