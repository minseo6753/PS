#include<iostream>
using namespace std;

long long memo[101] = {};

long long p(int n) {
	if (n == 1 || n == 2 || n == 3)return 1;
	if (n == 4 || n == 5)return 2;
	if (memo[n])return memo[n];
	memo[n] = p(n-1) + p(n - 5);
	return memo[n];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << p(n) << '\n';
	}
}