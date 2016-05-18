#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	int carry = 1;
	for (int i = digits.size() - 1; i >= 0; --i) {
		if (carry == 0)
			break;
		if (digits[i] == 9) {
			digits[i] = 0;
		}
		else {
			digits[i] += carry;
			carry = 0;
		}
	}
	if (carry == 1)
		digits.insert(digits.begin(), 1);
	return digits;
}

int main() {
	vector<int> digits = { 9, 9, 9 };
	digits = plusOne(digits);
	return 0;
}