#include <iostream>
#include <vector>
#include <string>

using namespace std;

void display(vector<vector<char>>& board) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
}

bool isValidSudoku(vector<vector<char>>& board, int i, int j) {
	vector<int> hash(9, 0);
	for (int k = 0; k<9; k++) {
		if (board[i][k] != '.') {
			int num = board[i][k] - '0';
			if (hash[num - 1] == 1)
				return false;
			else
				hash[num - 1] = 1;
		}
	}
	hash = vector<int>(9, 0);
	for (int k = 0; k<9; k++) {
		if (board[k][j] != '.') {
			int num = board[k][j] - '0';
			if (hash[num - 1] == 1)
				return false;
			else
				hash[num - 1] = 1;
		}
	}
	int secx = i / 3;
	int secy = j / 3;
	hash = vector<int>(9, 0);
	for (int m = 0; m<3; ++m) {
		for (int n = 0; n<3; ++n) {
			if (board[secx*3 + m][secy*3 + n] != '.') {
				int num = board[secx*3 + m][secy*3 + n] - '0';
				if (hash[num - 1] == 1)
					return false;
				else
					hash[num - 1] = 1;
			}
		}
	}
	return true;
}
bool solveSudoku(vector<vector<char>>& board, int i, int j) {
	if (i == 8 && j == 8)
		return true;
	while (i < 9 && j < 9 && board[i][j] != '.') {
		if (j == 8) {
			j = 0;
			i++;
		}
		else
			j++;
	}
	for (int num = 1; num <= 9; ++num) {
		board[i][j] = num + '0';
		if (isValidSudoku(board, i, j)) {
			if (solveSudoku(board, i, j))
				return true;
		}
	}
	board[i][j] = '.';
	return false;
}
void solveSudoku(vector<vector<char>>& board) {
	solveSudoku(board, 0, 0);
}



int main() {
	vector<string> boardStr = {".265...9.", "5...79..4", "3...1....", "6.....8.7", ".75.2..1.", ".1....4..", "...3.89.2", "7...6..4.", ".3.2..1.."};
	vector<vector<char>> board(9, vector<char>(9, 0));
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j)
			board[i][j] = boardStr[i][j];
	}
	solveSudoku(board);
	display(board);
	system("pause");
	return 0;
}