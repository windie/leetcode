#include <vector>
using namespace std;

class Solution {

	bool isValid(vector<int> &curQueens, int row, int col) {
		for (int i = 0; i < curQueens.size(); i++) {
			if (abs(row - i) == abs(col - curQueens[i])) {
				return false;
			}
		}
		return true;
	}

	void recursiveFind(int n, int curRow, bool *column, vector<int> & curQueens,
			int & rs) {
		if (curRow >= n) {
			rs++;
			return;
		}

		for (int colj = 0; colj < n; colj++) {
			if (column[colj]) {
				continue;
			}
			if (!isValid(curQueens, curRow, colj)) {
				continue;
			} else {
				column[colj] = true;
				curQueens.push_back(colj);
				recursiveFind(n, curRow + 1, column, curQueens, rs);
				curQueens.pop_back();
				column[colj] = false;
			}
		}
	}
public:
	int totalNQueens(int n) {
		vector<int> curQueens;
		int rs = 0;
		bool *column = new bool[n];
		memset(column, 0, sizeof(bool) * n);
		recursiveFind(n, 0, column, curQueens, rs);
		return rs;
	}
};
