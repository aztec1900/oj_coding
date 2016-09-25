#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	//freopen("ut.txt", "r", stdin);
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		int ans = 1;
		int dp = a % 10;
		while (b) {
			if (b & 1)
				ans = (ans * dp) % 10;
			dp = (dp * dp) % 10;
			b >>= 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}