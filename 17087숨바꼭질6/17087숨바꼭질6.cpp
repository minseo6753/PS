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

	int n, s;
	cin >> n >> s;

	int d;
	cin >> d;
	d = abs(s - d);
	for (int i = 0; i < n-1; i++) {
		
		int a;
		cin >> a;
		d = GCD(d, abs(s - a));
	}

	cout << d;
}