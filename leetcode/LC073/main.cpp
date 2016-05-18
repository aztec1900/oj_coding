#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	int m = matrix.size();
	if (m == 0)
		return;
	int n = matrix[0].size();
	bool col0Zero = false;
	for (int i = 0; i<m; ++i)
		if (matrix[i][0] == 0) {
			col0Zero = true;
			break;
		}
	bool row0Zero = false;
	for (int j = 0; j<n; ++j)
		if (matrix[0][j] == 0) {
			row0Zero = true;
			break;
		}
	for (int i = 1; i<m; ++i)
		for (int j = 1; j<n; ++j)
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
	for (int i = 1; i<m; ++i)
		if (matrix[i][0] == 0)
			for (int k = 1; k<n; ++k)
				matrix[i][k] = 0;
	for (int j = 1; j<n; ++j)
		if (matrix[0][j] == 0)
			for (int k = 1; k<m; ++k)
				matrix[k][j] = 0;
	if (col0Zero)
		for (int k = 0; k<m; ++k)
			matrix[k][0] = 0;
	if (row0Zero)
		for (int k = 0; k<n; ++k)
			matrix[0][k] = 0;
}

int main() {
	vector<vector<int>> matrix = { { 1, 1, 1 }, { 0, 1, 2 } };
	setZeroes(matrix);
	return 0;
}