#include<iostream>
using namespace std;

class Solution {
	bool find(vector<vector<char> > &board, vector<vector<bool> > &isvisit,
			int row, int col, string word, int curpos) {
		if (isvisit[row][col]) {
			return false;
		}
		if (board[row][col] != word[curpos]) {
			return false;
		} else {
			if(curpos+1 == word.size()){
				return true;
			}
			bool rs = false;
			if (row - 1 >= 0) {
				isvisit[row][col] = true;
				rs = find(board, isvisit, row - 1, col, word, curpos + 1);
				if(rs) {
					return true;
				}
				isvisit[row][col] = false;
			}
			if (row + 1 < board.size()) {
				isvisit[row][col] = true;
				rs = find(board, isvisit, row + 1, col, word, curpos + 1);
				if(rs) {
					return true;
				}
				isvisit[row][col] = false;
			}
			if (col - 1 >= 0) {
				isvisit[row][col] = true;
				rs = find(board, isvisit, row, col - 1, word, curpos + 1);
				if(rs) {
					return true;
				}
				isvisit[row][col] = false;
			}
			if (col + 1 < board[0].size()) {
				isvisit[row][col] = true;
				rs = find(board, isvisit, row, col + 1, word, curpos + 1);
				if(rs) {
					return true;
				}
				isvisit[row][col] = false;
			}
			return false;
		}
	}

public:
	bool exist(vector<vector<char> > &board, string word) {
		if(word.size()==0){
			return true;
		}
		if (board.size() == 0) {
			return false;
		}
		vector<vector<bool> > isvisit;
		vector<bool> tmp;
		for (int i = 0; i < board[0].size(); i++) {
			tmp.push_back(false);
		}
		for (int i = 0; i < board.size(); i++) {
			isvisit.push_back(tmp);
		}
		for(int i = 0; i<board.size(); i++){
			for(int j=0; j<board[i].size(); j++){
				int rs = find(board, isvisit, i, j, word, 0);
				if(rs){
					return true;
				}
			}
		}
		return false;
	}
};
