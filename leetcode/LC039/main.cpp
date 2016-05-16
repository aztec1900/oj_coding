#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinationSum(vector<int>& candidates, int start, int target, vector<int> path, vector<vector<int>>& ret) {
	for (int i = start; i<candidates.size(); ++i) {
		if (candidates[i] < target) {
			path.push_back(candidates[i]);
			combinationSum(candidates, i, target - candidates[i], path, ret);
			path.pop_back();
		}
		else if (candidates[i] == target) {
			path.push_back(target);
			ret.push_back(path);
			break;
		}
		else
			break;
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int>> ret;
	combinationSum(candidates, 0, target, {}, ret);
	return ret;
}

int main() {
	vector<int> nums = { 1, 2 };
	int target = 3;
	auto ret = combinationSum(nums, target);
	return 0;
}
