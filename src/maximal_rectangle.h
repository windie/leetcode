class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.size() == 0)
			return 0;
		vector < vector<int>
				> l(matrix.size(), vector<int>(matrix[0].size(), 0));
		for (int j = 0; j < matrix.size(); j++) {
			l[j][0] = (matrix[j][0]=='1' ? 1: 0);
		}
		for(int i=0; i<matrix.size(); i++){
			for(int j=1; j<matrix[0].size(); j++){
				if(matrix[i][j]=='1'){
					l[i][j] = l[i][j-1] +1;
				}else{
					l[i][j] = 0;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if(matrix[i][j] == '1'){
					int k=i;
					int width = l[k][j];
					while(k>=0 && l[k][j]){
						width = min(width, l[k][j]);
						res = max(res, width*(i-k+1));
						k--;
					}
				}
			}
		}
		return res;
	}
};
