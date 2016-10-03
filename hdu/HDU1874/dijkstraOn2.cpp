#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 205
#define INT_INF 0x3fffffff

int Graph[MAXN][MAXN];
int dist[MAXN]; // dist[i] stores the current shortest distance between start to i
int visited[MAXN];

int dijkstra(int start, int end, int n) {
	int i, j;
	memset(visited, 0, sizeof(visited));
	visited[start] = 1;
	if (end == start)
		return 0;
	for (i = 0; i < n; i++)
		dist[i] = Graph[start][i];
	for (i = 1; i < n; i++)
	{
		int dmin = INT_INF, pos;
		for (j = 0; j < n; j++)
		{
			if (!visited[j] && dist[j] < dmin)
			{
				pos = j;
				dmin = dist[j];
			}
		}
		if (dmin == INT_INF || pos == end)
			break;
		visited[pos] = 1;
		for (j = 0; j < n; j++)
		{
			if (!visited[j] && dist[pos] + Graph[pos][j] < dist[j])
				dist[j] = dist[pos] + Graph[pos][j];
		}
	}
	if (dist[end] == INT_INF)
		return -1;
	else
		return dist[end];
}

int main2() {
	freopen("ut.txt", "r", stdin);
	int m, n, x, y, d;
	while (scanf("%d %d", &n, &m) != EOF) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				Graph[i][j] = INT_INF;
			}
			Graph[i][i] = 0;
		}
		while (m--) {
			scanf("%d %d %d", &x, &y, &d);
			if(Graph[x][y] > d)
				Graph[x][y] = Graph[y][x] = d;
		}
		int start, end;
		scanf("%d %d", &start, &end);
		printf("%d\n", dijkstra(start, end, n));
	}
	return 0;
}
