#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<vector<int>>dp(n+1, vector<int>(10,1));
	dp[1][0] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
		for (int j = 1; j < 9; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}
	
	int s = 0;
	for (int i = 0; i < 10; i++) {
		s += dp[n][i];
		s %= 1000000000;
	}
	cout << s;
}