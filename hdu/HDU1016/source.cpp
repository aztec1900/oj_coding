#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_set>

using namespace std;

unordered_set<int> prime = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };

int circle[30];
int nums[30];

void solve(int i, int n) {
	for (int k = 1; k < n; ++k) {
		if (nums[k] == 0 && prime.count(circle[i-1] + k + 1) != 0) {
			circle[i] = k + 1;
			if (i == n - 1) {
				if (prime.count(k + 2)) {
					for (int j = 0; j < n-1; ++j)
						printf("%d ", circle[j]);
					printf("%d\n", circle[n - 1]);
				}
				break;
			}
			else {
				nums[k] = 1;
				solve(i + 1, n);
				nums[k] = 0;
			}
		}
	}
}

int main() {
	freopen("ut.txt", "r", stdin);
	int n;
	int iCase = 1;
	while (scanf("%d", &n) != EOF) {
		memset(nums, 0, sizeof(int) * 30);
		memset(circle, 0, sizeof(int) * 30);
		printf("Case %d:\n", iCase++);
		if (n == 1)
			printf("1\n");
		else {
			circle[0] = 1;
			nums[0] = 1;
			solve(1, n);
		}
		printf("\n");
	}
	return 0;
}