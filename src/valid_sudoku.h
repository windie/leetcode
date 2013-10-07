#include <iostream>
using namespace std;

class Solution {
private:
	bool isValidGrid(vector<vector<char> > &board, int row, int col) {
		bool* isDup = new bool[10];
		memset(isDup, false, sizeof(bool) * 10);
		for (int i = row; i < row + 3; i++) {
			for (int j = col; j < col + 3; j++) {
				if (board[i][j] == '.') {
					continue;
				}
				if (isDup[board[i][j] - '0']) {
					return false;
				} else {
					isDup[board[i][j] - '0'] = true;
				}
			}
		}
		return true;
	}

public:
	bool isValidSudoku(vector<vector<char> > &board) {
		for (int i = 0; i < board.size(); i++) {
			bool* isDup = new bool[10];
			memset(isDup, false, sizeof(bool) * 10);
			for (int j = 0; j < board.size(); j++) {
				if (board[i][j] == '.') {
					continue;
				}
				if (isDup[board[i][j] - '0']) {
					return false;
				} else {
					isDup[board[i][j] - '0'] = true;
				}
			}
			delete[] isDup;
		}

		for (int j = 0; j < board[0].size(); j++) {
			bool* isDup = new bool[10];
			memset(isDup, false, sizeof(bool) * 10);
			for (int i = 0; i < board.size(); i++) {
				if (board[i][j] == '.') {
					continue;
				}
				if (isDup[board[i][j] - '0']) {
					return false;
				} else {
					isDup[board[i][j] - '0'] = true;
				}
			}
			delete[] isDup;
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (!isValidGrid(board, i * 3, j * 3)) {
					return false;
				}
			}
		}
		return true;
	}
};
