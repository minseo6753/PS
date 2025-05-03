#include<iostream>
using namespace std;

int gcd(int m, int n) {
	int r;
	do {
		r = m % n;
		m = n;
		n = r;
	} while (r);
	return m;
}

int lcm(int m, int n) {
	return (m * n) / gcd(m, n);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;

		if (y == n)y = 0;

		int tmp;
		bool b = false;
		int l = lcm(m, n);
		for (int i = 0; i < l/m; i++) {
			tmp = i * m + x;
			if (tmp % n == y) {
				b = true;
				break;
			}
		}
		if (b) {
			cout << tmp << '\n';
		}
		else cout << -1 << '\n';
	}


}