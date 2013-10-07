#include<iostream>
using namespace std;

class Solution {
	bool isvalid(vector<vector<char> > &board, int i, int j) {
		int row = i / 3;
		int col = j / 3;
		int dic[10] = { 0 };
		for (int ii = row * 3; ii < row * 3 + 3; ii++) {
			for (int jj = col * 3; jj < col * 3 + 3; jj++) {
				if (board[ii][jj] != '.') {
					if (dic[board[ii][jj] - '0'] == 0) {
						dic[board[ii][jj] - '0'] = 1;
					} else {
						return false;
					}
				}
			}
		}
		int dicrow[10] = { 0 };
		for (int jj = 0; jj < board.size(); jj++) {
			if (board[i][jj] != '.') {
				if (dicrow[board[i][jj] - '0'] == 0) {
					dicrow[board[i][jj] - '0'] = 1;
				} else {
					return false;
				}
			}
		}
		int diccol[10] = { 0 };
		for (int ii = 0; ii < board.size(); ii++) {
			if (board[ii][j] != '.') {
				if (diccol[board[ii][j] - '0'] == 0) {
					diccol[board[ii][j] - '0'] = 1;
				} else {
					return false;
				}
			}
		}
		return true;
	}
	bool findnextPos(vector<vector<char> > &board, int &ni, int &nj) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board.size(); j++) {
				if (board[i][j] == '.') {
					ni = i;
					nj = j;
					return true;
				}
			}
		}
		return false;
	}
	bool check(vector<vector<char> > &board, int i, int j) {
		if (board[i][j] == '.') {
			for (int k = 1; k <= 9; k++) {
				board[i][j] = k + '0';
				if (isvalid(board, i, j)) {
					if(check(board, i, j)){
						return true;
					}
				}
			}
			board[i][j] = '.';
			return false; // !!!
		} else {
			int ni, nj;
			if (findnextPos(board, ni, nj)) {
				return check(board, ni, nj);
			} else {
				return true;
			}
		}
	}
public:
	void solveSudoku(vector<vector<char> > &board) {
		check(board, 0, 0);
	}
};
