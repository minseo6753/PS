#include<iostream>
#include<vector>
using namespace std;

enum Direction{HORIZON,VERTICAL,DIAGONAL};

int dfs(int row, int col, Direction d, vector<vector<int>>& wall, int n) {

	if (row == n - 1 && col == n - 1) {
		return 1;
	}

	int sum = 0;
	bool goRight = col + 1 < n && !wall[row][col + 1];
	bool goDown = row + 1 < n && !wall[row + 1][col];
	if (d != VERTICAL) {
		if (goRight) {
			sum += dfs(row, col + 1, HORIZON, wall, n);
		}
	}
	if (d != HORIZON) {
		if (goDown) {
			sum += dfs(row + 1, col, VERTICAL, wall, n);
		}
	}
	if (goRight && goDown && !wall[row + 1][col + 1]) sum += dfs(row + 1, col + 1, DIAGONAL, wall, n);

	return sum;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>>wall(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> wall[i][j];
		}
	}

	cout << dfs(0, 1, HORIZON, wall, n);
}