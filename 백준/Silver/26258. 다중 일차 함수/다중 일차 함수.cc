#include<iostream>
#include<vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>>v(n,vector<int>(3));
	int px, py;
	cin >> px >> py;
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		v[i][0] = px;
		v[i][1] = x;
		if (py == y)v[i][2] = 0;
		else if (py < y)v[i][2] = 1;
		else v[i][2] = -1;

		px = x;
		py = y;
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		double k;
		cin >> k;

		int st = 0;
		int end = n - 1;
		while (st <= end) {
			int mid = (st + end) / 2;
			if (k >= v[mid][0] && k <= v[mid][1]) {
				cout << v[mid][2] << '\n';
				break;
			}
			else if (k < v[mid][0]) {
				end = mid - 1;
			}
			else st = mid + 1;
		}
	}
}