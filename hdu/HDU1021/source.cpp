#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

int f[] = { 1, 2, 0, 2, 2, 1, 0, 1 };

int main() {
	freopen("ut.txt", "r", stdin);
	int num;
	while (scanf("%d", &num) != EOF) {
		if (f[num % 8] == 0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}