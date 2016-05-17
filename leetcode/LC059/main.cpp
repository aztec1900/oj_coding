#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
	if (n == 0)
		return{};
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	int left = 0, right = n, top = 0, buttom = n;
	int n2 = n*n;
	int cnt = 1;
	int direction = 0;
	int i = 0, j = 0;
	while (cnt <= n2) {
		matrix[i][j] = cnt;
		switch (direction) {
		case 0:
			if (j == right - 1) {
				top++;
				direction = (direction + 1) % 4;
				i = top;
			}
			else
				j++;
			break;
		case 1:
			if (i == buttom - 1) {
				right--;
				j = right - 1;
				direction = (direction + 1) % 4;
			}
			else
				i++;
			break;
		case 2:
			if (j == left) {
				buttom--;
				i = buttom - 1;
				direction = (direction + 1) % 4;
			}
			else
				j--;
			break;
		case 3:
			if (i == top) {
				left++;
				j = left;
				direction = (direction + 1) % 4;
			}
			else
				i--;
			break;
		}
		cnt++;
	}
	return matrix;
}

int main() {
	auto ret = generateMatrix(4);
	return 0;
}