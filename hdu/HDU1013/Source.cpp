#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

#define MAX_LINE 10000
using namespace std;

int digitalRoot(int x) {
	if (x < 10)
		return x;
	int ans = 0;
	while (x) {
		ans += x % 10;
		x /= 10;
	}
	if (ans >= 10)
		return digitalRoot(ans);
	else
		return ans;
}

char line[MAX_LINE];

int main() {
	//freopen("ut.txt", "r", stdin);
	while (fgets(line, MAX_LINE, stdin)) {
		int x = 0;
		int i = 0;
		while (isdigit(line[i]))
			x += line[i++] - '0';
		if (x == 0)
			break;
		printf("%d\n", digitalRoot(x));
	}
	return 0;
}