#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 300

char* multiple(char* a, char* b) {
	char* res = new char[MAXN];
	memset(res, 0, sizeof(char)*MAXN);
	int carry = 0, d1, d2, mul;
	for (int i = 0; i < strlen(a); ++i) {
		d1 = a[i] - '0';
		char *p = b;
		carry = 0;
		int j = 0;
		while (*p || carry) {
			d2 = 0;
			if (*p) {
				d2 = *p - '0';
				p++;
			}
			mul = d1 * d2 + res[i + j]+ carry;
			if (res[i + j])
				mul -= '0';
			res[i + j] = mul % 10 + '0';
			carry = mul / 10;
			j++;
		}
	}
	strcpy(a, res);
	delete res;
	return a;
}

char num[MAXN], res[MAXN];

int main() {
	freopen("ut.txt", "r", stdin);
	int power;
	char str[20];
	while (scanf("%s %d", str, &power) != EOF) {
		int digit = 0, i = 0, j = 0;
		int len = strlen(str);
		for (int i = len - 1; i >= 0;--i) {
			if (str[i] == '.')
				digit = len - i - 1;
			else
				num[j++] = str[i];
		}
		num[j] = '\0';
		res[0] = '1'; res[1] = '\0';
		for (i = 0; i < power; ++i) {
			multiple(res, num);
		}
		len = strlen(res);
		digit *= power;
		for (i = 0; i < digit; ++i) {
			if (res[i] != '0')
				break;
		}
		int digitEnd = i;
		for (i = len - 1; i >= digit; --i) {
			if (res[i] != '0')
				break;
		}
		int integerStart = i;
		if (integerStart < digit && digitEnd == digit)
			printf("0");
		else {
			for (i = integerStart; i >= digit; --i)
				printf("%c", res[i]);
			if (digitEnd != digit) {
				printf(".");
				for (i = digit - 1; i >= digitEnd; --i)
					printf("%c", res[i]);
			}
		}
		printf("\n");
	}
	return 0;
}