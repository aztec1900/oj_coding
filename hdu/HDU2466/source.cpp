#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 505
#define MAXM 5005

struct Item {
	int p, q, v;
};

bool cmp(Item a, Item b) {
	return a.q < b.q;
}

Item items[MAXN];
int dp[MAXM][MAXN];

int solve(int m, int n) {
	if (dp[m][n] != -1)
		return dp[m][n];
	if (m == 0 || n == 0)
		dp[m][n] = 0;
	else {
		if (m < items[n - 1].q)
			dp[m][n] = solve(m, n - 1);
		else
			dp[m][n] = max(solve(m - items[n - 1].p, n - 1) + items[n - 1].v, solve(m, n - 1));
	}
	return dp[m][n];
}

int main() {
	freopen("ut.txt", "r", stdin);
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF){
		for (int i = 0; i < n; ++i)
			scanf("%d %d %d", &items[i].p, &items[i].q, &items[i].v);
		sort(items, items + n, cmp);
		memset(dp, -1, sizeof(int)*MAXM*MAXN);
		printf("%d\n", solve(m, n));
	}
	return 0;
}