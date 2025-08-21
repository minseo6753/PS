#include<iostream>
using namespace std;

int fib(int n) {
	if (n == 0)return 0;
	if (n == 1)return 1;
	
	int a = 0;
	int b = 1;
	for (int i = 2; i <= n; i++) {
		int tmp = b;
		b = (a + b)%1000000;
		a = tmp;
	}

	return b;
}

int main() {
	long long n;
	cin >> n;
	cout << fib(n % 1500000);
}