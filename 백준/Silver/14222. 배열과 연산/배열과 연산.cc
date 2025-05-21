#include<iostream>
#include<vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<vector<int>>v(k, vector<int>(51, 0));
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v[a % k][a / k]++;
	}

	int num = 0;
	for (int j = 1; j <= n / k; j++) {
		if (v[0][j] > 0)num += v[0][j] - 1;
		else num--;

		if (num < 0) {
			cout << 0;
			return 0;
		}
	}
	
	for (int i = 1; i <= n % k; i++) {
		num = 0;
		for (int j = 0; j < n / k + 1; j++) {
			if (v[i][j] > 0)num += v[i][j] - 1;
			else num--;

			if (num < 0) {
				cout << 0;
				return 0;
			}
		}
		
	}

	for (int i = n % k + 1; i < k; i++) {
		num = 0;
		for (int j = 0; j < n / k ; j++) {
			if (v[i][j] > 0)num += v[i][j] - 1;
			else num--;

			if (num < 0) {
				cout << 0;
				return 0;
			}
		}
	}
	
	cout << 1;
}