#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 200000001

vector<int>dist(801,INF);

struct cmp {
	bool operator()(int a, int b) {
		return dist[a] > dist[b];
	}
};

void dijk(int sour, vector<vector<int>>& map) {
	fill(dist.begin(), dist.end(), INF);
	priority_queue<int,vector<int>,cmp>pq;
	
	dist[sour] = 0;
	pq.push(sour);
	while (!pq.empty()) {
		int tmp = pq.top();
		pq.pop();
		
			
			for (int i = 1; i < map[tmp].size(); i++) {
				if (dist[i] > dist[tmp] + map[tmp][i]) {
					dist[i] = dist[tmp] + map[tmp][i];
					pq.push(i);
				}
			}
		

	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	int n, e;
	cin >> n >> e;
	vector<vector<int>>map(n+1, vector<int>(n+1, INF));
	for (int i = 1; i <= n; i++) {
		map[i][i] = 0;
	}
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = c;
		map[b][a] = c;
	}
	int v1, v2;
	cin >> v1 >> v2;

	dijk(1, map);
	int stov1 = dist[v1];
	int stov2 = dist[v2];
	dijk(v1, map);
	int v1tod = dist[n];
	int v1tov2 = dist[v2];
	dijk(v2, map);
	int v2tod = dist[n];
	int v2tov1 = dist[v1];
	int sum1 = stov1 + v1tov2 + v2tod;
	int sum2 = stov2 + v2tov1 + v1tod;
	int result = min(sum1, sum2);
	if (result >= INF)cout << -1;
	else cout << result;
}