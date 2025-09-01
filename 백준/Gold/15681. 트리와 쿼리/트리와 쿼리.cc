#include<iostream>
#include<vector>
using namespace std;

vector<int>tree[100001];
int subtree[100001] = { 0 };
bool visit[100001] = { 0 };

int count(int root) {
	visit[root] = true;

	int sum = 0;
	for (int i = 0; i < tree[root].size(); i++) {
		int child = tree[root][i];
		if (!visit[child]) {
			sum += count(child);
		}
	}
	subtree[root] = sum + 1;
	return sum + 1;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, r, q;
	cin >> n >> r >> q;

	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	count(r);

	for (int i = 0; i < q; i++) {
		int u;
		cin >> u;
		cout << subtree[u] << '\n';
	}
}