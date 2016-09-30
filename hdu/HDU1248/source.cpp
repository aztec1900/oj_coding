#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 10005

int dp[MAXN], v[] = {150,200,350};

int main() {
	freopen("ut.txt", "r", stdin);
	int nCase, n;
	scanf("%d", &nCase);
	for (int iCase = 0; iCase < nCase; ++iCase) {
		memset(dp, 0, sizeof(int)*MAXN);
		scanf("%d", &n);
		for (int i = 0; i < 3; ++i) {
			for (int j = v[i]; j <= n; ++j) {
				dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
			}
		}
		printf("%d\n", n - dp[n]);
	}
	return 0;
}