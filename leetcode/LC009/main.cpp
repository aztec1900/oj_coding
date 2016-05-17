#include <iostream>

using namespace std;

bool isPalindrome(int x) {
	if (x < 0)
		return false;
	int base = 1;
	while (x / 10 >= base)
		base *= 10;
	while (base != 0) {
		if (x / base != x % 10)
			return false;
		else {
			x = (x % base) / 10;
			base /= 100;
		}
	}
	return true;
}

int main() {
	int x = 1000021;
	cout << isPalindrome(x);
	return 0;
}