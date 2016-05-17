#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinationSum2(vector<int>& nums, vector<int>& freq, int start,
	vector<int> path, int target, vector<vector<int>>& ret) {
	for (int i = start; i<nums.size(); ++i) {
		if (nums[i] <= target) {
			int targetNext = target;
			auto path2 = path;
			for (int cnt = 0; cnt<freq[i]; ++cnt) {
				if (targetNext > nums[i]) {
					path2.push_back(nums[i]);
					targetNext -= nums[i];
					combinationSum2(nums, freq, i + 1, path2, targetNext, ret);
					//path.pop_back();
				}
				else if (targetNext == nums[i]) {
					path2.push_back(nums[i]);
					ret.push_back(path2);
					break;
				}
				else
					break;
			}
		}
		else if (nums[i] == target) {
			path.push_back(target);
			ret.push_back(path);
			break;
		}
		else
			break;
	}
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<int> nums;
	vector<int> freq;
	int cnt = 0;
	for (int i = 0; i<candidates.size(); ++i) {
		if (i == 0 || (i != 0 && candidates[i] != candidates[i - 1])) {
			nums.push_back(candidates[i]);
			freq.push_back(1);
			cnt++;
		}
		else
			freq[cnt - 1]++;
	}
	vector<vector<int>> ret;
	combinationSum2(nums, freq, 0, {}, target, ret);
	return ret;
}

int main() {
	vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
	int target = 8;
	auto ret = combinationSum2(candidates, target);
	return 0;
}