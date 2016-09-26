#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int label[20];
char in[10], out[10];

int main() {
	freopen("ut.txt", "r", stdin);
	int n;
	while (scanf("%d %s %s", &n, in, out) != EOF) {
		int i = 0, j = 0, k = 0;
		bool ans = true;
		stack<char> s;
		while (j < n) {
			if (s.empty() || s.top() != out[j]) {
				while (i < n && (s.empty() || s.top() != out[j])) {
					label[k++] = 0;
					s.push(in[i]);
					i++;
				}
			}
			if (s.top() != out[j]) {
				ans = false;
				break;
			}
			else {
				s.pop();
				label[k++] = 1;
				j++;
			}
		}
		if (ans) {
			printf("Yes.\n");
			for (int i = 0; i < n * 2; ++i) {
				if (label[i])
					printf("out\n");
				else
					printf("in\n");
			}
		}
		else
			printf("No.\n");
		printf("FINISH\n");
	}
	return 0;
}