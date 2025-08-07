#include<iostream>
#include<vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c, t;
	cin >> r >> c >> t;

	int cl1, cl2;

	vector<vector<pair<int,int>>>v(r, vector<pair<int,int>>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> v[i][j].first;
			v[i][j].second = 0;

			if (v[i][j].first == -1)cl2 = i;
		}
	}
	cl1 = cl2 - 1;

	int mov[4] = { 1,-1,0,0 };
	while (t--) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (v[i][j].first > 0) {
					int dust = v[i][j].first / 5;
					for (int k = 0; k < 4; k++) {
						int ti = i + mov[k];
						int tj = j + mov[3 - k];
						if (ti >= 0 && ti < r && tj >= 0 && tj<c && v[ti][tj].first>-1) {
							v[ti][tj].second += dust;
							v[i][j].first -= dust;
						}
					}
				}
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				v[i][j].first += v[i][j].second;
				v[i][j].second = 0;
			}
		}

		for (int i = cl1 - 1; i > 0; i--)v[i][0].first = v[i - 1][0].first;
		for (int i = 0; i < c-1; i++)v[0][i].first = v[0][i + 1].first;
		for (int i = 0; i < cl1; i++)v[i][c - 1].first = v[i + 1][c - 1].first;
		for (int i = c - 1; i > 1; i--)v[cl1][i].first = v[cl1][i - 1].first;
		v[cl1][1].first = 0;

		for (int i = cl2 + 1; i < r-1; i++)v[i][0].first = v[i + 1][0].first;
		for (int i = 0; i < c - 1; i++)v[r - 1][i].first = v[r - 1][i + 1].first;
		for (int i = r - 1; i > cl2; i--)v[i][c - 1].first = v[i - 1][c - 1].first;
		for (int i = c - 1; i > 1; i--)v[cl2][i].first = v[cl2][i - 1].first;
		v[cl2][1].first = 0;
	}

	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			sum += v[i][j].first;
		}
	}
	cout << sum + 2;
}