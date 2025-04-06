#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;

int m, n;
bool v[50][50];

void dfs(int i, int j) {
	if (i < 0 || i >= m || j < 0 || j >= n)return;
	if (!v[i][j])return;
	v[i][j] = 0;
	dfs(i + 1, j);
	dfs(i, j + 1);
	dfs(i - 1, j);
	dfs(i, j - 1);
	return;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> m >> n >> k;
		memset(v, 0, sizeof(v));
		while (k--) {
			int x, y;
			cin >> x >> y;
			v[x][y] = 1;
		}
		int wom = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j]) {
					dfs(i, j);
					wom++;
				}
			}
		}
		cout << wom << '\n';
	}
}