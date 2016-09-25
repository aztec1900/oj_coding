#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int nCase, n, num, ans;
	scanf("%d", &nCase);
	for (int iCase = 0; iCase < nCase; ++iCase) {
		scanf("%d", &n);
		ans = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &num);
			ans += num;
		}
		printf("%d\n", ans);
	}
	return 0;
}