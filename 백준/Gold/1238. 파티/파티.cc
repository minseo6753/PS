#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1000001

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

	vector<int>dist(n + 1, INF);
	priority_queue<pair<int, int>>pq;
	dist[x] = 0;
	pq.push({ 0,x });
	while (!pq.empty()) {
		int time = -pq.top().first;
		int town = pq.top().second;
		pq.pop();
		
		if (time > dist[town])continue;

		for (int i = 0; i < road[town].size(); i++) {
			int next_town = road[town][i].first;
			int duration = road[town][i].second;
			if (dist[town] + duration < dist[next_town]) {
				dist[next_town] = dist[town] + duration;
				pq.push({ -dist[next_town],next_town});
			}
		}
	}

	vector<int>revdist(n + 1, INF);
	revdist[x] = 0;
	pq.push({ 0,x });
	while (!pq.empty()) {
		int time = -pq.top().first;
		int town = pq.top().second;
		pq.pop();
		
		if (time > revdist[town])continue;

		for (int i = 0; i < reverse[town].size(); i++) {
			int next_town = reverse[town][i].first;
			int duration = reverse[town][i].second;
			if (revdist[town] + duration < revdist[next_town]) {
				revdist[next_town] = revdist[town] + duration;
				pq.push({ -revdist[next_town],next_town});
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		result = max(result, dist[i] + revdist[i]);
	}
	cout << result;
}