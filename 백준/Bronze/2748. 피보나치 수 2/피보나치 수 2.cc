#include<iostream>
using namespace std;

long long memo[91] = { 0 };

long long fib(int n) {
	if (n == 0)return 0;
	if (n == 1)return 1;
	if (memo[n])return memo[n];

	memo[n] = fib(n - 1) + fib(n - 2);
	return memo[n];
}

int main() {
	int n;
	cin >> n;

	cout << fib(n);
}