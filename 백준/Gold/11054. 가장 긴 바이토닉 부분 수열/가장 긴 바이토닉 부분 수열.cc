#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>v(n);
	vector<int>dp(n, 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];

		int maxi = 0;
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				maxi = max(maxi, dp[j]);
			}
		}
		dp[i] = maxi + 1;
	}

	int result = 0;

	vector<int>dp2(n, 1);
	for (int i = n - 1; i >= 0; i--) {
		
		int maxi = 0;
		for (int j = n - 1; j > i; j--) {
			if (v[j] < v[i]) {
				maxi = max(maxi, dp2[j]);
			}
		}
		dp2[i] = maxi + 1;

		result = max(result, dp[i] + dp2[i]);
	}

	cout << result - 1;
}