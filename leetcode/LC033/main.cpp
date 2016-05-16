#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
	int n = nums.size();
	if (n == 0)
		return -1;
	if (n == 0)
		return nums[0] == target ? 0 : -1;
	int start = 0;
	int end = n - 1;
	int mid = start + (end - start) / 2;
	while (start < end) {
		if (nums[mid] == target)
			return mid;
		else if (nums[start] < nums[end]) {
			if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid - 1;
		}
		else {
			if (nums[mid] >= nums[start]) {
				if (nums[mid] < target)
					start = mid + 1;
				else {
					if (nums[start] <= target)
						end = mid - 1;
					else
						start = mid + 1;
				}
			}
			else {
				if (nums[mid] > target)
					end = mid - 1;
				else {
					if (target <= nums[end])
						start = mid + 1;
					else
						end = mid - 1;
				}
			}
		}
		mid = start + (end - start) / 2;
	}
	if (nums[mid] == target)
		return mid;
	else
		return -1;
}

int main() {
	vector<int> nums = { 3, 5, 1 };
	int target = 3;
	auto ret = search(nums, target);
	cout << ret << endl;
	return 0;
}