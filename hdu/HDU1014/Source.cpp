#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

int gcd(int a, int b) {
	if (a < b)
		return gcd(b, a);
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int nDigit(int x) {
	int ans = 0;
	if (x == 0)
		return 1;
	while (x) {
		x /= 10;
		ans++;
	}
	return ans;
}

int main() {
	//freopen("ut.txt", "r", stdin);
	int step, mod, nd;
	bool firstLine = true;
	while (scanf("%d %d", &step, &mod) != EOF) {
		//if (!firstLine)
		//	printf("\n");
		//else
		//	firstLine = false;
		printf("%10d%10d", step, mod);
		if (gcd(mod, step) == 1)
			printf("    Good Choice\n");
		else
			printf("    Bad Choice\n");
		printf("\n");
	}
	return 0;
}