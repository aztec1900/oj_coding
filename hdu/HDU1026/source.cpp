#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define MAXN 200
#define LIMIT_MAX 1000000

char maze[MAXN][MAXN];
int dp[MAXN][MAXN];
int moves[MAXN][MAXN];

struct Site {
	int i, j;
	char status;
	int step;
	bool operator<(const Site& rhs) const {
		return step > rhs.step;
	}
};

Site map[MAXN][MAXN];

int dir1[] = { 0, 0, 1, -1 };
int dir2[] = { 1, -1, 0, 0 };

int dfs(int i, int j, int m, int n) {
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
	if (maze[i][j] != '.')
		ans += maze[i][j] - '0';
	return ans;
}

void bfs(int n, int m) {
	priority_queue<Site> q;
	if (map[0][0].status != '.')
		map[0][0].step = map[0][0].status - '0';
	else
		map[0][0].step = 0;
	q.push(map[0][0]);
	while (!q.empty()) {
		Site node = q.top();
		q.pop();
		for (int d = 0; d < 4; ++d) {
			int ii = node.i + dir1[d];
			int jj = node.j + dir2[d];
			if (ii >= 0 && ii <= n && jj >= 0 && jj < m && map[ii][jj].status != 'X') {
				int step = node.step + 1 + (map[ii][jj].status == '.' ? 0 : map[ii][jj].status - '0');
				if (map[ii][jj].step > step) {
					map[ii][jj].step = step;
					moves[ii][jj] = d;
					if (ii == n - 1 && jj == m - 1)
						break;
					q.push(map[ii][jj]);
				}
			}
		}
	}
}

int t;

void out(int i, int j)
{
	if (moves[i][j] == -1)
		return;
	int ipre = i - dir1[moves[i][j]];
	int jpre = j - dir2[moves[i][j]];
	if (ipre < 0 || jpre < 0)
		return;
	out(ipre, jpre);
	if (isdigit(map[ipre][jpre].status))
	{
		for (int i = 0; i< map[ipre][jpre].status - '0'; i++)
			printf("%ds:FIGHT AT (%d,%d)\n", t++, ipre, jpre);
	}
	printf("%ds:(%d,%d)->(%d,%d)\n", t++, ipre, jpre, i, j);
}

int main() {
	freopen("ut.txt", "r", stdin);
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		getchar();
		memset(maze, 0, sizeof(char)*MAXN*MAXN);
		memset(dp, 0, sizeof(int)*MAXN*MAXN);
		memset(moves, -1, sizeof(int)*MAXN*MAXN);
		for (int i = 0; i < n; ++i) {
			fgets(maze[i], MAXN, stdin);
			for (int j = 0; j < m; ++j) {
				map[i][j].i = i;
				map[i][j].j = j;
				map[i][j].step = LIMIT_MAX;
				map[i][j].status = maze[i][j];
			}
		}
		bfs(n, m);
		int ans = map[n - 1][m - 1].step;
		if (ans >= LIMIT_MAX)
			printf("God please help our poor hero.\n"); 
		else {
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", ans);
			t = 1;
			out(n - 1, m - 1);
			if (isdigit(map[n - 1][m - 1].status)) {
				for (int i = 0; i < map[n - 1][m - 1].status - '0'; i++)
					printf("%ds:FIGHT AT (%d,%d)\n", t++, n - 1, m - 1);
			}
		}
		printf("FINISH\n");
	}
	return 0;
}