#include<iostream>
#include<vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>>v(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int a;
			cin >> a;
			v[i].push_back(a);

			if (i != 0) {
				if (j == 0) v[i][j] += v[i - 1][j];
				else if (j == i)v[i][j] += v[i - 1][j - 1];
				else if (v[i - 1][j - 1] > v[i - 1][j]) v[i][j] += v[i - 1][j - 1];
				else v[i][j] += v[i - 1][j];
			}

		}
	}

	int result = 0;
	for (int i = 0; i < v[n - 1].size(); i++) {
		if (result < v[n - 1][i])result = v[n - 1][i];
	}

	cout << result;
}