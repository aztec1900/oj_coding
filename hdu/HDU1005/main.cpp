#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int dp[50];
int tab[71];

int main() {
	//freopen("ut.txt", "r", stdin);
	int a, b, n;
	while (scanf("%d %d %d", &a, &b, &n) != EOF) {
		if (a == 0 && b == 0 && n == 0)
			break;

		memset(dp, 0, sizeof(int) * 50);
		memset(tab, 0, sizeof(int) * 71);
		dp[0] = 1, dp[1] = 1;
		tab[11] = 1;
		int i;
		int ind;
		for (i = 2; i < n; ++i) {
			dp[i] = (a * dp[i - 1] + b * dp[i - 2]) % 7;
			ind = dp[i] + dp[i - 1] * 10;
			if (tab[ind] != 0)
				break;
			else
				tab[ind] = i;
		}
		int ans;
		if (n-1 < i)
			ans = dp[n-1];
		else {
			int start = tab[ind] - 1;
			int interval = i - tab[ind];
			ans = dp[start + (n - 1 - start) % interval];
		}
		printf("%d\n", ans);
	}
	return 0;
}