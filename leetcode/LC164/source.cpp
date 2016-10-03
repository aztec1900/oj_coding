#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int maximumGap(vector<int>& nums) {
	int n = nums.size();
	if (n < 2) return 0;
	int maxV = nums[0], minV = nums[0];
	for (int i = 1; i<n; ++i) {
		maxV = max(maxV, nums[i]);
		minV = min(minV, nums[i]);
	}
	int inter = (maxV - minV) / n + 1;
	vector<int> busketMin(n, INT_MAX), busketMax(n, INT_MIN);
	for (int i = 0; i<n; ++i) {
		int ind = (nums[i] - minV) / inter;
		busketMin[ind] = min(busketMin[ind], nums[i]);
		busketMax[ind] = max(busketMax[ind], nums[i]);
	}
	int ans = busketMax[0] - busketMin[0];
	int pre = 0;
	for (int i = 1; i<n; ++i) {
		if (busketMax[i] != INT_MIN) {
			ans = max(busketMin[i] - busketMax[pre], ans);
			pre = i;
		}
	}
	return ans;
}

int main() {
	vector<int> nums = { 3,6,9,1 };
	cout << maximumGap(nums) << endl;
	return 0;
}