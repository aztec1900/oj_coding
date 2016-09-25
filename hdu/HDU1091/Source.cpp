#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		if (a == 0 && b == 0)
			break;
		printf("%d\n", a + b);
	}
	return 0;
}