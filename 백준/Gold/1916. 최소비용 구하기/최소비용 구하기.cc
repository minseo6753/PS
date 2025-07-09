#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 100000000

struct bus {
	int dest;
	int cost;
};

bool compare(bus a, bus b) {
	return a.cost < b.cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int src, dest;
	vector<vector<bus>>map(n+1);
	for (int i = 0; i < m; i++) {
		int cost;
		cin >> src >> dest >> cost;
		if(src!=dest) map[src].push_back({ dest,cost });
	}

	for (int i = 0; i < map.size(); i++) {
		sort(map[i].begin(), map[i].end(),compare);
	}

	cin >> src >> dest;

	vector<int>dist(n + 1, INF);
	vector<bool>visit(n + 1, 0);
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({ 0,src });
	dist[src] = 0;
	visit[src] = true;
	while (true) {
		int node = pq.top().second;
		pq.pop();
		
		if (node == dest) {
			cout << dist[dest];
			break;
		}

		
		visit[node] = true;
		for (int i = 0; i < map[node].size(); i++) {
			int tmpdst = map[node][i].dest;
			if (!visit[tmpdst]&&dist[tmpdst] > dist[node] + map[node][i].cost) {
				dist[tmpdst] = dist[node] + map[node][i].cost;
				pq.push({ dist[tmpdst],tmpdst });
			}
		}
		
		

	}

}