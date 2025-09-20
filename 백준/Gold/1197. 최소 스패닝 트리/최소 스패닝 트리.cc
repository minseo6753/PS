#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
	int weight;
	int v;

	bool operator<(const Edge e)const {
		return weight > e.weight;
	}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e;
	cin >> v >> e;
	
	vector<vector<Edge>>tree(v + 1);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a].push_back({ c,b });
		tree[b].push_back({ c,a });
	}

	priority_queue<Edge>pq;
	vector<bool>included(v + 1, false);
	int sum = 0;

	for (int i = 0; i < tree[1].size(); i++)pq.push(tree[1][i]);
	included[1] = true;

	int cnt = 1;
	while (cnt<v) {
		int weight = pq.top().weight;
		int v = pq.top().v;
		pq.pop();

		if (included[v])continue;

		sum += weight;
		included[v] = true;
		cnt++;

		for (int i = 0; i < tree[v].size(); i++) {
			pq.push(tree[v][i]);
		}
	}

	cout << sum;
}