#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 200001

struct Way {
	int node;
	int distance;
};

struct cmp {
	bool operator()(Way a, Way b) {
		return a.distance > b.distance;
	}
};

vector<int> dijk(vector<vector<Way>>& graph, int start, int n) {
	priority_queue<Way,vector<Way>,cmp>pq;
	vector<int>dist(n+1, INF);
	dist[start] = 0;
	pq.push({ start,0 });
	while (!pq.empty()) {
		int node = pq.top().node;
		int distance = pq.top().distance;
		pq.pop();

		if (distance > dist[node])continue;

		for (int i = 0; i < graph[node].size(); i++) {
			int neighbor = graph[node][i].node;
			if (dist[node] + graph[node][i].distance < dist[neighbor]) {
				dist[neighbor] = dist[node] + graph[node][i].distance;
				pq.push({ neighbor,dist[neighbor] });
			}
		}
	}
	return dist;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, e;
	cin >> n >> e;
	int k;
	cin >> k;
	vector<vector<Way>>graph(n + 1);
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	vector<int>dist = dijk(graph, k, n);
	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF)cout << "INF";
		else cout << dist[i];
		cout << '\n';
	}
}