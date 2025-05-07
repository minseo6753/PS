#include<iostream>
#include<vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<bool>>adj(n, vector<bool>(n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			bool b;
			cin >> b;
			adj[i][j] = b;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << adj[i][j] << ' ';
		}
		cout << '\n';
	}
}