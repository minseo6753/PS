#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int>v(n);
	for (int i = 0; i < n; i++) {

		cin >> v[i];
	}
	sort(v.begin(), v.end());
	
	int i = 0;
	int j = n - 1;
	int m = 2000000000;
	int a, b;
	while (i < j) {

		int sol = v[i] + v[j];

		if (sol == 0) {
			a = v[i];
			b = v[j];
			break;
		}

		if (abs(sol) < m) {
			m = abs(sol);
			a = v[i];
			b = v[j];
		}

		if (sol < 0) {
			i++;
		}
		else {
			j--;
		}
	}
	cout << a << ' ' << b;
}