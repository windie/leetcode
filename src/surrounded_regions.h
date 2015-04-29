class Solution {
    struct pos{
        int x;
        int y;
        pos(int xx, int yy) { x = xx; y = yy; }
    };
	void fill(vector<vector<char> >& check, int i, int j) {
	    if (i < 0 || j < 0 || i >= check.size() || j >= check[0].size() || check[i][j] != 'O') {
			return;
		}
	    stack<pos> s;
	    pos p(i, j);
	    s.push(p);
	    while(!s.empty()){
	        int ii = s.top().x;
	        int jj = s.top().y;
	        check[ii][jj] = 'Y';
	        s.pop();
	        if(ii - 1 >= 0 && check[ii - 1][jj] == 'O'){
	            pos pp(ii-1, jj);
	            s.push(pp);
	        }
	        if (jj - 1 >= 0 && check[ii][jj - 1] == 'O') {
	            pos pp(ii, jj-1);
	            s.push(pp);
	        }
	        if (ii + 1 < check.size() && check[ii + 1][jj] == 'O') {
	            pos pp(ii+1, jj);
	            s.push(pp);
	        }
	        if (jj + 1 < check[0].size() && check[ii][jj + 1] == 'O') {
	            pos pp(ii, jj+1);
	            s.push(pp);
	        }
	    }
	}

public:
	void solve(vector<vector<char> > &board) {
		if (board.size() == 0) {
			return;
		}
		int i, j;
		for (j = 0; j < board[0].size(); j++) {
			fill(board, 0, j);
		}
		for (j = 0; j < board[0].size(); j++) {
			fill(board, board.size() - 1, j);
		}
		for (i = 0; i < board.size(); i++) {
			fill(board, i, 0);
		}
		for (i = 0; i < board.size(); i++) {
			fill(board, i, board[0].size() - 1);
		}
		for (i = 0; i < board.size(); i++) {
			for (j = 0; j < board[0].size(); j++) {
				if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
		for (i = 0; i < board.size(); i++) {
			for (j = 0; j < board[0].size(); j++) {
				if (board[i][j] == 'Y') {
					board[i][j] = 'O';
				}
			}
		}
	}
};


//class Solution {
//	void fill(vector<vector<char> >& check, int i, int j) {
//		if (i < 0 || j < 0 || i >= check.size() || j >= check[0].size()
//				|| check[i][j] != 'O') {
//			return;
//		} else {
//			check[i][j] = 'Y';
//		}
//		if (i - 1 >= 0 && check[i - 1][j] == 'O') {
//			fill(check, i - 1, j);
//		}
//		if (j - 1 >= 0 && check[i][j - 1] == 'O') {
//			fill(check, i, j - 1);
//		}
//		if (i + 1 < check.size() && check[i + 1][j] == 'O') {
//			fill(check, i + 1, j);
//		}
//		if (j + 1 < check[0].size() && check[i][j + 1] == 'O') {
//			fill(check, i, j + 1);
//		}
//	}
//
//public:
//	void solve(vector<vector<char> > &board) {
//		if (board.size() == 0) {
//			return;
//		}
//		int i, j;
//		for (j = 0; j < board[0].size(); j++) {
//			fill(board, 0, j);
//		}
//		for (j = 0; j < board[0].size(); j++) {
//			fill(board, board.size() - 1, j);
//		}
//		for (i = 0; i < board.size(); i++) {
//			fill(board, i, 0);
//		}
//		for (i = 0; i < board.size(); i++) {
//			fill(board, i, board[0].size() - 1);
//		}
//		for (i = 0; i < board.size(); i++) {
//			for (j = 0; j < board[0].size(); j++) {
//				if (board[i][j] == 'O') {
//					board[i][j] = 'X';
//				}
//			}
//		}
//		for (i = 0; i < board.size(); i++) {
//			for (j = 0; j < board[0].size(); j++) {
//				if (board[i][j] == 'Y') {
//					board[i][j] = 'O';
//				}
//			}
//		}
//	}
//};
