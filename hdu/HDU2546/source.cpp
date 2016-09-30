#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 1005

int price[MAXN];
int dp[MAXN][MAXN];

int minRemain(int r, int n) {
	if (n == 0 || r < 5)
		return r;
	else if (dp[r][n] != 0x1010101)
		return dp[r][n];
	else {
		dp[r][n] = min(minRemain(r - price[n - 1], n - 1), minRemain(r, n - 1));
		return dp[r][n];
	}
}

int cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("ut.txt", "r", stdin);
	int n, m;
	while (scanf("%d", &n) != EOF) {
		if (n == 0)
			break;
		for (int i = 0; i < n; ++i)
			scanf("%d", &price[i]);
		sort(price, price + n, cmp);
		scanf("%d", &m);
		memset(dp, 1, sizeof(int)*MAXN*MAXN);
		printf("%d\n", minRemain(m, n));
	}
	return 0;
}