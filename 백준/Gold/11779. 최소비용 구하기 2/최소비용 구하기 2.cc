#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define INF 100000000

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>>bus(n+1, vector<pair<int, int>>());
	for (int i = 0; i < m; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		bus[s].push_back({ e,c });
	}

	int start, end;
	cin >> start >> end;

	priority_queue<pair<int, int>>pq;
	vector<int>dist(n + 1,INF);
	vector<int>pre(n + 1);
	dist[start] = 0;
	pq.push({ 0,start });
	
	while (!pq.empty()) {
		int town = pq.top().second;
		int distance = pq.top().first;
		pq.pop();

		if (distance > dist[town])continue;

		for (int i = 0; i < bus[town].size(); i++) {
			int next = bus[town][i].first;
			int cost = bus[town][i].second;

			if (dist[town] + cost < dist[next]) {
				dist[next] = dist[town] + cost;
				pq.push({ dist[next],next });
				pre[next] = town;
			}
		}
	}

	cout << dist[end] << '\n';
	
	stack<int>s;
	int town = end;
	while (town != start) {
		s.push(town);
		town = pre[town];
	}
	s.push(start);
	cout << s.size() << '\n';
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}