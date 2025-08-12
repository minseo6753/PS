#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>>map(n, vector<int>(m));
	int cheese = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)cheese++;
		}
	}

	queue<pair<int, int>>q;
	
	int mov[4] = { 1,-1,0,0 };
	int time = 0;
	while (cheese) {
		time++;
		vector<vector<int>>visit(n, vector<int>(m,0));
		q.push({ 0,0 });
		visit[0][0] = -1;
		while (!q.empty()) {
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int tr = row + mov[i];
				int tc = col + mov[3 - i];
				if (tr < 0 || tr >= n || tc < 0 || tc >= m)continue;
				if (visit[tr][tc]==-1)continue;
				if (map[tr][tc] == 1) {
					visit[tr][tc]++;
					if (visit[tr][tc] >= 2) {
						visit[tr][tc] = -1;
						map[tr][tc] = 0;
						cheese--;
					}
				}
				else {
					visit[tr][tc] = -1;
					q.push({ tr,tc });
				}
			}
		}
	}

	cout << time;
}