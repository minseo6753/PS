#include<iostream>
#include<vector>

using namespace std;

int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector < bool > v(1000001, true);
	
	for (int i = 2; i*i <= 1000000; i++) {

		if (v[i]) {
			int p = i;

			for (int j = 2; j * p <= 1000000; j++) {

				if (v[j * p]) {

					v[j * p] = false;

					
				}
			}
		}
	}

	while (true) {

		int n;
		cin >> n;
		
		if (n == 0) {
			return 0;
		}

		bool t = false;
		int a;
		for (int i = 3; i <= (n / 2); i+=2) {
			if (v[i] && v[n - i]) {
				t = true;
				a = i;
				break;
			}
		}
		if (t) {
			cout << n << " = " << a << " + " << n - a << '\n';
		}
		else {
			cout << "Goldbach's conjecture is wrong." << '\n';
		}

	}
	
}