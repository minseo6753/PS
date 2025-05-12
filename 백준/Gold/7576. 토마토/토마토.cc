#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int bfs(vector<vector<int>>& v, int n, int m, queue<vector<int>>& q, int zero) {

	int mov[4] = { 1,-1,0,0 };

	int day;
	while (!q.empty()) {
		int i = q.front()[0];
		int j = q.front()[1];
		day = q.front()[2];
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ti = i + mov[k];
			int tj = j + mov[3 - k];
			if (ti >= 0 && ti < n && tj >= 0 && tj < m && v[ti][tj] == 0) {
				q.push({ ti,tj,day + 1 });
				v[ti][tj] = 1;
				zero--;
			}
		}
	}

	if (zero > 0)return -1;
	else return day;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;

	vector<vector<int>>v(n, vector<int>(m));
	queue<vector<int>>q;
	int zero = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			v[i][j] = a;
			if (a == 1)q.push({ i,j,0 });
			if (a == 0)zero++;
		}
	}

	if (zero == 0) cout << 0;
	else cout << bfs(v, n, m, q, zero);
}