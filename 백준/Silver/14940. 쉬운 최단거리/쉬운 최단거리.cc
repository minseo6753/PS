#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int>>&map, vector<vector<int>>&dist, int n, int m, int dx, int dy) {
	queue<pair<int,int>>q;
	q.push({ dx,dy });

	vector<vector<bool>>visit(n, vector<bool>(m, 0));
	visit[dx][dy] = 1;

	dist[dx][dy] = 0;

	int mov[] = {1,-1,0,0};

	int cnt = 1;
	while (q.size()) {
		int num = 0;
		while (cnt--) {

			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			int d = dist[x][y];

			for (int i = 0; i < 4; i++) {
				int tx = x + mov[i];
				int ty = y + mov[3 - i];
				if (tx >= 0 && tx < n && ty >= 0 && ty < m && map[tx][ty] == 1 && visit[tx][ty] == 0) {
				
					q.push({ tx,ty });
					visit[tx][ty] = 1;

					dist[tx][ty] = d + 1;

					num++;
				}
			}
		}
		cnt = num;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>>map(n, vector<int>(m));
	vector<vector<int>>dist(n, vector<int>(m,-1));
	int dx, dy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				dx = i;
				dy = j;
			}
			if (map[i][j] == 0)dist[i][j] = 0;
		}
	}

	bfs(map, dist, n, m, dx, dy);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	
}