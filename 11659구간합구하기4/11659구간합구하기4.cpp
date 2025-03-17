#include<iostream>
#include<vector>

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int>v(n + 1, 0);

	for (int i = 1; i <= n; i++) {

		int a;
		cin >> a;
		v[i] = v[i - 1] + a;

	}

	for (int k = 0; k < m; k++) {

		int i, j;
		cin >> i >> j;
		cout << v[j] - v[i - 1]<<'\n';
	}
}