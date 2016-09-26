#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char alphabet[1000];
int target;

char can[6];
char ans[6];

int powi(int x, int n) {
	int res = 1;
	while (n) {
		res *= x;
		n--;
	}
	return res;
}

void solve(char alphabet[], int n, int left, int& res) {
	if (left == 0) {
		if (res == target) {
			if (strcmp(can, ans) > 0)
				strcpy(ans, can);
		}
	}
	else {
		int res2;
		for (int i = 0; i < n; ++i) {
			if (alphabet[i] != -1) {
				char foo = alphabet[i];
				can[5 - left] = foo + 'A' - 1;
				alphabet[i] = -1;
				res2 = res + powi(foo, 5 - left + 1) * (left % 2 ? 1 : -1);
				solve(alphabet, n, left - 1, res2);
				alphabet[i] = foo;
			}
		}
	}
}

int main() {
	freopen("ut.txt", "r", stdin);
	while (scanf("%d %s", &target, alphabet) != EOF) {
		if (target == 0 && strcmp(alphabet, "END") == 0)
			break;
		int n = strlen(alphabet);
		for (int i = 0; i < n; ++i)
			alphabet[i] -= 'A' - 1;
		memset(can, 0, 6);
		memset(ans, 0, 6);
		int res = 0;
		solve(alphabet, n, 5, res);
		if (ans[0] != 0) {
			//for (int i = 0; i < 5; ++i)
			//	ans[i] += 'A';
			printf("%s\n", ans);
		}
		else
			printf("no solution\n");
	}
	return 0;
}