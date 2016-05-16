#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ret;
	int n = nums.size();
	if (n < 3)
		return ret;
	sort(nums.begin(), nums.end());
	int i = 0;
	while (i <= n - 3) {
		int j = i + 1;
		int k = n - 1;
		while (j < k && j < n && k >= 0) {
			int sum = nums[j] + nums[k] + nums[i];
			if (sum == 0) {
				ret.push_back({ nums[i], nums[j], nums[k] });
				j++;
				while (j < n && nums[j] == nums[j - 1])
					j++;
				//break;
			}
			else if (sum < 0) {
				j++;
				while (j < n && nums[j] == nums[j - 1])
					j++;
			}
			else {
				k--;
				while (k >= 0 && nums[k] == nums[k + 1])
					k--;
			}
		}
		i++;
		while (i < n && nums[i] == nums[i - 1])
			i++;
	}
	return ret;
}

int main() {
	vector<int> nums = {-2, 0, 1, 1, 2};
	auto ret = threeSum(nums);
	return 0;
}