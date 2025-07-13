#include<iostream>
#include<memory.h>
using namespace std;

int dp[101][100001];

struct obj {
	int weight;
	int value;
};

obj li[101];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, 0, sizeof(dp));

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> li[i].weight >> li[i].value;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (li[i].weight <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - li[i].weight] + li[i].value);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];
}