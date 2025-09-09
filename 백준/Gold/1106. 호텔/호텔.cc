#include<iostream>
#include<vector>
using namespace std;
#define MAX_VAL 100001

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c, n;
	cin >> c >> n;

	vector<int>dp(c + 100, MAX_VAL);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int cost, cust;
		cin >> cost >> cust;
		
		for (int j = cust; j < c + 100; j++) {
			if (dp[j - cust] != MAX_VAL)dp[j] = min(dp[j], dp[j - cust]+cost);
		}
	}

	int result = MAX_VAL;
	for (int i = c; i < c + 100; i++) {
		result = min(result, dp[i]);
	}
	cout << result;
}