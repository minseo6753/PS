#include<iostream>
#include<cmath>
using namespace std;

long long GCD(long long a, long long b) {
	long long m, n;

	if (a > b) {
		m = a;
		n = b;
	}
	else {
		m = b;
		n = a;
	}

	while (n > 0) {
		long long r = m % n;
		m = n;
		n = r;
	}
	return m;
}

int main() {
	long long g, l;
	cin >> g >> l;

	long long a, b;
	for (long long i = g; i <= sqrt(g * l); i += g) {
		if ((g * l) % i == 0) {
			long long j = (g * l) / i;
			if (j % g == 0 && GCD(j / g, i / g) == 1) {
				a = i;
				b = j;
			}
		}
	}
	cout << a << ' ' << b;
}