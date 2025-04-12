#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int n, m;
	cin >> n >> m;
	vector<int>* adj = new vector<int>[n+1];
	int u, v;
	while (m--) {
		
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool>visit(n+1,0);
	queue<int>q;
	int cnt = 0;
	
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			cnt++;
			q.push(i);
			visit[i] = 1;

			while (q.size()) {
				int node = q.front();
				q.pop();
				for (int j = 0; j < adj[node].size(); j++) {
					if (!visit[adj[node][j]]) {
						q.push(adj[node][j]);
						visit[adj[node][j]] = 1;
					}
				}
			}
			
		}
	}
	
	cout << cnt;

}