#include<iostream>
#include<vector>
using namespace std;

const int INF = 5000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<int>>v(n + 1, vector<int>(n + 1, INF));

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;

		v[a][a] = 0;
		v[b][b] = 0;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (v[i][k] + v[k][j] < v[i][j])v[i][j] = v[i][k] + v[k][j];
			}
		}
	}

	int min = INF;
	int num;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += v[i][j];
		}
		if (sum < min) {
			min = sum;
			num = i;
		}
	}
	cout << num;
}