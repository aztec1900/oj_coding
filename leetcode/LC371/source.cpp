#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>

using namespace std;

int getSum(int a, int b) {
	unsigned int ua = a, ub = b;
	int ret = 0;
	int carry = 0;
	int i = 0;
	while (ua || ub || carry && i < 32) {
		unsigned int bita = ua & 1, bitb = ub & 1;
		unsigned int bit = (bita ^ bitb ^ carry) << i;
		ret |= bit;
		i++;
		if ((bita & bitb) | (bita & carry) | (bitb & carry))
			carry = 1;
		else
			carry = 0;
		ua >>= 1;
		ub >>= 1;
	}
	return ret;
}

int main() {
	int i = 8;
	int carry = 32;
	cout << (i << carry) << endl;
	cout << getSum(1, -1) << endl;
	return 0;
}