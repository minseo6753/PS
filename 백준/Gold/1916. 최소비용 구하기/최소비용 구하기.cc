#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 100000000

struct bus {
	int dest;
	int cost;
};


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

	cin >> src >> dest;

	vector<int>dist(n + 1, INF);

	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({ 0,src });
	dist[src] = 0;

	while (true) {
		int node = pq.top().second;
		int di = pq.top().first;
		pq.pop();
		
		if (node == dest) {
			cout << dist[dest];
			break;
		}

		if (di > dist[node]) {
			continue;
		}

		for (int i = 0; i < map[node].size(); i++) {
			int tmpdst = map[node][i].dest;
			if (dist[tmpdst] > dist[node] + map[node][i].cost) {
				dist[tmpdst] = dist[node] + map[node][i].cost;
				pq.push({ dist[tmpdst],tmpdst });
			}
		}
		
		

	}

}