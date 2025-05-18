#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int mov[4] = { 1,-1,0,0 };

void bfs(vector<vector<char>>& v, vector<vector<bool>>& visit, int n, int i, int j) {
	queue<pair<int, int>>q;
	q.push({ i,j });
	visit[i][j] = 1;
	char color = v[i][j];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (v[x][y] == 'R')v[x][y] = 'G';
		q.pop();
		for (int i = 0; i < 4; i++) {
			int tx = x + mov[i];
			int ty = y + mov[3 - i];
			if (tx >= 0 && tx < n && ty >= 0 && ty < n && v[tx][ty] == color && !visit[tx][ty]) {
				q.push({ tx,ty });
				visit[tx][ty] = 1;
				
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<vector<char>>v(n,vector<char>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	vector<vector<bool>>visit(n, vector<bool>(n, 0));
	int sect = 0;
	for (int i= 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				bfs(v, visit, n, i, j);
				sect++;
			}
		}
	}
	cout << sect << ' ';
	vector < vector<bool>>visit2(n, vector<bool>(n, 0));
	sect = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit2[i][j]) {
				bfs(v, visit2, n, i, j);
				sect++;
			}
		}
	}
	cout << sect;
}