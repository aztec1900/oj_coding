#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b) {
	if (a < b)
		return gcd(b, a);
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main() {
	freopen("ut.txt", "r", stdin);
	int nCase;
	scanf("%d", &nCase);
	for (int iCase = 0; iCase < nCase; ++iCase) {
		int n;
		scanf("%d", &n);
		unsigned int ans;
		scanf("%d", &ans);
		int num;
		for (int i = 1; i < n; ++i) {
			scanf("%d", &num);
			ans = ans / gcd(ans, num) * num;
		}
		printf("%d\n", ans);
	}
	return 0;
}