#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 500005

int city[MAXN];
int inc[MAXN];

int main() {
	freopen("ut.txt", "r", stdin);
	int n;
	int poor, rich;
	int iCase = 1;
	while (scanf("%d", &n) != EOF) {
		memset(city, 0, sizeof(int) * MAXN);
		memset(inc, 0, sizeof(int) * MAXN);
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &poor, &rich);
			city[poor] = rich;
		}
		int nInc = 1;
		inc[0] = city[1];
		for (int i = 2; i <= n; ++i) {
			if (city[i] == 0)
				continue;
			if (city[i] > inc[nInc - 1]) {
				inc[nInc++] = city[i];
			}
			else if (city[i] < inc[nInc - 1]) {
				int* p = upper_bound(inc, inc + nInc, city[i]);
				*p = city[i];
			}
		}
		if (nInc == 1)
			printf("Case %d:\nMy king, at most %d road can be built.\n\n", iCase++, nInc);
		else
			printf("Case %d:\nMy king, at most %d roads can be built.\n\n", iCase++, nInc);
	}
	return 0;
}