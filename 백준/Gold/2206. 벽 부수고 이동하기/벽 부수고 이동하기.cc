#include<iostream>
#include<memory.h>
#include<queue>

using namespace std;

int map[1000][1000];
int n, m;

struct s {
	int row;
	int col;
	bool brk;
};

int mov[4] = { 1,-1,0,0 };
bool visit[1000][1000][2];
int bfs() {

	queue<s>q;
	q.push({ 0,0,false });
	visit[0][0][0] = true;
	visit[0][0][1] = true;

	int step = 1;
	while (!q.empty()) {

		int loop = q.size();
		while (loop--) {
			int row = q.front().row;
			int col = q.front().col;
			bool brk = q.front().brk;
			q.pop();

			if (row == n - 1 && col == m - 1)return step;
		
			for (int i = 0; i < 4; i++) {
				int tr = row + mov[i];
				int tc = col + mov[3 - i];
				if (tr < 0 || tr >= n || tc < 0 || tc >= m)continue;

				if (brk) {
					if (map[tr][tc] == 0&&!visit[tr][tc][1]) {
						q.push({ tr,tc,brk });
						visit[tr][tc][1] = true;
					}
				}
				else {
					if (!visit[tr][tc][0]) {
						if (map[tr][tc] == 0)q.push({ tr,tc,brk });
						else q.push({ tr,tc,true });
						visit[tr][tc][0] = true;
					}
				}
			}
		}
		step++;
	}
	return -1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < m; j++) {
			map[i][j] = a[j]-48;
		}
	}

	memset(visit, 0, sizeof(visit));

	cout<< bfs();
	
}