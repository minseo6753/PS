#include<iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int dp[100001] = { 0 };
	while (n--) {
		int w, v;
		cin >> w >> v;
		for (int j = k; j >= w; j--) {
			if (dp[j] < dp[j - w] + v)dp[j] = dp[j - w] + v;
		}
	}
	cout << dp[k];
}