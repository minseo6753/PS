#include<iostream>
#include<vector>
using namespace std;

void dfs(int n,vector<vector<int>>&v,vector<int>&p) {

	for (int i = 0; i < v[n].size(); i++) {
		if (p[v[n][i]] == 0) {
			p[v[n][i]] = n;
			dfs(v[n][i],v,p);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin >> n;
	
	vector<vector<int>>v(n + 1);
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	vector<int>parent(n + 1,0);
	parent[1] = 1;
	dfs(1, v, parent);
	
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
}