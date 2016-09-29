#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXN 1000005

using namespace std;

typedef long long ll;

ll dp[MAXN], pre[MAXN];
int a[MAXN];

int main() {
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {
		memset(dp, 0, sizeof(ll)*MAXN);
		memset(pre, 0, sizeof(ll)*MAXN);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int j = 0; j < m; ++j) {
			for (int i = j; i < n; ++i) {
				dp[i] = max(dp[i - 1], pre[i - 1]) + a[i];
			}
		}
	}
}