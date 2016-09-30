#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 6000

typedef long long ll;

ll dp[MAXN];
int ind[8];

char base[5][3] = { "th", "st", "nd", "rd", "th" };

int main() {
	freopen("ut.txt", "r", stdin);
	int n, m = 0;
	dp[0] = 1;
	memset(ind, 0, sizeof(int) * 8);
	while (scanf("%d", &n) != EOF && n) {
		if (n - 1 > m) {
			for (int i = m + 1; i < n; ++i) {
				dp[i] = min(min(dp[ind[2]] * 2, dp[ind[3]] * 3), min(dp[ind[5]] * 5, dp[ind[7]] * 7));
				if (dp[i] == dp[ind[2]] * 2)
					ind[2]++;
				if (dp[i] == dp[ind[3]] * 3)
					ind[3]++;
				if (dp[i] == dp[ind[5]] * 5)
					ind[5]++;
				if (dp[i] == dp[ind[7]] * 7)
					ind[7]++;
			}
			m = n - 1;
		}
		char* baseToUse;
		if (n % 100 > 10 && n % 100 < 20)
			baseToUse = base[0];
		else if (n % 10 <= 3)
			baseToUse = base[n % 10];
		else
			baseToUse = base[0];
		printf("The %d%s humble number is %lld.\n", n, baseToUse, dp[n - 1]);
	}
	return 0;
}