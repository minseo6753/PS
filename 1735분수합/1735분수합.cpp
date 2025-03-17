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

	int nu1, deno1, nu2, deno2;
	cin >> nu1 >> deno1 >> nu2 >> deno2;

	int nu, deno;
	nu = nu1 * deno2 + nu2 * deno1;
	deno = deno1 * deno2;

	int i = GCD(nu, deno);
	nu /= i;
	deno /= i;

	cout << nu << ' ' << deno;
}