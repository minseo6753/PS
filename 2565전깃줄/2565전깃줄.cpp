#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<pair<int,int>>v(n);
	
	for (int i = 0; i < n; i++) {

		cin >> v[i].first >> v[i].second;

	}

	sort(v.begin(), v.end());

	vector<int>dp(n,1);
	int m = 0;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < i; j++) {

			if (v[i].second > v[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		m = max(m, dp[i]);
	}
	cout << n - m;
}