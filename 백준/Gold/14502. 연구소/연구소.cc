#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int map[8][8];
int n, m;
vector<pair<int,int>> virus;
int minVirus = 64;

int mov[4] = { 0, 1, 0, -1 };
int bfs() {

	int tmap[8][8];
	copy(&map[0][0], &map[0][0] + 64, &tmap[0][0]);

	queue<pair<int, int>> q;

	int cnt = 0;

	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
		while(!q.empty()) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			cnt++;

			for (int i = 0; i < 4; i++) {
				int tr = r + mov[i];
				int tc = c + mov[3-i];
				if (tr >= 0 && tr < n && tc >= 0 && tc < m && tmap[tr][tc] == 0) {
					tmap[tr][tc] = 2;
					q.push({ tr, tc });
				}
			}
		}
	}

	return cnt;
}

void wall(int row, int col, int cnt) {

	if(cnt == 3) {
		minVirus = min(minVirus, bfs());
		return;
	}

	if(col >= m) {
		wall(row + 1, 0, cnt);
		return;
	}
	if(row >= n) {
		return;
	}

	if (map[row][col] == 0) {
		map[row][col] = 1;
		wall(row, col + 1, cnt + 1);
		map[row][col] = 0; 	
	}
	
	wall(row, col + 1, cnt);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	int wallcnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if(map[i][j] == 2) {
				virus.push_back({ i, j });
			}
			if(map[i][j] == 1) {
				wallcnt++;
			}
		}
	}

	wall(0, 0, 0);

	cout << n * m - (wallcnt + 3) - minVirus;
}