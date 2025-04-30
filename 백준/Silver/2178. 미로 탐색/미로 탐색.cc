#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int bfs(int n, int m, string* arr) {
	int step = 0;
	queue<pair<int, int>>q;
	q.push(make_pair(0, 0));
	vector<vector<bool>>visit(n, vector<bool>(m, 0));
	visit[0][0] = 1;
	int num = 1;
	int move[4] = { 1,-1,0,0 };
	int x = 0;
	int y = 0;
	while (x != n - 1 || y != m - 1) {
		step++;
		int cnt = 0;
		for (int i = 0; i < num; i++) {
			x = q.front().first;
			y = q.front().second;
			if (x == n - 1 && y == m - 1)break;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int tx = x + move[j];
				int ty = y + move[3 - j];
				
				if (tx >= 0 && tx < n && ty >= 0 && ty < m && !visit[tx][ty]&&arr[tx][ty]=='1') {
					q.push(make_pair(tx, ty));
					cnt++;
					visit[tx][ty] = 1;
				}
			}
			
		}
		num = cnt;
	}
	return step;
}

int main() {
	int n, m;
	cin >> n >> m;
	string* arr = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << bfs(n, m, arr);
	
}