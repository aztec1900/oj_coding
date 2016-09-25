#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n, num, ans;
	while (scanf("%d", &n) != EOF) {
		ans = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &num);
			ans += num;
		}
		printf("%d\n", ans);
	}
	return 0;
}