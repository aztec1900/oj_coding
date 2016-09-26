#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int nCase, m, n;
	scanf("%d", &nCase);
	for (int iCase = 0; iCase < nCase; ++iCase) {
		int iiCase = 1;
		while (scanf("%d %d", &n, &m) != EOF) {
			if (n == 0 && m == 0)
				break;
			int ans = 0;
			for (int a = 1; a < n; ++a) {
				for (int b = a + 1; b < n; ++b) {
					if ((a*a + b*b + m) % (a*b) == 0)
						ans++;
				}
			}
			printf("Case %d: %d\n", iiCase++, ans);
		}
		if (iCase != nCase - 1)
			printf("\n");
	}
	return 0;
}