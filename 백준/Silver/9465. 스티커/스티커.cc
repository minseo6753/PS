#include<iostream>
#include<vector>

using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>>v(3, vector<int>(n, 0));

		for (int i = 0; i < n; i++) {
			cin >> v[0][i];
		}
		for (int i = 0; i < n; i++) {
			cin >> v[1][i];
		}

		for (int i = 1; i < n; i++) {
			v[0][i] += (v[1][i - 1] > v[2][i - 1]) ? v[1][i - 1] : v[2][i - 1];
			v[1][i] += (v[0][i - 1] > v[2][i - 1]) ? v[0][i - 1] : v[2][i - 1];
			v[2][i] += (v[0][i - 1] > v[1][i - 1]) ? v[0][i - 1] : v[1][i - 1];
		}
		
		cout << max(max(v[0][n - 1], v[1][n - 1]), v[2][n - 1]) << '\n';
	}
}