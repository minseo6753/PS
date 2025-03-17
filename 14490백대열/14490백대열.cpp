#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int GCD(int a, int b) {
	int m, n;
	if (a < b) {
		m = b;
		n = a;
	}
	else {
		m = a;
		n = b;
	}

	int r;
	do {
		r = m % n;
		m = n;
		n = r;
	} while (r > 0);

	return m;
}

int main() {

	int n, m;
	scanf("%d:%d", &n, &m);
	
	int i = GCD(n, m);
	cout << n / i << ':' << m / i;
	
}