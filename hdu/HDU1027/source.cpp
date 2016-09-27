#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

#define MAXN 1005
int base[MAXN];
int can[MAXN];

int main() {
	freopen("ut.txt", "r", stdin);
	int m, n;
	while (scanf("%d %d", &n, &m) != EOF) {
		base[1] = 1;
		int i = 1;
		while (base[i] < m) {
			i++;
			base[i] = base[i - 1] * i;
		}
		int j;
		for (j = 0; j <= n; ++j)
			can[j] = j;
		for (j = 1; j <= n - i; ++j) {
			if (j != 1)
				printf(" ");
			printf("%d", j);
		}
		int start = n - i + 1;
		int order;
		m--;
		while (i) {
			if (i == 1)
				order = 0;
			else {
				order = m / base[i - 1];
				m -= base[i - 1] * order;
			}
			i--;
			for (j = start; j <= n; ++j) {
				if (can[j] != 0) {
					if (!order) {
						can[j] = 0;
						break;
					}
					order--;
				}
			}
			printf(" %d", j);
		}
		printf("\n");
	}
	return 0;
}