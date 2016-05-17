#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(vector<string>& board, int n, int i, int j) {
	for (int k = 0; k<n; ++k) {
		if (board[i][k] == 'Q')
			return false;
	}
	for (int k = 0; k<n; ++k) {
		if (board[k][j] == 'Q')
			return false;
	}
	int b1 = j - i;
	int b2 = i + j;
	for (int x = 0; x<n; ++x) {
		int y = x + b1;
		if (y >= 0 && y<n && board[x][y] == 'Q')
			return false;
		y = -x + b2;
		if (y >= 0 && y<n && board[x][y] == 'Q')
			return false;
	}
	return true;
}
void solveNQueens(int n, int level, vector<string> path, vector<vector<string>>& ret) {
	if (level == n)
		ret.push_back(path);
	for (int i = 0; i<n; ++i) {
		if (isValid(path, n, level, i)) {
			path[level][i] = 'Q';
			if (level == n - 1) {
				ret.push_back(path);
				break;
			}
			else {
				solveNQueens(n, level + 1, path, ret);
				path[level][i] = '.';
			}
		}
	}
}
vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> ret;
	vector<string> path(n, string(n, '.'));
	solveNQueens(n, 0, path, ret);
	return ret;
}

void display(vector<string>& board) {
	for (string line : board)
		cout << line << endl;
	cout << "-------------------" << endl;
}

int main() {
	int n = 8;
	auto nQueensSolution = solveNQueens(n);
	for (auto sol : nQueensSolution)
		display(sol);
	system("pause");
	return 0;
}