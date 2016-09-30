#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 1005

int dp[MAXN][MAXN];
int vol[MAXN], value[MAXN];

int package01(int v, int n) {
	if (dp[v][n] == -1) {
		if (n == 0)
			dp[v][n] = 0;
		else {
			if (v >= vol[n - 1])
				dp[v][n] = max(package01(v - vol[n - 1], n - 1) + value[n - 1], package01(v, n - 1));
			else
				dp[v][n] = package01(v, n - 1);
		}
	}
	return dp[v][n];
}

int main() {
	freopen("ut.txt", "r", stdin);
	int nCase, n, v;
	scanf("%d", &nCase);
	for (int iCase = 0; iCase < nCase; ++iCase) {
		scanf("%d %d", &n, &v);
		for (int i = 0; i < n; ++i)
			scanf("%d", &value[i]);
		for (int i = 0; i < n; ++i)
			scanf("%d", &vol[i]);
		memset(dp, -1, sizeof(int)*MAXN*MAXN);
		if (n == 0 || v == 0)
			printf("0\n");
		else
			printf("%d\n", package01(v, n));
	}
	return 0;
}