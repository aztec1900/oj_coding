#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 1000

char pw[MAXN];

bool isvowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	freopen("ut.txt", "r", stdin);
	while (scanf("%s", pw) != EOF) {
		if (strcmp(pw, "end") == 0)
			break;
		int vcnt = 0, ccnt = 0;
		bool hasVowel = false;
		if (isvowel(pw[0])) {
			hasVowel = true;
			vcnt = 1;
		}
		else {
			ccnt = 1;
		}
		int i;
		for (i = 1; i < strlen(pw); ++i) {
			if (vcnt) {
				if (isvowel(pw[i]))
					vcnt++;
				else {
					vcnt = 0;
					ccnt = 1;
				}
			}
			else {
				if (!isvowel(pw[i]))
					ccnt++;
				else {
					hasVowel = true;
					ccnt = 0;
					vcnt = 1;
				}
			}
			if (ccnt == 3 || vcnt == 3 || (pw[i] == pw[i - 1] && pw[i] != 'e' && pw[i] != 'o'))
				break;
		}
		if (i == strlen(pw) && hasVowel)
			printf("<%s> is acceptable.\n", pw);
		else
			printf("<%s> is not acceptable.\n", pw);
	}
	return 0;
}