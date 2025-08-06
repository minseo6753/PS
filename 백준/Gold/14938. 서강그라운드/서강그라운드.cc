#include<iostream>
#include<vector>
using namespace std;
#define INF 16

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, r;
	cin >> n >> m >> r;

	vector<int>item(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	vector<vector<int>>dist(n+1, vector<int>(n+1, INF));
	for (int i = 1; i <= n; i++)dist[i][i] = 0;
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		dist[a][b] = l;
		dist[b][a] = l;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}

	int maxItem = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= m)sum += item[j];
		}
		maxItem = max(maxItem, sum);
	}

	cout << maxItem;
}