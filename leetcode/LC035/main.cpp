#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
	int start = 0;
	int end = nums.size() - 1;
	int mid = start + (end - start) / 2;
	while (start < end - 1) {
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			start = mid;
		else
			end = mid;
		mid = start + (end - start) / 2;
	}
	if (target <= nums[start])
		return start;
	else if (target <= nums[end])
		return end;
	else
		return end + 1;
}

int main() {
	vector<int> nums = { 1, 2, 3 };
	cout << searchInsert(nums, 0) << endl;
	cout << searchInsert(nums, 5) << endl;
	return 0;
}