#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
const int MAXN = 10005;

using namespace std;

char line[MAXN];

int main() {
	freopen("ut.txt", "r", stdin);
	int nCase;
	scanf("%d", &nCase);
	getchar();
	for (int iCase = 0; iCase < nCase; ++iCase) {
		fgets(line, MAXN, stdin);
		char pre = 0;
		int cnt = 1;
		char *p = line;
		while (*p && *p!= '\n') {
			if (*p == pre)
				cnt++;
			else {
				if (pre) {
					if (cnt > 1)
						printf("%d%c", cnt, pre);
					else
						printf("%c", pre);
				}
				pre = *p;
				cnt = 1;
			}
			p++;
		}
		if (cnt > 1)
			printf("%d%c\n", cnt, pre);
		else
			printf("%c\n", pre);
	}
	return 0;
}