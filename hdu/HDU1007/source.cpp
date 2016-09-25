#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAXN 100005

struct Point {
	double x, y;
	int index;
};

int cmpx(Point a, Point b) {
	return a.x < b.x;
}

int cmpy(Point *a, Point *b) {
	return a->y < b->y;
}

Point ptx[MAXN];
Point pty[MAXN];
Point* ptTmp[MAXN];

int n;

double closet(int start, int end) {
	if (start == end - 1) {
		return hypot(ptx[start].x - ptx[end].x, ptx[start].y - ptx[end].y);
	}
	if (start == end - 2) {
		double ans = hypot(ptx[start].x - ptx[end].x, ptx[start].y - ptx[end].y);
		ans = min(ans, hypot(ptx[start].x - ptx[start+1].x, ptx[start].y - ptx[start+1].y));
		ans = min(ans, hypot(ptx[end - 1].x - ptx[end].x, ptx[end - 1].y - ptx[end].y));
		return ans;
	}
	int mid = start + (end - start) / 2;
	double d1 = closet(start, mid);
	double d2 = closet(mid + 1, end);
	double ans = min(d1, d2);
	double left = ptx[mid].x - ans;
	double right = ptx[mid].x + ans;
	int cnt = 0;
	//for (int i = 0; i < n; ++i) {
	//	if (pty[i].index >= start && pty[i].index <= end && pty[i].x >= left && pty[i].x <= right)
	//		ptTmp[cnt++] = &pty[i];
	//}
	for (int i = start; i <= end; ++i) {
		if (ptx[i].x >= left && ptx[i].x <= right)
			ptTmp[cnt++] = &ptx[i];
	}
	sort(ptTmp, ptTmp + cnt, cmpy);
	for (int i = 0; i < cnt; ++i) {
		for (int j = i + 1; j < cnt; ++j) {
			double dis = hypot(ptTmp[i]->x - ptTmp[j]->x, ptTmp[i]->y - ptTmp[j]->y);
			if (dis > ans)
				break;
			ans = min(ans, dis);
		}
	}
	return ans;
}

int main() {
	//freopen("ut.txt", "r", stdin);
	while (scanf("%d", &n) != EOF) {
		if (n == 0)
			break;
		for (int i = 0; i < n; ++i) {
			scanf("%lf %lf", &ptx[i].x, &ptx[i].y);
			ptx[i].index = i;
		}
		memcpy(pty, ptx, n*sizeof(Point));
		sort(ptx, ptx + n, cmpx);
		//sort(pty, pty + n, cmpy);
		printf("%.2lf\n", closet(0, n-1)/2);
	}
	return 0;
}