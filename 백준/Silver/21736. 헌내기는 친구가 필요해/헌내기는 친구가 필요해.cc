#include<iostream>	
#include<vector>
#include<queue>
using namespace std;

vector<vector<char>>map(600, vector<char>(600));
vector<vector<bool>>visit(600, vector<bool>(600, 0));
queue<pair<int, int>>q;
int arr[4] = { 1,-1,0,0 };
int n, m;
int cnt = 0;

void bfs() {

	while (q.size()) {

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int tx = x + arr[i];
			int ty = y + arr[3 - i];

			if (tx >= 0 && tx < m && ty >= 0 && ty < n && !visit[ty][tx]) {
				if (map[ty][tx] == 'O') {
					q.push(make_pair(tx, ty));
				}
				else if (map[ty][tx] == 'P') {
					q.push(make_pair(tx, ty));
					cnt++;
				}
				visit[ty][tx] = 1;
			}
		}
	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'I') {
				x = j;
				y = i;
			}
		}
	}
	
	q.push(make_pair(x, y));
	bfs();
	
	if (cnt == 0)cout << "TT";
	else cout << cnt;
}