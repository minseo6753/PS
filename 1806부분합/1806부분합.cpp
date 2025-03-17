#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, s;
	cin >> n >> s;

	vector<int>v(n + 1, 0);
	for (int i = 1; i <= n; i++) {

		int a;
		cin >> a;
		v[i] = v[i - 1] + a;

	}

	int i = 1;
	int j = 1;
	int m = 100001;
	while (j <= n && i <= j) {
		if (v[j] - v[i - 1] < s) {
			j++;
		}
		else {
			m = min(m, j - i + 1);
			i++;
		}
	}

	if (m == 100001) {
		cout << 0;
	}
	else {
		cout << m;
	}
}