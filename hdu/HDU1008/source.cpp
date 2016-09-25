#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	freopen("ut.txt", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0)
			break;
		int pre = 0, cur, ans = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &cur);
			if (cur >= pre)
				ans += (cur - pre) * 6 + 5;
			else if (cur < pre)
				ans += (pre - cur) * 4 + 5;
			pre = cur;
		}
		printf("%d\n", ans);
	}
	return 0;
}