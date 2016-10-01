#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define MAXN 1505

vector<int> G[MAXN];
int visited[MAXN];
int matching[MAXN]; //用于标记本轮的增广路径节点

bool hungarianDFS(int u) {
	for (int i = 0; i < G[u].size(); ++i) {
		int t = G[u][i];
		if (!visited[t]) {
			visited[t] = 1;
			if (matching[t] == -1 || hungarianDFS(matching[t])) {
				matching[t] = u;
				return true;
			}
		}
	}
	return false;
}

int hungarian(int n) {
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		memset(matching, -1, sizeof(int)*MAXN);
		if (hungarianDFS(i))
			ans++;
	}
	return ans;
}

int main() {
	int n, x, y, ny;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%d:(%d) ", &x, &ny);
			
		}
	}
}

