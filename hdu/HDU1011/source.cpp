#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define MAXN 101

struct TreeNode {
	int bug;
	int p;
	int next[MAXN];
	int nNext;
};

TreeNode nodes[MAXN];

int maxBrain(int iNode, int nTroop) {
	if (nTroop <= 0)
		return 0;
	int b1 = 0, b2 = 0;
	if (nTroop * 20 >= nodes[iNode].bug) {
		b1 = nodes[iNode].p;
		int troopleft = nTroop - (nodes[iNode].bug % 20 == 0 ? nodes[iNode].bug / 20 : nodes[iNode].bug / 20 + 1);
		int bnext = 0;
		for (int i = 0; i < nodes[iNode].nNext; ++i) {
			bnext = max(bnext, maxBrain(nodes[iNode].next[i], troopleft));
		}
		b1 += bnext;
	}
	for (int i = 0; i < nodes[iNode].nNext; ++i) {
		b2 = max(b2, maxBrain(nodes[iNode].next[i], nTroop));
	}
	return max(b1, b2);
}

int main() {
	freopen("ut.txt", "r", stdin);
	int m, n;
	while (scanf("%d %d", &n, &m) != EOF) {
		if (n == -1 && m == -1)
			break;
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &nodes[i].bug, &nodes[i].p);
			nodes[i].nNext = 0;
		}
		for (int i = 0; i < n - 1; ++i) {
			int pre, nxt;
			scanf("%d %d", &pre, &nxt);
			nodes[pre - 1].next[nodes[pre - 1].nNext++] = nxt-1;
		}
		printf("%d\n", maxBrain(0, m));
	}
	return 0;
}