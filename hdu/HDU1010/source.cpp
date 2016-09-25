#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int dirs[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
char board[7][7];

bool dfs(int i, int j, int t, int m, int n) {
	if (i < 0 || i >= n || j < 0 || j >= m)
		return false;
	if (t == 0)
		return board[i][j] == 'D';
	if (board[i][j] == 'D')
		return false;
	//bool ans = false;
	char status = board[i][j];
	board[i][j] = 'X';
	for (int d = 0; d < 4; ++d) {
		int ii = i + dirs[d][0];
		int jj = j + dirs[d][1];
		if (ii >= 0 && ii < n && jj >= 0 && jj < m && board[ii][jj] != 'X')
			if (dfs(ii, jj, t - 1, m, n))
				return true;
	}
	board[i][j] = status;
	return false;
}

int main() {
	freopen("ut.txt", "r", stdin);
	int m, n, t;
	while (scanf("%d %d %d", &n, &m, &t) != EOF) {
		if (n == 0 && m == 0 && t == 0)
			break;
		getchar();
		int start_i, start_j, door_i, door_j, wall = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				board[i][j] = getchar();
				if (board[i][j] == 'S') {
					start_i = i;
					start_j = j;
				}
				else if (board[i][j] == 'D') {
					door_i = i;
					door_j = j;
				}
				else if (board[i][j] == 'X')
					wall++;
			}
			getchar();
		}
		if ((door_i + door_j + start_i + start_j + t) % 2 == 1 || m*n - wall - 1 < t)
			printf("NO\n");
		else {
			if (dfs(start_i, start_j, t, m, n))
				printf("YES\n");
			else
				printf("NO\n");
		}
			
	}
	return 0;
}