#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>

#define MAXN 1005

using namespace std;

struct Room {
	int J, F;
	double rate;
};

bool cmp(Room a, Room b) {
	return a.rate > b.rate;
}

Room rooms[MAXN];

int main() {
	//freopen("ut.txt", "r", stdin);
	int catFood, n;
	while (scanf("%d %d", &catFood, &n) != EOF) {
		if (catFood == -1 && n == -1)
			break;
		for (int i = 0; i < n; ++i) {
			scanf("%d %d", &rooms[i].J, &rooms[i].F);
			rooms[i].rate = (double)rooms[i].J / rooms[i].F;
		}
		sort(rooms, rooms + n, cmp);
		double ans = 0;
		for (int i = 0; i < n; ++i) {
			if (catFood > rooms[i].F) {
				ans += rooms[i].J;
				catFood -= rooms[i].F;
			}
			else {
				ans += rooms[i].J * (double)catFood / rooms[i].F;
				break;
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}