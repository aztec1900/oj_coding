#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canJump(vector<int>& nums) {
	int n = nums.size();
	if (n == 0)
		return true;
	int farest = 0;
	int i = 0;
	while (farest < n) {
		if (i == farest && nums[i] == 0)
			return i == n - 1; // if i is the end of the vector, of course the end is reached.
		farest = max(i + nums[i], farest);
		i++;
	}
	return true;
}

int main() {
	vector<int> nums = { 2, 3, 1, 1, 4 };
	cout << canJump(nums) << endl;
	return 0;
}