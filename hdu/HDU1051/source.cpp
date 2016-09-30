#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 10005

struct Wood{
	int l, w;
};

bool cmp(Wood a, Wood b) {
	if (a.l == b.l)
		return a.w < b.w;
	else
		return a.l < b.l;
}

Wood woods[MAXN];

int main() {
	freopen("ut.txt", "r", stdin);
	int nCase, n;
	scanf("%d", &nCase);
	for (int iCase = 0; iCase < nCase; ++iCase) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d %d", &woods[i].l, &woods[i].w);
		sort(woods, woods + n, cmp);
		int l = 0, w = 0;
		int ans = 0;
		while (l != -1) {
			l = -1, w = -1;
			ans++;
			for (int i = 0; i < n; ++i) {
				if (woods[i].l != -1 && woods[i].l >= l && woods[i].w >= w) {
					l = woods[i].l;
					w = woods[i].w;
					woods[i].l = -1;
				}
			}
		}
		printf("%d\n", ans-1);
	}
	return 0;
}