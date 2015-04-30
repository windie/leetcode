class Solution {
    bool isvalid(vector<vector<char> > &board, int idxi, int idxj){
        int row = idxi/3;
        int col = idxj/3;
        vector<bool> dic0(10, false);
        for(int i = row * 3; i < row * 3 + 3; i++){
            for(int j = col * 3; j < col * 3 + 3; j++){
                if(board[i][j] == '.'){
                     continue;
                }
                if(dic0[board[i][j]-'0']){
                     return false;
                }else{
                     dic0[board[i][j]-'0'] = true;
                }
            }
        }
        vector<bool> dic(10, false);
        for(int i = 0; i<board.size(); i++){
            if(board[i][idxj] == '.'){
                continue;
            }
            if(dic[board[i][idxj]-'0']){
                return false;
            }else{
                dic[board[i][idxj]-'0'] = true;
            }
        }
        vector<bool> dic1(10, false);
        for(int j = 0; j<board[0].size(); j++){
            if(board[idxi][j] == '.'){
                continue;
            }
            if(dic1[board[idxi][j]-'0']){
                return false;
            }else{
                dic1[board[idxi][j]-'0'] = true;
            }
        }
        return true;
    }
    bool findnext(vector<vector<char> > &board, int &ni, int &nj){
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                if(board[i][j] == '.'){
                    ni = i;
                    nj = j;
                    return true;
                }
            }
        }
        return false;
    }
    bool check(vector<vector<char> > &board, int i, int j){
        if(board[i][j] == '.'){
            for(int v = 1; v<=9; v++){
                board[i][j] = v + '0';
                if(isvalid(board, i, j)){
                    if(check(board, i, j)){
                        return true;
                    }
                }
            }
            board[i][j] = '.';
            return false;
        }else{
            int ni, nj;
            if(findnext(board, ni, nj)){
                return check(board, ni, nj);
            }else{
                return true;
            }
        }
    }
public:
    void solveSudoku(vector<vector<char> > &board) {
        if(board.size() == 0 || board[0].size()==0){
            return;
        }
        check(board, 0, 0);
    }
};

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
