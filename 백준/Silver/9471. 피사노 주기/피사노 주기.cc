#include<iostream>
using namespace std;

int pisano(int m) {

	int a = 0;
	int b = 1;
	int period = 1;
	while(true) {
		int tmp = b;
		b = (a + b) % m;
		a = tmp;

		if (a == 0 && b == 1)return period;
		
		period++;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int p;
	cin >> p;
	while (p--) {
		int n, m;
		cin >> n >> m;
		cout << n << ' ' << pisano(m) << '\n';
	}
}