#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int>l(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> l[i];
	}
	vector<int>j(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> j[i];
	}

	vector<vector<int>>dp(100, vector<int>(n+1, 0));
	for (int w = 0; w < 100; w++) {
		for (int k = 1; k <= n; k++) {
			if (l[k] > w) {
				dp[w][k] = dp[w][k - 1];
			}
			else {
				dp[w][k] = max(dp[w][k - 1], dp[w - l[k]][k - 1] + j[k]);
			}
		}
	}
	cout << dp[99][n];
}