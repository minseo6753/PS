#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int>v(n);
	
	vector<int>dp(n,1);

	int m = 0;
	for (int i = 0; i < n; i++) {

		cin >> v[i];

		for (int j = 0; j < i; j++) {

			if (v[i] < v[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		m = max(m, dp[i]);
	}

	cout << m;
}