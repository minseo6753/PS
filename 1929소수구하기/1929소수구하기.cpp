#include<iostream>
#include<vector>

using namespace std;

int main() {

	int m, n;
	cin >> m >> n;
	
	vector<bool>v(n + 1, true);
	v[1] = false;

	for (int i = 2; i*i <= n; i++) {

		if (v[i]) {
			
			for (int j = 2; j * i <= n; j++) {
				v[j * i] = false;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (v[i]) {
			cout << i << '\n';
		}
	}
}