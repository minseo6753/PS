#include<iostream>
#include<vector>
using namespace std;
#define INF 25000001

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, w;
		cin >> n >> m >> w;

		vector<vector<int>>map(n + 1, vector<int>(n + 1, INF));
		for (int i = 1; i <= n; i++)map[i][i] = 0;

		for (int i = 0; i < m; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			if (map[s][e] < t)continue;
			map[s][e] = t;
			map[e][s] = t;
		}

		for (int i = 0; i < w; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			map[s][e] = -t;
		}

		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
				}
			}
		}

		bool b = false;
		for (int i = 1; i <= n; i++) {
			for (int k = 1; k <= n; k++) {
				if (map[i][k] + map[k][i] < 0) {
					b = true;
					break;
				}
			}
			if (b)break;
		}
		if (b)cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}