#include<iostream>
#include<vector>
using namespace std;
#define INF 1e9

bool bellman(vector < vector<pair<int, int>>>& v) {
	vector<int>dist(v.size(), INF);
	for (int i = 0; i < v.size()-1; i++) {
		bool update = false;
		for (int j = 1; j <= v.size()-1; j++) {
			for (int k = 0; k < v[j].size(); k++) {
				if (dist[j] + v[j][k].second < dist[v[j][k].first]) {
					dist[v[j][k].first] = dist[j] + v[j][k].second;
					update = true;
				}
			}
		}
		if (!update)return false;
	}
	return true;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, w;
		cin >> n >> m >> w;

		vector<vector<pair<int,int>>>map(n + 1, vector<pair<int,int>>());

		for (int i = 0; i < m; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			map[s].push_back({ e,t });
			map[e].push_back({ s,t });
		}

		for (int i = 0; i < w; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			map[s].push_back({ e,-t });
		}

		if (bellman(map))cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
}