#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 1000005

using namespace std;

typedef long long ll;

ll dp[MAXN], pre[MAXN];
int a[MAXN];

int main() {
	freopen("ut.txt", "r", stdin);
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {
		memset(dp, 0, sizeof(ll)*MAXN);
		memset(pre, 0, sizeof(ll)*MAXN);
		ll dpMax;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int j = 0; j < m; ++j) {
			dpMax = INT_MIN;
			for (int i = j; i < n; ++i) {
				if(i == 0)
					dp[i] = a[i];
				else {
					dp[i] = max(dp[i - 1], pre[i - 1]) + a[i];
					pre[i - 1] = dpMax;
				}
				dpMax = max(dpMax, dp[i]);
			}
		}
		printf("%lld\n", dpMax);
	}
	return 0;
}