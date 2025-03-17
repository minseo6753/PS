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

	int m = 0;
	while (next_permutation(v.begin(), v.end())) {

		int s = 0;
		for (int i = 0; i < n - 1; i++) {
			s += abs(v[i] - v[i + 1]);
		}
		m = max(m, s);
	}

	cout << m;
}