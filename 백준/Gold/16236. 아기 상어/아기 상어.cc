#include<iostream>
#include<queue>
using namespace std;

int n;
int map[20][20];

int rm[4] = { -1,0,0,1 };
int cm[4] = { 0,-1,1,0 };

int bfs(int &row,int &col, int &size, int &cnt) {
	priority_queue<pair<int,pair<int, int>>>q;
	q.push({ 0,{-row,-col} });
	bool visit[20][20] = { 0 };
	visit[row][col] = true;

	while (!q.empty()) {
		int loop = q.size();
		while (loop--) {
			int time = -q.top().first;
			int r = -q.top().second.first;
			int c = -q.top().second.second;
			q.pop();

			if (map[r][c] != 0 && map[r][c] < size) {
				map[r][c] = 0;
				cnt++;
				row = r;
				col = c;
				if (cnt == size) {
					size++;
					cnt = 0;
				}
				return time;
			}

			for (int i = 0; i < 4; i++) {
				int tr = r + rm[i];
				int tc = c + cm[i];

				if (tr < 0 || tr >= n || tc < 0 || tc >= n)continue;
				if (visit[tr][tc])continue;

				if (map[tr][tc] <= size) {
					q.push({ -(time + 1),{-tr,-tc} });
					visit[tr][tc] = true;
				}
			}
		}
	}
	return 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int row, col;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				row = i;
				col = j;
				map[i][j] = 0;
			}
		}
	}

	int size = 2;
	int cnt = 0;
	int sum = 0;
	while (true) {
		int time = bfs(row, col,size,cnt);
		if (time > 0)sum += time;
		else break;
	}
	cout << sum;
}