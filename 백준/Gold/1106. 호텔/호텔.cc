#include<iostream>	
#include<vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c, n;
	cin >> c >> n;

	vector<int>dp(c*100+1,0);

	for (int i = 0; i < n; i++) {
		int cost, cust;
		cin >> cost >> cust;
		for (int j = cost; j <= c*100; j++) {
			dp[j] = max(dp[j], dp[j - cost] + cust);
		}
	}
	
	cout << lower_bound(dp.begin(), dp.end(), c) - dp.begin();
}