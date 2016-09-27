#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 130

long long dp[MAXN][MAXN];
int m = 0;

long long calc(int max, int n) {
	if (dp[max][n] != 0)
		return dp[max][n];
	if (max > n) {
		dp[max][n] = calc(n, n);
		return dp[max][n];
	}
	if (max == 1) {
		dp[max][n] = 1;
		return 1;
	}
	if (n % max == 0)
		dp[max][n] += 1;
	for (int i = n; i >= 0; i -= max)
		dp[max][n] += calc(max - 1, n);
	return dp[max][n];
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", calc(n, n));
	}
	return 0;
}
