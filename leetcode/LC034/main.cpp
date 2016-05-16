#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
	int start = 0;
	if (nums.size() == 0)
		return{ -1, -1 };
	int end = nums.size() - 1;
	int mid = start + (end - start) / 2;
	while (start < end) {
		if (nums[mid] == target) {
			if (mid == 0 || (mid != 0 && nums[mid - 1] != target))
				break;
			else
				end = mid - 1;
		}
		else if (nums[mid] < target)
			start = mid + 1;
		else
			end = mid - 1;
		mid = start + (end - start) / 2;
	}
	vector<int> ret;
	if (nums[mid] == target)
		ret.push_back(mid);
	else
		return{ -1, -1 };
	start = mid;
	end = nums.size() - 1;
	mid = start + (end - start) / 2;
	while (start < end) {
		if (nums[mid] == target) {
			if (mid == nums.size() - 1 || (mid < nums.size() - 1 && nums[mid + 1] != target))
				break;
			else
				start = mid + 1;
		}
		else if (nums[mid] < target)
			start = mid + 1;
		else
			end = mid - 1;
		mid = start + (end - start) / 2;
	}
	ret.push_back(mid);
	return ret;
}

int main() {
	vector<int> nums = { 5, 5, 7, 7, 8, 8, 9 };
	int target = 8;
	auto ret = searchRange(nums, target);
	return 0;
}
