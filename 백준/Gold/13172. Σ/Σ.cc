#include<iostream>
using namespace std;
#define X 1000000007

int fastPow(int base, int exp, int mod) {

	long long result = 1;
	while (exp) {
		if (exp & 1)result = result * base % mod;
		base = (long long)base * base % mod;
		exp >>= 1;
	}
	return result;
}

int main() {
	int m;
	cin >> m;

	int sum = 0;
	for (int i = 0; i < m; i++) {
		int n, s;
		cin >> n >> s;


		int inverse = fastPow(n, X - 2, X);
		sum += (long long)s * inverse % X;
		
		sum %= X;
	}
	cout << sum;
}