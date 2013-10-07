#include <iostream>
using namespace std;

class Solution {
	void ratateEdge(vector<vector<int> > &matrix, int row, int width) {
		int left = row, top = row, right = row + width - 1, bottom = row + width
				- 1;
		for (int i = 0; i < width - 1; i++) {
			int i1 = matrix[top][left + i];
			int i2 = matrix[top + i][right];
			int i3 = matrix[bottom][right - i];
			int i4 = matrix[bottom - i][left];

			matrix[top + i][right] = i1;
			matrix[bottom][right - i] = i2;
			matrix[bottom - i][left] = i3;
			matrix[top][left + i] = i4;
		}
	}

public:
	void rotate(vector<vector<int> > &matrix) {
		if (matrix.empty()) {
			return;
		}
		int n = matrix.size();
		for (int i = n, row = 0; i > 1; i -= 2, row++) {
			ratateEdge(matrix, row, i);
		}
	}
};
