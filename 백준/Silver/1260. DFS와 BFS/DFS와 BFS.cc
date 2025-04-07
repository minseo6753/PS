#include<iostream>
#include<queue>
#include<memory.h>

using namespace std;

int n, m, v;
bool map[1001][1001] = {};
bool visit[1001] = {};

void DFS(int i) {
	cout << i << ' ';
	visit[i] = 1;
	
	for (int j = 1; j <= n; j++) {
		if (map[i][j] && !visit[j]) {
			DFS(j);
		}
	}

}

queue<int>q;

void BFS() {

	while (q.size()) {

		int i = q.front();
		q.pop();
		cout << i << ' ';

		for (int j = 1; j <= n; j++) {
			if (map[i][j] && !visit[j]) {
				q.push(j);
				visit[j] = 1;
			}
		}

	}

}

int main() {
	
	cin >> n >> m >> v;
	
	while(m--) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	DFS(v);
	cout << '\n';
	memset(visit, 0, sizeof(visit));
	q.push(v);
	visit[v] = 1;
	BFS();
}