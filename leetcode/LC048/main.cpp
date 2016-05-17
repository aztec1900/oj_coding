#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	if (n <= 1)
		return;
	for (int layer = 0; layer < n / 2; layer++) {
		//int foo = matrix[layer][layer];
		int side = n - layer * 2 - 1;
		for (int i = 0; i<side; ++i) {
			int foo = matrix[layer][layer + i];
			matrix[layer][layer + i] = matrix[n - 1 - layer - i][layer];
			matrix[n - 1 - layer - i][layer] = matrix[n - 1 - layer][n - 1 - layer - i];
			matrix[n - 1 - layer][n - 1 - layer - i] = matrix[layer + i][n - 1 - layer];
			matrix[layer + i][n - 1 - layer] = foo;
		}
	}
}

int main() {
	vector<vector<int>> matrix = { { 1, 2 }, { 3, 4 } };
	rotate(matrix);
	return 0;
}