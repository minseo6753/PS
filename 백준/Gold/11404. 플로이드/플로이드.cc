#include<iostream>
#include<vector>
using namespace std;
#define INF 10000001

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>>v(n + 1, vector<int>(n + 1, INF));
	for(int i=1; i<=n; i++) {
		v[i][i] = 0; 
	}

	for(int i=0;i<m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (v[a][b] > c) {
			v[a][b] = c;
		}
	}
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if (v[i][j] > v[i][k] + v[k][j]) {
					v[i][j] = v[i][k] + v[k][j];
				}
			}
		}
	}

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if (v[i][j] == INF) {
				cout << 0;
			} else {
				cout << v[i][j];
			}
			cout << ' ';
		}
		cout << '\n';
	}
}