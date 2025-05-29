#include<iostream>
#include<vector>
using namespace std;

int n, m;
int mov[4] = { -1,1,0,0 };
int mx = 0;

void dfs(vector<vector<int>>& v, vector<vector<bool>>&visit,int x,int y,int cnt,int sum) {

	if (cnt == 4) {
		if (sum > mx)mx = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int tx = x + mov[i];
		int ty = y + mov[3 - i];

		if (tx >= 0 && tx < n && ty >= 0 && ty < m && !visit[tx][ty]) {
			visit[tx][ty] = 1;
			dfs(v, visit, tx, ty, cnt + 1, sum + v[tx][ty]);
			visit[tx][ty] = 0;

		}

	}

}

void t(vector<vector<int>>& v, vector<vector<bool>>& visit, int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		if (sum > mx)mx = sum;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int tx = x + mov[i];
		int ty = y + mov[3 - i];

		if (tx >= 0 && tx < n && ty >= 0 && ty < m && !visit[tx][ty]) {
			visit[tx][ty] = 1;
			t(v, visit, x, y, cnt + 1, sum + v[tx][ty]);
			visit[tx][ty] = 0;

		}

	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	vector<vector<bool>>visit(n, vector<bool>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = 1;
			dfs(v, visit, i, j, 1, v[i][j]);
			t(v, visit, i, j, 1, v[i][j]);
			visit[i][j] = 0;
		}
	}
	cout << mx;
}