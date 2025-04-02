#include<iostream>
using namespace std;

int memo[40] = {};

int fib(int n) {
	if (n == 0)return 0;
	if (n == 1)return 1;
	if (memo[n])return memo[n];
	memo[n] = fib(n - 2) + fib(n - 1);
	return memo[n];
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		if (n == 0)cout << 1 << ' ' << 0;
		else if (n == 1)cout << 0 << ' ' << 1;
		else cout << fib(n - 1) << ' ' << fib(n);
		cout << '\n';
	}
}