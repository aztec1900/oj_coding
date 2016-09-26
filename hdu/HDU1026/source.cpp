#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 200
#define LIMIT_MAX 1000000

char maze[MAXN][MAXN];
int dp[MAXN][MAXN];
int moves[MAXN][MAXN];

int dir1[] = { 0, 0, 1, -1 };
int dir2[] = { 1, -1, 0, 0 };

int dfs(int i, int j, int m, int n) {
	if (dp[i][j] != 0)
		return dp[i][j];
	if (i == n - 1 && j == m - 1)
		return maze[i][j] == '.' ? 0 : maze[i][j] - '0';
	int ans = LIMIT_MAX, ii, jj;
	char foo = maze[i][j];
	maze[i][j] = 'X';
	for (int d = 0; d < 4; ++d) {
		ii = i + dir1[d];
		jj = j + dir2[d];
		if (ii >= 0 && ii < n && jj >= 0 && jj < m && maze[ii][jj] != 'X') {
			int t = dfs(ii, jj, m, n);
			if (t < ans) {
				ans = t;
				moves[i][j] = d;
			}
		}
	}
	maze[i][j] = foo;
	ans++;
	if (maze[i][j] == '.')
		dp[i][j] = ans;
	else
		dp[i][j] = ans + maze[i][j] - '0';
	return dp[i][j];
}

int main() {
	freopen("ut.txt", "r", stdin);
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		getchar();
		memset(maze, 0, sizeof(char)*MAXN*MAXN);
		memset(dp, 0, sizeof(int)*MAXN*MAXN);
		memset(moves, 0, sizeof(int)*MAXN*MAXN);
		for (int i = 0; i < n; ++i) {
			fgets(maze[i], MAXN, stdin);
		}
		int ans = dfs(0, 0, m, n);
		if (ans >= LIMIT_MAX)
			printf("God please help our poor hero.\n"); 
		else {
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", ans);
			int i = 0, j = 0;
			int t = 1;
			while (t <= ans) {
				if (maze[i][j] != '.') {
					for (int sub = 0; sub < maze[i][j] - '0'; ++sub)
						printf("%ds:FITGHT AT (%d,%d)\n", t++, i, j);
				}
				int ii = i + dir1[moves[i][j]];
				int jj = j + dir2[moves[i][j]];
				if (t <= ans)
					printf("%ds:(%d,%d)->(%d,%d)\n", t++, i, j, ii, jj);
				i = ii;
				j = jj;
			}
		}
		printf("FINISH\n");
	}
	return 0;
}