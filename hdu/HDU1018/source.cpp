#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


int main() {
	int nCase;
	scanf("%d", &nCase);
	for (int iCase = 0; iCase < nCase; ++iCase) {
		int n;
		scanf("%d", &n);
		double ans = 0;
		for (int i = 1; i <= n; ++i)
			ans += log10(i);
		printf("%d\n", (int)ans+1);
	}
	return 0;
}