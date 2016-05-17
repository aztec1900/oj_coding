#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
	int m = matrix.size();
	if (m == 0)
		return{};
	int n = matrix[0].size();
	if (n == 0)
		return{};
	vector<int> ret;
	int top = 0, buttom = m, left = 0, right = n;
	int i = 0, j = 0;
	while (top != buttom && left != right) {
		i = top;
		for (j = left; j<right; ++j)
			ret.push_back(matrix[i][j]);
		top++;
		if (top == buttom)
			break;
		j = right - 1;
		for (i = top; i<buttom; ++i)
			ret.push_back(matrix[i][j]);
		right--;
		if (left == right)
			break;
		i = buttom - 1;
		for (j = right - 1; j >= left; --j)
			ret.push_back(matrix[i][j]);
		buttom--;
		if (top == buttom)
			break;
		j = left;
		for (i = buttom - 1; i >= top; --i)
			ret.push_back(matrix[i][j]);
		left++;
		i = top;
	}
	return ret;
}

int main() {
	vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	auto ret = spiralOrder(matrix);
	return 0;
}