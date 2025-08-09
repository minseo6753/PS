#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1000001

vector<int> dijk(vector<vector<pair<int, int>>>& v, int src) {

	vector<int>dist(v.size(), INF);
	priority_queue<pair<int, int>>pq;
	dist[src] = 0;
	pq.push({ 0,src });
	while (!pq.empty()) {
		int time = -pq.top().first;
		int town = pq.top().second;
		pq.pop();

		if (time > dist[town])continue;

		for (int i = 0; i < v[town].size(); i++) {
			int next_town = v[town][i].first;
			int duration = v[town][i].second;
			if (dist[town] + duration < dist[next_town]) {
				dist[next_town] = dist[town] + duration;
				pq.push({ -dist[next_town],next_town });
			}
		}
	}

	return dist;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x;
	cin >> n >> m >> x;

	vector<vector<pair<int,int>>>road(n+1, vector<pair<int,int>>());
	vector<vector<pair<int,int>>>reverse(n+1, vector<pair<int,int>>());
	for (int i = 0; i < m; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		road[s].push_back({ e,t });
		reverse[e].push_back({ s,t });
	}

	vector<int>dist = dijk(road, x);
	vector<int>revdist = dijk(reverse, x);

	int result = 0;
	for (int i = 1; i <= n; i++) {
		result = max(result, dist[i] + revdist[i]);
	}
	cout << result;
}