#include<iostream>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int x[10000];
	int y[10000];
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	long long sum1 = 0;
	long long sum2 = 0;
	for (int i = 0; i < n-1; i++) {
		sum1 += (long long)x[i] * y[i + 1];
		sum2 += (long long)x[i + 1] * y[i];
	}
	sum1 += (long long)x[n - 1] * y[0];
	sum2 += (long long)x[0] * y[n - 1];

	cout << fixed;
	cout.precision(1);

	if (sum1 > sum2) cout << double(sum1 - sum2) / 2;
	else cout << double(sum2 - sum1) / 2;
}